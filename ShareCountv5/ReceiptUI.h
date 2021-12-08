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
    Recepisse	GetReceipt() const;
    void SetReceiptData(const Recepisse &r);

protected slots:
    void slot_onAddPayer();
    void slot_onRemovePayer();

protected:
    void SetPayee(Payee::IDType);
    void FormatReceipt();

    void SetCategory(int);

    void SetDescription(QString);
    void AddPayer(Person::IDType id, Amount a);
    void SetDate(boost::gregorian::date const& d);

private:
    Ui::ReceiptDialog ui;
    Group *m_pGroup;
    Recepisse	m_Receipt;
};

#endif // RECEIPTUI_H included
