#include "CDateTimeDelegate.h"
#include <QDateTime>
#include <QDateTimeEdit>

CDateTimeEditDelegate::CDateTimeEditDelegate(QObject *parent)
: QItemDelegate(parent)
{
    m_strDisplayFormat = "yyyy-MM-dd hh:mm:ss ddd";
}

CDateTimeEditDelegate::~CDateTimeEditDelegate()
{

}

QWidget* CDateTimeEditDelegate::createEditor(QWidget *parent,
                                             const QStyleOptionViewItem& option,
                                             const QModelIndex& index ) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QDateTimeEdit *editor = new QDateTimeEdit(parent);
    editor->setDateTime(QDateTime::currentDateTime());
    editor->setDisplayFormat(m_strDisplayFormat);
    return editor;
}

void CDateTimeEditDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QDateTime dt = index.model()->data(index, Qt::EditRole).toDateTime();
    QDateTimeEdit *dtEdit = static_cast<QDateTimeEdit*>(editor);
    dtEdit->setDisplayFormat(m_strDisplayFormat);
    dtEdit->setDateTime(dt);

}

void CDateTimeEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                         const QModelIndex &index) const
{
    QDateTimeEdit *dtEdit = static_cast<QDateTimeEdit*>(editor);
    dtEdit->interpretText();
    dtEdit->setDisplayFormat(m_strDisplayFormat);
    QDateTime dt = dtEdit->dateTime();
    model->setData(index, dt.toString(m_strDisplayFormat), Qt::EditRole);
}

void CDateTimeEditDelegate::updateEditorGeometry(QWidget *editor,
                                                 const QStyleOptionViewItem &option,
                                                 const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

