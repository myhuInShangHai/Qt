#ifndef CPROCESSDELEGATE_H
#define CPROCESSDELEGATE_H

#include <QObject>
#include <QItemDelegate>

class CProcessDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit CProcessDelegate(QObject *parent = 0);
    virtual ~ CProcessDelegate();
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    QWidget *createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const;
    void setEditorData( QWidget *editor, const QModelIndex &index ) const;
    void setModelData( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const;
    void updateEditorGeometry( QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index ) const;

signals:

public slots:

};


//--------------//
class CProcess2Delegate: public QItemDelegate
{
    Q_OBJECT
public:
    explicit CProcess2Delegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};
#endif // CPROCESSDELEGATE_H
