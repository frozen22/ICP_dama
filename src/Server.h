/**
 * Predmet: Seminar Java (IJA)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Server
 */

#ifndef SERVER_H
#define	SERVER_H

#include <string>
#include <iostream>
#include <exception>
#include <sstream>

#include <QtNetwork> // otestovat na merlinovi!
#include <QObject>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket> // otestovat na merlinovi!

using std::string;
using std::cerr;
using std::cout;
using std::endl;
using std::flush;
using std::exception;
using std::stringstream;


//const int WHITE = 1;
//const int BLACK = 0;

/**
 * Serverova cast komunikace po siti.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */
class Server : public QObject {
  Q_OBJECT
private:
  int serverPort; // cislo portu server
  QTcpServer *server; // socket serveru
  QTcpSocket *client; // socket pripojeneno klienta
  string basicStr;
  bool color;
  bool ready;
  

public:
  /**
   * Konstruktor.
   * 
   * @param serverPort Cislo portu na kterem je server spusten
   */
  Server(int, QObject * parent = 0);
  /**
   * Destruktor se postara o pamet alokovane pro QTcpServer
   */
  ~Server(){
   delete server; 
  }

  /**
   * Jsme pripraveni zapocit hru
   * @return true/false
   */
  bool isReady(){
    return ready;
  }
  
  /**
   * Zakladni notace rozehrane partie
   * @return retezec zakladni notace
   */
   string getBasicStr(){
    return basicStr;
  }
  
  /**
   * Vrati barvu hrace
   * @return barva 
   */
  bool getColor(){
    return color;
  }
  
  /**
   * Vrati ukazatel na socket
   * @return socket
   */
  QTcpSocket * getSocket(){
    return client;
  }

  /**
   * Odeslani zpravy pripojenemu klientovy.
   * 
   * @param dataString Odesilana zprava.
   */
  void send(string dataString);

public slots:
  /**
   * Cteni ze socketu.
   * 
   * @return Precteny retezec. Null v pripade chyby.
   */
  void read();

  /**
   * Cekani na pripojeni klienta.
   * 
   * @return True - uspesne pripojeni klienta, False - accept error
   */
  bool handleNewConnection();

  /**
   * Ziskani socketu server. Pouziva se pri kontrole zda byl server vytvoren.
   */
  QTcpServer * getServer();

  /**
   * Uzavreni socketu.
   */
  void close();



};


#endif	/* SERVER_H */

