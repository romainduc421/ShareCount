#ifndef GROUPLISTMODEL_H
#define GROUPLISTMODEL_H


#include <QAbstractListModel>
#include "Person.h"
#include <vector>

class Group;

/*!
 * \brief The GroupListModel class
 * modèle d'un cercle d'amis implementant une liste abstraite de données
 * QAbstractListModel
 */
class GroupListModel : public QAbstractListModel
{
	Q_OBJECT
public:

    /*!
     * \brief GroupListModel constructeur du modèle
     * \param g le groupe considéré
     * \param parent l'objet parent (fenetre principale)
     */
	GroupListModel(Group *g, QObject *parent = 0);

    /*!
     * \brief ~GroupListModel destructeur du modèle
     */
	virtual ~GroupListModel();

    /*!
     * \brief rowCount
     * \param parent
     * \return
     */
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;

    /*!
     * \brief columnCount
     * \param parent
     * \return
     */
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;

    /*!
     * \brief data
     * \param index
     * \param role
     * \return
     */
    virtual QVariant data(const QModelIndex &index, int role = 0) const;

    /*!
     * \brief headerData
     * \param section
     * \param orientation
     * \param role
     * \return
     */
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    /*!
     * \brief sort tri des colonnes par ordre ascendant (alphanum) des personnes
     * \param column
     * \param order
     */
    virtual void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

    /*!
     * \brief addMember
     * \param p
     */
	void addMember(Person *p);

    /*!
     * \brief removeMember remove the member represented by the QModelIndex given
     * \param index
     */
    void removeMember(const QModelIndex& index);

private:
    Group               *m_pGroup;

    /**
     * @brief m_sortVector vector allowing the capacity to sort the groupList
     */
    std::vector<int>    m_sortVector;

};


#endif
/* GROUPLISTMODEL_H included */
