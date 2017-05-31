#include "CComboCheckBoxDelegate.h"
#include <QListWidget>
#include <QCheckBox>


CComboCheckBoxDelegate::CComboCheckBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent), m_pComboBox(NULL)
{
    QPair<QString, Qt::CheckState> list;
    list.first = "111"; list.second = Qt::Unchecked;
    QPair<QString, Qt::CheckState> list2;
    list2.first = "222"; list.second = Qt::Unchecked;
    QPair<QString, Qt::CheckState> list3;
    list3.first = "333"; list.second = Qt::Unchecked;
    m_lstComboCheckBoxItems.append(list);
    m_lstComboCheckBoxItems.append(list2);
    m_lstComboCheckBoxItems.append(list3);

    m_strCurrentText.clear();
}

CComboCheckBoxDelegate::~CComboCheckBoxDelegate()
{

}

QWidget* CComboCheckBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                              const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QListWidget* pListWidget = new QListWidget;
    for (int i = 0; i < m_lstComboCheckBoxItems.size(); i++)
    {
        QListWidgetItem* pItem = new QListWidgetItem(pListWidget);
        pItem->setData(Qt::UserRole, i);
        pListWidget->addItem(pItem);

        QCheckBox* pCheckBox = new QCheckBox;
        pCheckBox->setText(m_lstComboCheckBoxItems.at(i).first);
        pCheckBox->setCheckState(m_lstComboCheckBoxItems.at(i).second);
        connect(pCheckBox, SIGNAL(stateChanged(int)), this, SLOT(OnStateChanged(int)));
        pListWidget->setItemWidget(pItem, pCheckBox);
    }

    m_pComboBox = new QComboBox(parent);
    m_pComboBox->setModel(pListWidget->model());
    m_pComboBox->setView(pListWidget);
    m_pComboBox->setEditable(true);

    return m_pComboBox;
}


void CComboCheckBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString strText = index.model()->data(index, Qt::EditRole).toString();
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    comboBox->setEditText(strText);
}


void CComboCheckBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    QString strData = comboBox->currentText();
    model->setData(index, strData, Qt::EditRole);
}


void CComboCheckBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                                                  const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}


void CComboCheckBoxDelegate::OnStateChanged(int iState)
{
    m_strCurrentText.clear();
    QCheckBox* pCheckBox = qobject_cast<QCheckBox*>(sender());
    int iCount = m_lstComboCheckBoxItems.size();
    for (int i = 0; i < iCount; i++)
    {
        if (pCheckBox->text().compare(m_lstComboCheckBoxItems.at(i).first) == 0)
        {
            if (iState == 0)
            {
                m_lstComboCheckBoxItems[i] = qMakePair(m_lstComboCheckBoxItems.at(i).first, Qt::Unchecked);
            }
            else if (iState == 1)
            {
                m_lstComboCheckBoxItems[i] = qMakePair(m_lstComboCheckBoxItems.at(i).first, Qt::PartiallyChecked);
            }
            else if (iState == 2)
            {
                m_lstComboCheckBoxItems[i] = qMakePair(m_lstComboCheckBoxItems.at(i).first, Qt::Checked);
            }
        }

        if (m_lstComboCheckBoxItems.at(i).second == Qt::Checked)
        {
            m_strCurrentText += m_lstComboCheckBoxItems.at(i).first;
            m_strCurrentText += ";";
        }
    }

    if (m_strCurrentText.right(1) == ";")
    {
        m_strCurrentText.chop(1);
    }

    if (m_pComboBox != NULL)
    {
        m_pComboBox->setEditText(m_strCurrentText);
    }
}
