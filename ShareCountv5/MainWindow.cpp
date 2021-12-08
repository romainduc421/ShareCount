#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Group.h"
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <fstream>
#include <qfile.h>
#include "ReceiptUI.h"
#include "DialogGroupList.h"
#include <QFileDialog>

#include <iostream>

using boost::archive::text_iarchive;
using boost::archive::text_oarchive;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_pGroup(new Group())
{
    ui.setupUi(this);
    connectSlots();
    m_pGroup->addGroupMember(new Person("Hunter"));
    m_pGroup->addGroupMember(new Person("Phil"));

    m_pGroup->AddReceiptCollection(QString::fromUtf8("Collection 1"));
    Recepisse r;
    r.AddPayerByAmount( m_pGroup->member(0).getID(), Amount(45.0) );
    m_pGroup->GetReceiptCollection(0).AddReceipt(r);
    m_pDataModel.reset( new ReceiptCollectionModel(m_pGroup.get()) );
    ui.treeView->setModel( m_pDataModel.get() );
    ui.treeView->setHeaderHidden(true);
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

    connect(ui.actionLoad_Group, SIGNAL(triggered()), this, SLOT(slot_OpenGroup()));
    connect(ui.actionSave_Group, SIGNAL(triggered()), this, SLOT(slot_SaveGroup()));
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

        Recepisse rr;
        rr.SetDate( boost::gregorian::date(2014, boost::gregorian::May, 25 ));
        dlg.SetReceiptData(rr);
        dlg.exec();
    } catch (std::exception &e) {
        //std:cerr << "Erreur:"+e << std::endl;
    }
}


void MainWindow::slot_OpenGroup()
{
    try {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open Group"), QDir::home().absolutePath(), QString::fromUtf8(".grp") );
        if (fileName != QString()) {
            std::ifstream file (fileName.toLocal8Bit(), std::ios::in);
            text_iarchive ar (file);
            ui.treeView->setModel(0);
            m_pDataModel.reset();
            m_pGroup.reset( new Group() );
            ar & (*m_pGroup); //read into the group
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void MainWindow::slot_SaveGroup()
{
    try {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save Group"), QDir::home().absolutePath(), QString::fromUtf8(".grp") );
        if (fileName != QString()) {
            std::ofstream file (fileName.toLocal8Bit(), std::ios::out);
            text_oarchive ar (file);
            ar & (*m_pGroup); //write group into the archive
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

}
