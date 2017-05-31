#include "CCLineEditDelegate.h"

CCLineEditDelegate::CCLineEditDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QWidget* CCLineEditDelegate::createEditor(QWidget *parent,  const QStyleOptionViewItem &option,
                                         const  QModelIndex &index)  const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QLineEdit *editor =  new  QLineEdit(parent);
    editor->resize(parent->width()*0.6, parent->height());
    editor->setAlignment(Qt::AlignCenter);
    QRegExp regExp( "[0-9]{0,10}" );
    editor->setValidator( new  QRegExpValidator(regExp, parent));
    return  editor;
}

void  CCLineEditDelegate::setEditorData(QWidget *editor,  const  QModelIndex &index)  const
{
    QString text = index.model()->data(index, Qt::EditRole).toString();
    QLineEdit *lineEdit =  static_cast <QLineEdit*>(editor);
    lineEdit->setText(text);
}

void  CCLineEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                      const  QModelIndex &index)  const
{
    QLineEdit *lineEdit =  static_cast <QLineEdit*>(editor);
    QString text = lineEdit->text();
    model->setData(index, text, Qt::EditRole);
}

void  CCLineEditDelegate::updateEditorGeometry(QWidget *editor,
                                              const  QStyleOptionViewItem &option,  const  QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
