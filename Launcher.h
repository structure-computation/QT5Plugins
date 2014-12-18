#ifndef LAUNCHER_H
#define LAUNCHER_H
#include <Soca/Com/SodaClient.h>
#include <QtCore/QProcess>
#include <QtCore/QList>



class Launcher : public QObject { 
  Q_OBJECT
 public:
    Launcher(){};
    Launcher(QList<SodaClient*> &sc_list_){
            sc_list        = sc_list_;
        }
    
    ~Launcher(){
        qDebug() << "CLOSE LOOP";
    };
    
 public slots:
      void launch(){   //fonction à définir dans chaque launcher
          qDebug() << "test" ;

          for (int i = 0; i < sc_list.size(); ++i) {
              qDebug() << "sc1.pending_events" << sc_list[i]->pending_events_size();
          }
      }; 
      
 public: 
      QList<SodaClient*> sc_list;     
};


#endif // LAUNCHER_H
