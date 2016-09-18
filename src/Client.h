/**
 * Predmet: Seminar Java (IJA)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Klient
 */

#include <string>
#include <iostream>
#include <exception>

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


#ifndef KLIENT_H
#define	KLIENT_H

/**
 * Klientska cast komunikace po siti.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */
class Client : public QObject {
  Q_OBJECT
private:
  string serverHostName; // adresa serveru
  int serverPort; // cislo serveru
  QTcpSocket *clientSocket;
  bool isConnected;


public:
  /**
   * Konstruktor.
   * 
   * @param serverHostname Adresa serveru
   * @param serverPort Port serveru
   */
  Client(string, int, QObject* parent = 0);

  /**
   * Destruktor Clienta.
   */
  ~Client(){
    delete clientSocket;
  }
  
  /**
   * Pripojeni k serveru.
   * 
   * @return True - pripojeni probehlo uspesne, False - neuspesne.
   */
  bool prepareConnect();

  /**
   * Vrati ukazatel na socket
   * @return socket
   */
  QTcpSocket * getSocket(){
    return clientSocket;
  }
  
  /**
   * Odeslani zpravy na server.
   * 
   * @param dataString Odesilana zprava.
   */
  void send(string dataString);

  /**
   * Zjistuje stav socketu
   * @return je pripraven true/ jinak false
   */
  bool isOpen() {
    return isConnected;
  }

public slots:

  /**
   * Nastala chyba pri praci se socketem
   */
  void gotError() {
    cerr << "Chyba pri praci se socketem" << endl;
  }

  /**
   * Nastavuje priznak vytvoreni spojeni
   */
  void gotConnect() {
    cout << "connected!! " << endl;
    isConnected = true;
  }

  /**
   * Cteni ze socketu.
   * 
   * @return Precteny retezec. V pripade neuspechu null.
   */
  string read();

  /**
   * Uzavreni socketu.
   */
  void close();


};


#endif	/* KLIENT_H */

