/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Klient
 */
#include "Client.h"

Client::Client(string host, int port, QObject* parent) : QObject(parent) {
  cout << "Parametry pripojeni port: " << port << ", host: " << host << endl;
  serverHostName = host;
  serverPort = port;
  isConnected = false;
  clientSocket = new QTcpSocket(this);

  // a pripojime jeho signaly na sloty, ktere je zpracuji
  connect(clientSocket, SIGNAL(connected()), SLOT(gotConnect()));
  //connect(clientSocket, SIGNAL(error(QAbstractSocket::SocketError)), SLOT(gotError()));
  connect(clientSocket, SIGNAL(readyRead()), SLOT(read()));
  connect(clientSocket, SIGNAL(disconnected()), SLOT(close()));

  qApp->processEvents();
}

/**
 * Pripojeni k serveru.
 * 
 * @return True - pripojeni probehlo uspesne, False - neuspesne.
 */
bool Client::prepareConnect() {
  try {
    QHostAddress *addr = new QHostAddress(QString::fromStdString(serverHostName));
    clientSocket->connectToHost(*addr, serverPort);

    if (clientSocket->waitForConnected()) {
      
    } else {
      cerr << "Nemohu se pripojit!" << endl;
      return false;
    }

  } catch (exception e) {
    cerr << e.what() << endl;
    return false;
  }

  return true;
}

/**
 * Odeslani zpravy na server.
 * 
 * @param dataString Odesilana zprava.
 */
void Client::send(string dataString) {

  try {
    QByteArray dataToSend;
    dataToSend.append(dataString.c_str());
    clientSocket->write(dataToSend);
    clientSocket->flush();
  } catch (exception e) {
    cerr << e.what() << endl;
  }
}

/**
 * Cteni ze socketu.
 * 
 * @return Precteny retezec. V pripade neuspechu null.
 */
string Client::read() {
  if(isConnected){return "";}
  string strRead;
  try {
    QByteArray data = clientSocket->readAll();

    strRead = data.data();

  } catch (exception e) {
    cerr << "Nstala chyba pri IO operaci se socketem" << endl; //?
    cerr << e.what() << endl;
    return "";
  }
  cout << strRead << endl;
  return strRead;
}

/**
 * Uzavreni socketu.
 */
void Client::close() {
  try {
    if (clientSocket->isOpen()) {
      clientSocket->close();
    }

  } catch (std::exception e) {
    cerr << "Chyba pri zavirani socketu." << endl;
    cerr << e.what() << endl;
  }
}


