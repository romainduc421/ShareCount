#ifndef ADDPAYERDIALOG_H
#define ADDPAYERDIALOG_H


#include <QDialog>
#include "ui_AddPayerDialog.h"
#include "Person.h"
#include "Group.h"

class Group;

class AddPayerDialog : public QDialog
{
    Q_OBJECT

protected:
    void SetupComboBox();

private:
    Ui::AddPayerDialog ui;
    Group *m_pGroup;
public:
    Amount GetAmount()  const;
    AddPayerDialog(Group *g, QWidget *parent = 0);
    Person::IDType	GetSelectedID() const;

};

#endif // ADDPAYERDIALOG_H included
