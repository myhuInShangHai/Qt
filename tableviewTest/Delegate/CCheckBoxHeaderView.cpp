#include "CCheckBoxHeaderView.h"

CCheckBoxHeaderView::CCheckBoxHeaderView(int checkBoxColumnId, Qt::Orientation orientation, QWidget * parent)
    : QHeaderView(orientation, parent)
{
    m_checkBoxColumnId = checkBoxColumnId;
    m_checkBoxIsOn = false;
}

CCheckBoxHeaderView::~CCheckBoxHeaderView()
{

}

void CCheckBoxHeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    painter->save();
    QHeaderView::paintSection(painter, rect, logicalIndex);
    painter->restore();
    if (logicalIndex == m_checkBoxColumnId)
    {
        QStyleOptionButton option;
        int width = 3;
        for (int i=0; i<logicalIndex; ++i)
            width += sectionSize( i );
        option.rect = QRect(width, 5, 15, 15);
        if (m_checkBoxIsOn)
            option.state = QStyle::State_On;
        else
            option.state = QStyle::State_Off;
        this->style()->drawControl(QStyle::CE_CheckBox, &option, painter);
    }
}

void CCheckBoxHeaderView::mousePressEvent(QMouseEvent *event)
{
    if (visualIndexAt(event->pos().x()) == m_checkBoxColumnId)
    {
        if (m_checkBoxIsOn)
            m_checkBoxIsOn = false;
        else
            m_checkBoxIsOn = true;
        this->updateSection(m_checkBoxColumnId);
        emit sig_AllChecked(m_checkBoxIsOn);
    }

    QHeaderView::mousePressEvent(event);
}
