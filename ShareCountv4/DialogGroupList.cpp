#include "DialogGroupList.h"

DialogGroupList::DialogGroupList(Group *g, QWidget *parent) :
	QDialog(parent)
{
	ui.setupUi(this);
	ui.widget->setGroup(g);
}
