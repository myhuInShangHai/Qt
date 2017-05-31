#include "CPixBtnDelegate.h"
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QStyleOptionButton>
#include <QPalette>
#include <QColor>
#include <QApplication>
#include <QMouseEvent>

CPixBtnDelegate::CPixBtnDelegate(QObject *parent) :
    QItemDelegate(parent)
{
    m_pBtns = new QMap<QModelIndex, QStyleOptionButton *>();
    pixPath = QString("");
}

CPixBtnDelegate::~CPixBtnDelegate()
{
    foreach (QStyleOptionButton *pBtn, m_pBtns->values()) {
        if (NULL != pBtn) {
            delete pBtn;
            pBtn = NULL;
        }
    }
    m_pBtns->clear();
    if (NULL != m_pBtns) {
        delete m_pBtns;
        m_pBtns = NULL;
    }
}

void CPixBtnDelegate::setPixPath(const QString &path)
{
    pixPath = path;
}

void CPixBtnDelegate::paint(QPainter *painter,const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    QStyleOptionButton * pBtn = m_pBtns->value(index);
    if (NULL == pBtn) {
        pBtn = new QStyleOptionButton();
        pBtn->state |= QStyle::State_Enabled;
        (const_cast<CPixBtnDelegate *>(this))->m_pBtns->insert(index, pBtn);
    }
    int dx1 = 46; int dy1 = 4;
    int dx2 = 30-(option.rect.width()/2 + 16); int dy2 = -4;
    pBtn->rect = option.rect.adjusted(dx1, dy1, dx2, dy2); //设置按钮的大小

    const QPixmap &pixmap = QPixmap(pixPath);
    int width=pixmap.width();
    int height=pixmap.height();
    int x=pBtn->rect.x()+pBtn->rect.width()/2-width/2;
    int y=pBtn->rect.y()+pBtn->rect.height()/2-height/2;

    painter->save();
    if (option.state & QStyle::State_Selected) {
        painter->fillRect(option.rect, option.palette.light());
    }
    painter->drawPixmap(x,y,pixmap);  //设置按钮的背景图片
    painter->restore();
    QApplication::style()->drawControl(QStyle::CE_PushButtonLabel, pBtn, painter);

}

bool CPixBtnDelegate::editorEvent(QEvent *event,QAbstractItemModel *model,
                                   const QStyleOptionViewItem &option,const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent * ev = static_cast<QMouseEvent*>(event);
        if (m_pBtns->contains(index)) {
            QStyleOptionButton * pBtn = m_pBtns->value(index);
            if (pBtn->rect.contains(ev->x(), ev->y())) {
                pBtn->state |= QStyle::State_Sunken;
            }
        }
    }
    if (event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent * ev = static_cast<QMouseEvent*>(event);
        if (m_pBtns->contains(index)) {
            QStyleOptionButton * pBtn = m_pBtns->value(index);
            if (pBtn->rect.contains(ev->x(), ev->y())) {
                pBtn->state &= (~QStyle::State_Sunken);
                emit sig_buttonClicked(index);
            }
        }
    }
    return QItemDelegate::editorEvent(event, model, option, index);
}
