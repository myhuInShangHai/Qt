#include "CComboBoxDelegate.h"
#include <QComboBox>

CComboBoxDelegate::CComboBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QWidget* CComboBoxDelegate::createEditor(QWidget *parent,  const QStyleOptionViewItem &option,
                                         const  QModelIndex &index)  const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QComboBox *editor =  new QComboBox(parent);
    editor->addItem("MAN");
    editor->addItem("WOMAN");
    editor->setCurrentIndex(0);
    //editor->setEditable(true);
    return  editor;
}

void  CComboBoxDelegate::setEditorData(QWidget *editor,  const  QModelIndex &index)  const
{
    QString text = index.model()->data(index, Qt::EditRole).toString();
    QComboBox *comboBox =  static_cast <QComboBox*>(editor);
    int  tindex = comboBox->findText(text);
    comboBox->setCurrentIndex(tindex);
}

void  CComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                      const  QModelIndex &index)  const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    QString strData = comboBox->currentText();
    model->setData(index, strData, Qt::EditRole);
}

void  CComboBoxDelegate::updateEditorGeometry(QWidget *editor,
                                              const  QStyleOptionViewItem &option,  const  QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}

