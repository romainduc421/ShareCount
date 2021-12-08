#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_MainWindow.h"
#include <boost/smart_ptr/scoped_ptr.hpp>

/*!
 * A scoped_ptr assumes ownership of the resource to which it points,
 * and never accidentally surrenders that ownership.
 * This property of scoped_ptr improves expressiveness in our code,
 * as we can select the smart pointer (scoped_ptr or auto_ptr)
 * that best fits our needs.
 */

class Group;

/*!
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow
     * \param parent
     */
    explicit MainWindow(QWidget *parent = 0);

    /*!
     * \brief ~MainWindow
     */
    virtual ~MainWindow();

public slots:
    /*!
     * \brief slot_editGroupMembers
     */
    void slot_editGroupMembers();
    void slot_addReceipt();

private:
    /*!
     * \brief m_pGroup
     */
    boost::scoped_ptr<Group> m_pGroup;

    /*!
     * \brief ui
     */
    Ui::MainWindow ui;

    /*!
     * \brief connectSlots
     */
    void connectSlots();

    /*!
     * \brief MainWindow  without copying
     * \param other
     */
    explicit MainWindow(const MainWindow& other);
};

#endif // MAINWINDOW_H
