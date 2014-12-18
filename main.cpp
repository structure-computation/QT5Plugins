#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>
#include <QtGui/QTableView>

#include <Soca/Com/SodaClient.h>
#include <QtCore/QProcess>
#include <QtCore/QList>

#include "Launcher.h"
#include "MyTable.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    SodaClient::_nb_inst = 1;


    QList< QList< QString > > list_server_object;
    QList< QString > list_1; list_1 << "127.0.0.1"      << "/__users__" ;
    QList< QString > list_2; list_2 << "192.168.38.238" << "/__users__" ;

    list_server_object << list_1; // << list_2;
//     list_server_object[0] << "127.0.0.1"      << "/__users__" ;
//     list_server_object[1] << "192.168.38.238" << "/__users__" ;

    QList<MP> mp_list;
    QList<SodaClient*> sc_list;
    Launcher *launcher = new Launcher(sc_list);
//    QEventLoop loop;

    qDebug() << list_server_object.size();
    sc_list.reserve(list_server_object.size());

    for (int i = 0; i < list_server_object.size(); ++i) {
        QHostAddress adress1(list_server_object[i][0]);  //localhost

        sc_list << new SodaClient( adress1, 8890 );

        qDebug() << "test";
        MP object_id = sc_list.last()->load("/__users__");
        mp_list << object_id;
        qDebug() << (mp_list.last())[0]["name"];
        sc_list.last()->reg_model( object_id );

        QObject::connect(sc_list.last(), SIGNAL(new_event()), launcher, SLOT(launch()));
        QObject::connect(sc_list.last(), SIGNAL(quit()), &app, SLOT(quit()));
    }
    qDebug() << "test2";

    QWidget window;
    window.resize(300, 200);

    QTableView tableView( &window);
    MyTable myModel(0, mp_list[0], sc_list[0]);
    tableView.setModel( &myModel );
    QObject::connect(sc_list[0], SIGNAL(new_event()), &tableView, SLOT(reset()));

    tableView.show();

    QPushButton quit("Quit", &window);
    quit.setFont(QFont("Times", 18, QFont::Bold));
    quit.setGeometry(10, 140, 180, 40);
    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    window.show();

    return app.exec();

};
