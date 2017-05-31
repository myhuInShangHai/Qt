#ifndef CDATETIMEDELEGATE_H
#define CDATETIMEDELEGATE_H

#include <QObject>
#include <QItemDelegate>

class CDateTimeEditDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    explicit CDateTimeEditDelegate(QObject *parent = 0);
    ~CDateTimeEditDelegate(void);

protected:
    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
        const QModelIndex &index) const;
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
        const QModelIndex &index) const;

private:
    QString m_strDisplayFormat;
};

#endif // CDATETIMEDELEGATE_H
