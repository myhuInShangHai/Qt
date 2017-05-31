#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QObject>
#include <QRadioButton>
#include <QMessageBox>
#include "Delegate/CCheckBoxHeaderView.h"
#include "ModelData/CModelData.h"
#include "Delegate/CPixBtnDelegate.h"
#include "Delegate/CSpinBoxDelegate.h"
#include "Delegate/CComboBoxDelegate.h"
#include "Delegate/CCLineEditDelegate.h"
#include "Delegate/CComboCheckBoxDelegate.h"
#include "Delegate/CProcessDelegate.h"
#include "Delegate/CDateTimeDelegate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    void setDelegate();
    void setHeadData();
    void setModelData();

private slots:
    void OnRadioButton(bool clicked);
    void slotHeadCheckBoxStateChanged(bool status);
    void slotTablePixBtnClicked(QModelIndex index);

private:
    Ui::MainWindow *ui;

private:
    QStandardItemModel  * m_pModel;
    CCheckBoxHeaderView * m_pHeadDeleagte;
    QList<CModelData *> * m_pModelDataList;
    CPixBtnDelegate     * m_pButtonDelegate;
    CSpinBoxDelegate    * m_pNumberDelegate;
    CComboBoxDelegate   * m_pComboBoxDelegate;
    CCLineEditDelegate  * m_pLineEditDelegate;
    CComboCheckBoxDelegate * m_pComboCheckBoxDelegate;
    CProcessDelegate    * m_pProcessDelegate;
    CProcess2Delegate    * m_pProcess2Delegate;
    CDateTimeEditDelegate * m_pDateTimeDelegate;
};

#endif // MAINWINDOW_H
