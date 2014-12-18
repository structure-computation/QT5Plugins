#include "MyTable.h"

MyTable::MyTable(QObject *parent) :
    QAbstractTableModel(parent)
{
}

MyTable::MyTable(QObject *parent, MP mp_, SodaClient *sc_) :
    QAbstractTableModel(parent), mp(mp_), sc(sc_)
{
//    QObject::connect(sc, SIGNAL(new_event()), this, SIGNAL(dataChanged()));
}

int MyTable::rowCount(const QModelIndex & /*parent*/) const
{
   return mp.size();
}

int MyTable::columnCount(const QModelIndex & /*parent*/) const
{
    return 1;
}

QVariant MyTable::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
       return QString(mp[index.row()]["name"]);
    }
    return QVariant();
}
