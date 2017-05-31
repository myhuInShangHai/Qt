#ifndef CCHECKBOXHEADERVIEW_H
#define CCHECKBOXHEADERVIEW_H

#include <QtGui>
#include <QHeaderView>
#include <QStyleOptionButton>
#include <QStyle>

class CCheckBoxHeaderView : public QHeaderView
{
    Q_OBJECT
public:
    explicit CCheckBoxHeaderView(int checkBoxColumnId, Qt::Orientation orientation, QWidget * parent = 0);
    virtual ~CCheckBoxHeaderView();

signals:
    void sig_AllChecked(bool checked);

protected:
    void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const;
    void mousePressEvent(QMouseEvent *event);

private:
    int  m_checkBoxColumnId;
    bool m_checkBoxIsOn;
};

#endif // CCHECKBOXHEADERVIEW_H
