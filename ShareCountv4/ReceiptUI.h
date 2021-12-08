#ifndef RECEIPTUI_H
#define RECEIPTUI_H


#include <QDialog>
#include "ui_ReceiptUI.h"
#include "Person.h"
#include "Recepisse.h"

class Group;

class ReceiptUI : public QDialog
{
    Q_OBJECT
public:
    ReceiptUI(Group *g, QWidget *parent = 0);
    const Recepisse&	GetReceipt() const;

protected slots:
    void slot_onAddPayer();
    void slot_onRemovePayer();

protected:
    void AddPayer(Person::IDType id);

private:
    Ui::ReceiptDialog ui;
    Group *m_pGroup;
    Recepisse	m_Receipt;
};

#endif // RECEIPTUI_H
