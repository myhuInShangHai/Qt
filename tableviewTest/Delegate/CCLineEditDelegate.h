#ifndef CCLINEEDITDELEGATE_H
#define CCLINEEDITDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QLineEdit>

class CCLineEditDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    CCLineEditDelegate(QObject *parent = 0);
    QWidget *createEditor(QWidget *parent,  const QStyleOptionViewItem &option,
                          const  QModelIndex &index)  const;
    void  setEditorData(QWidget *editor,  const  QModelIndex &index)  const;

    void  setModelData(QWidget *editor, QAbstractItemModel *model,
                       const  QModelIndex &index)  const;

    void  updateEditorGeometry(QWidget *editor,
                               const  QStyleOptionViewItem &option,  const  QModelIndex &index) const;
};

#endif // CCLINEEDITDELEGATE_H
