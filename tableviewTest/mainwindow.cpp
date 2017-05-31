#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resize(620, 400);

    m_pModel = new QStandardItemModel(this);
    m_pHeadDeleagte = new CCheckBoxHeaderView(0, Qt::Horizontal, ui->tableView);
    m_pModelDataList = new QList<CModelData *>();
    m_pButtonDelegate = new CPixBtnDelegate(this);
    m_pNumberDelegate = new CSpinBoxDelegate(this);
    m_pComboBoxDelegate = new CComboBoxDelegate(this);
    m_pLineEditDelegate = new CCLineEditDelegate(this);
    m_pComboCheckBoxDelegate = new CComboCheckBoxDelegate(this);
    m_pProcessDelegate = new CProcessDelegate(this);
    m_pProcess2Delegate = new CProcess2Delegate(this);
    m_pDateTimeDelegate = new CDateTimeEditDelegate(this);
    setDelegate();
    setHeadData();
    setModelData();

}

MainWindow::~MainWindow()
{

    QList<CModelData *>::iterator it_1 = m_pModelDataList->begin();
    while (it_1 != m_pModelDataList->end()) {
        CModelData *pModel = *it_1;
        if (pModel) {
            delete pModel;
            pModel = NULL;
        }
        it_1++;
    }
    m_pModelDataList->clear();

    if(m_pHeadDeleagte != NULL){
        delete m_pHeadDeleagte;
        m_pHeadDeleagte = NULL;
    }
    delete ui;
}

void MainWindow::setDelegate()
{
    m_pButtonDelegate->setPixPath(":/Res/Images/btn_Detail.png");
    ui->tableView->setItemDelegateForColumn(0, m_pLineEditDelegate);
    ui->tableView->setItemDelegateForColumn(1, m_pNumberDelegate);
    ui->tableView->setItemDelegateForColumn(2, m_pComboBoxDelegate);
    ui->tableView->setItemDelegateForColumn(4, m_pDateTimeDelegate);
    ui->tableView->setItemDelegateForColumn(5, m_pProcess2Delegate);
    ui->tableView->setItemDelegateForColumn(6, m_pProcessDelegate);
    ui->tableView->setItemDelegateForColumn(7, m_pComboCheckBoxDelegate);
    ui->tableView->setItemDelegateForColumn(8, m_pButtonDelegate);
    connect(m_pHeadDeleagte, SIGNAL(sig_AllChecked(bool)), this, SLOT(slotHeadCheckBoxStateChanged(bool)));
    connect(m_pButtonDelegate, SIGNAL(sig_buttonClicked(QModelIndex)), this, SLOT(slotTablePixBtnClicked(QModelIndex)));
}

void MainWindow::setHeadData()
{
    m_pModel->setColumnCount(8);
    QStringList headMessage;
    headMessage << QObject::tr("id")  << QObject::tr("age")
                << QObject::tr("sex")  << QObject::tr("join")
                << QObject::tr("time") << QObject::tr("process") << QObject::tr("process2")
                << QObject::tr("chose") << QObject::tr("confirm");
    m_pModel->setHorizontalHeaderLabels(headMessage);
    ui->tableView->setModel(m_pModel);
    ui->tableView->setHorizontalHeader(m_pHeadDeleagte);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //自适应列宽
}

void MainWindow::setModelData()
{
    for(int i = 0; i< 1000; i++){
        CModelData * pModelData = new CModelData("11", "MAN", "unjoin", QDateTime::currentDateTime(), i+2);
        m_pModelDataList->append(pModelData);
    }

    m_pModel->setRowCount(0);
    int iRow = 0;
    for(QList<CModelData *>::const_iterator iter = m_pModelDataList->begin(); iter != m_pModelDataList->end(); iter++){
        QRadioButton *radioBtn = new QRadioButton("unjoin");
        connect(radioBtn, SIGNAL(toggled(bool)), this, SLOT(OnRadioButton(bool)));

        CModelData *pModel = *iter;
        m_pModel->setRowCount(m_pModel->rowCount() + 1);
        int iNumber = m_pModel->rowCount();
        m_pModel->setData(m_pModel->index(iNumber-1, 0, QModelIndex()),iNumber);
        m_pModel->setData(m_pModel->index(iNumber-1, 1, QModelIndex()),pModel->getAge());
        m_pModel->setData(m_pModel->index(iNumber-1, 2, QModelIndex()),pModel->getSex());
        ui->tableView->setIndexWidget(m_pModel->index(iRow, 3), radioBtn); //添加RadioButton
        m_pModel->setData(m_pModel->index(iNumber-1, 4, QModelIndex()),pModel->getTime().toString());
        m_pModel->setData(m_pModel->index(iNumber-1, 5, QModelIndex()),pModel->getProcess());
        m_pModel->setData(m_pModel->index(iNumber-1, 6, QModelIndex()),pModel->getProcess());
        m_pModel->setData(m_pModel->index(iNumber-1, 7, QModelIndex()),"111");

        m_pModel->item(iNumber-1, 0)->setCheckable(true); //添加CheckBox
        m_pModel->item(iNumber-1, 0)->setTextAlignment(Qt::AlignCenter);
        m_pModel->item(iNumber-1, 1)->setTextAlignment(Qt::AlignCenter);
        m_pModel->item(iNumber-1, 2)->setTextAlignment(Qt::AlignCenter);
        m_pModel->item(iNumber-1, 4)->setTextAlignment(Qt::AlignCenter);
        m_pModel->item(iNumber-1, 5)->setEnabled(false);
        iRow++;
    }
}

void MainWindow::OnRadioButton(bool clicked)
{
    QRadioButton *radioBtn = dynamic_cast<QRadioButton*>(sender());
    if (radioBtn != NULL)
    {
        if (clicked)
        {
            radioBtn->setText("join");
        }
        else
        {
            radioBtn->setText("unjoin");
        }
    }
}

void MainWindow::slotHeadCheckBoxStateChanged(bool status)
{
    if (status) {
        for (int i=0; i<m_pModel->rowCount(); ++i)
            m_pModel->item(i, 0)->setCheckState(Qt::Checked);
    }
    else {
        for (int i=0; i<m_pModel->rowCount(); ++i)
            m_pModel->item(i, 0)->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::slotTablePixBtnClicked(QModelIndex index)
{
    QMessageBox messageBox;
    messageBox.setText(QString("row: %1; column: %2").arg(index.row()).arg(index.column()));
    messageBox.exec();
}
