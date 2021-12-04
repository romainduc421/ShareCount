
#ifndef DIALOGGROUPLIST_H
#define DIALOGGROUPLIST_H
#include "ui_DialogGroupList.h"

class Group;

/*!
 * \brief The DialogGroupList class
 */
class DialogGroupList : public QDialog
{
	Q_OBJECT
public:
    /*!
     * \brief DialogGroupList
     * \param g
     * \param parent
     */
    DialogGroupList(Group *g, QWidget *parent = 0);

private:
    /*!
     * \brief ui
     */
	Ui::Dialog	ui;
};

#endif
/* DIALOGGROUPLIST_H included */
