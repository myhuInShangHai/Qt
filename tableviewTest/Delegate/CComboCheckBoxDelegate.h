#ifndef CCOMBOCHECKBOXDELEGATE_H
#define CCOMBOCHECKBOXDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QComboBox>
#include <QPair>

class CComboCheckBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    CComboCheckBoxDelegate(QObject *parent = 0);

    ~CComboCheckBoxDelegate(void);

protected:
    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
        const QModelIndex &index) const;
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
        const QModelIndex &index) const;

private:
    void setEditor(QWidget *pEditor);

private:
    QList<QPair<QString, Qt::CheckState> > m_lstComboCheckBoxItems;
    mutable QComboBox* m_pComboBox;
    QString m_strCurrentText;
private slots:
    void OnStateChanged(int iState);
};

#endif // CCOMBOCHECKBOXDELEGATE_H
