#include "GroupListModel.h"
#include "Group.h"
#include <iostream>


#include <algorithm>
#include <boost/bind.hpp>
#include <boost/function.hpp>

using std::cout;
using std::endl;
using std::cerr;

GroupListModel::GroupListModel(Group *g, QObject *parent) :
	QAbstractListModel(parent),
	m_pGroup(g)
{
    sort(0,Qt::AscendingOrder)
}

GroupListModel::~GroupListModel()
{
	std::cerr << "List Model Deleted..." << std::endl;
}

int GroupListModel::rowCount(const QModelIndex &parent) const
{
	return m_pGroup->size();
}

int GroupListModel::columnCount(const QModelIndex &parent) const
{
	return 1;
}

QVariant GroupListModel::data(QModelIndex const& index, int role) const
{
	if (role == Qt::DisplayRole) {
        //adding sorting ability
        int nombreMembre = m_sortVector.at(index.row());
        return QVariant( m_pGroup->member(nombreMembre).getName() );
	} else {
		return QVariant();
	}
}

QVariant GroupListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (section == 0 && orientation == Qt::Horizontal && role == Qt::DisplayRole)
		return QVariant(tr("Member Name"));
	else
		return QVariant();
}

void GroupListModel::addMember(Person *p)
{
	beginInsertRows(QModelIndex(), m_pGroup->size(), m_pGroup->size());
	m_pGroup->addGroupMember(p);
	endInsertRows();
    sort(0,Qt::AscendingOrder);
}


void GroupListModel::removeMember( const QModelIndex& index )
{
	if (index == QModelIndex())
		return;
	int row = index.row();
	if (row < 0 || row >= m_pGroup->size())
		throw std::runtime_error( (QString("Cannot remove member with row number: ") + QString::number(row)).toStdString() );

	beginRemoveRows(QModelIndex(), row, row);
    int nombreMembre = m_sortVector.at(row);
    m_pGroup->removeGroupMember( m_pGroup->member(nombreMembre).getID() );
	endRemoveRows();
    sort( 0, Qt::AscendingOrder ) ;
}

std::vector<int>
IntegerSequence(int i, int k){
    std::vector<int>  res ( k-i+1 );
    for(int l = i; l <= k-1; l++)
    {
       res[l-i] = l
    }
    return res;
}

bool
SortFunction(int i, int k, Group *grp){
    bool ret = false;
    QString name1 = grp->member(i).getName(),
            name2 = grp->member(k).getName();
    if(name1.compare(name2) < 0)
        ret = true;
    return ret;
}

void
GroupListModel::sort( int col, Qt::SortOrder sortOrder ){
    typedef std::vector<int>::iterator Iter;
    boost::function<bool(int, int)> sortFunction = boost::bind(&SortFunction, _1, _2, m_pGroup);
    m_sortVector = IntegerSequence(1, m_pGroup->size());

    std::sort(m_sortVector.begin(), m_sortVector.end(), sortFunction);
}
