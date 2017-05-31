#ifndef CPixBtnDelegate_H
#define CPixBtnDelegate_H

#include <QItemDelegate>
#include <QPixmap>

class CPixBtnDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit CPixBtnDelegate(QObject *parent=0);
    virtual ~CPixBtnDelegate();

    void setPixPath(const QString &path);

    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const;

    bool editorEvent(QEvent *event,
                     QAbstractItemModel *model,
                     const QStyleOptionViewItem &option,
                     const QModelIndex &index);

signals:
    void sig_buttonClicked(const QModelIndex &index);

public slots:

private:
    QMap<QModelIndex, QStyleOptionButton *> * m_pBtns; //行 - 按钮
    QString pixPath;  //图片路径
};

#endif // CPixBtnDelegate_H
