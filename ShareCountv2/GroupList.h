#ifndef GROUPLIST_H
#define GROUPLIST_H

#include "ui_GroupList.h"



class Group;

/*!
 * \brief The GroupList class
 * classe Views represantant la liste QWidget de membres d'un ShareCount
 */
class GroupList : public QWidget
{
	Q_OBJECT
public:
    /*!
     * \brief GroupList
     * \param parent
     */
	GroupList(QWidget *parent = 0);

    /*!
     * \brief setGroup : setter de groupe pour la liste du groupe
     * \param g un groupe quelconque
     */
	void setGroup(Group *g);

protected slots:

    /*!
     * \brief slot_onAddGroupMember
     * slot permettant d'ajouter un membre au groupe existant
     */
	void slot_onAddGroupMember();

    /*!
     * \brief slot_onRemoveGroupMember
     * slot permettant de supprimer un membre au groupe existant
     */
	void slot_onRemoveGroupMember();

private:

    /*!
     * \brief ui : le formulaire
     */
	Ui::Form	ui;

    /*!
     * \brief m_pGroup
     * le groupe courant
     */
	Group		*m_pGroup;
};

#endif
/* GROUPLIST_H included */
