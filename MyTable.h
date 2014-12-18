#ifndef MYTABLE_H
#define MYTABLE_H

#include <QAbstractTableModel>
#include <Soca/Com/SodaClient.h>

class MyTable : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit MyTable(QObject *parent = 0);
    MyTable(QObject *parent = 0, MP mp_ = 0, SodaClient *sc_ = 0);


    int rowCount(const QModelIndex & /*parent*/) const;
    int columnCount(const QModelIndex & /*parent*/) const;
    QVariant data(const QModelIndex &index, int role) const;
    
signals:
    
public slots:


private:
    MP mp;
    SodaClient *sc;
};

#endif // MYTABLE_H
