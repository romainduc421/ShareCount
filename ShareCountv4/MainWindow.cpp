#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Group.h"
#include "ReceiptUI.h"
#include "DialogGroupList.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_pGroup(new Group())
{
    ui.setupUi(this);
    connectSlots();
    m_pGroup->addGroupMember(new Person("Hunter"));
    m_pGroup->addGroupMember(new Person("Phil"));
}

MainWindow::~MainWindow()
{
    //delete *ui;
}

void MainWindow::connectSlots()
{
    connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui.actionGroup_Members, SIGNAL(triggered()), this, SLOT(slot_editGroupMembers()));
    connect(ui.actionReceipt, SIGNAL(triggered()), this, SLOT(slot_addReceipt()));
}

void MainWindow::slot_editGroupMembers()
{
    DialogGroupList dgl (m_pGroup.get(),this); //pass a pointer to the current group
    dgl.setModal(true);					  //set modal
    dgl.exec();                           //create the dialog window
}

void MainWindow::slot_addReceipt()
{
    try {
        ReceiptUI	dlg (m_pGroup.get(), this);
        dlg.setModal(true);
        dlg.exec();
    } catch (std::exception &e) {
        //std:cerr<< "Erreur:"+e <<std::endl;
    }
}
