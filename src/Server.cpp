/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Server
 */

#include "Server.h"
#include "Player.h"

Server::Server(int Port, QObject* parent) : QObject(parent) {
  server = new QTcpServer(this);

  serverPort = Port;
  color = WHITE;
  basicStr = "";
  ready = false;
  
  connect(server, SIGNAL(newConnection()), this, SLOT(handleNewConnection()));
  //        nastaveni omezeni
  //        server->setProxy(QNetworkProxy::NoProxy);
  //      	server->setMaxPendingConnections(10);
  bool success = server->listen(QHostAddress::Any, serverPort);

  //nepovedlo se podarit tcp na dane IP a portu
  if (!success) {
    cerr << "Chyba pri priprave prenosu!" << endl;
  } else {
    cout << "Cekam na prenos..." << endl;
  }
  server->waitForNewConnection();
  qApp->processEvents();

}


/**
 * Cekani na pripojeni klienta.
 * 
 * @return True - uspesne pripojeni klienta, False - accept error
 */
bool Server::handleNewConnection() {
  try {

    //ziskani socketu
    QTcpSocket* socket = server->nextPendingConnection();
    if (!socket) {
      cerr << "Chyba socketu pri prijmani spojeni!" << endl;
      return false;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(read()));

    connect(socket, SIGNAL(disconnected()),this, SLOT(close()));
    qApp->processEvents();
    
  } catch (exception e) {
    cerr << e.what() << endl;
    return false;
  }

  return true;
}

/**
 * Cteni ze socketu.
 * 
 * @return Precteny retezec. prazdny retezec v pripade chyby.
 */
void Server::read() {
  if(ready){return;}
  client = qobject_cast<QTcpSocket*>(this->sender());

  string strRead;


  try {
    QByteArray data = client->readAll(); //cteni
    strRead = data.data();
  } catch (exception e) {
    cerr << "Chyba pri cteni socketu!" << endl; 
    cerr << e.what() << endl;
    return ;
  }
  
  //prisla barva, kterou bude hrat hrac s timto "klientem"
  if(strRead[0] == 'w'){
    color = WHITE;
    //zakladame novou hru...
    if(strRead[1] == 'n'){
      ready = true;
      return;
    }
  }
  
  if(strRead[0] == 'b'){
    color = BLACK;
    if(strRead[1] == 'n'){
      ready = true;
      return;
    }
  }
  
  //nahrati hry
  if(strRead[0] == '1'){
    basicStr = strRead;
    ready = true;
  }
 

  
  
  return;
}



/**
 * Odeslani zpravy pripojenemu klientovy.
 * 
 * @param dataString Odesilana zprava.
 */
void Server::send(string dataString) {

  try {
    client->write(dataString.c_str());
    client->flush();
    
  } catch (exception e) {
    cerr << e.what() << endl;
  }
}

/**
 * Uzavreni socketu. mozna do destruktoru!
 */
void Server::close() {
  //zjisti, ktery socket poslal signal a ten uzavre
  client = qobject_cast<QTcpSocket*>(this->sender());
  try {
    client->deleteLater();
  } catch (exception e) {
    cerr << "Chyb pri uzavirani socketu" << endl; 
    cerr << e.what() << endl;
  }
}

QTcpServer * Server::getServer(){
    return server;
}


