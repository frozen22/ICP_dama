/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   OnlinePlayer
 */


#include "OnlinePlayer.h"

/**
 * OnlinePlayer.
 *
 * @author Frantisek Nemec (xnemec61)
 */
OnlinePlayer::OnlinePlayer(bool c, QTcpSocket * player) {
  Player::setPlayer(c);
  socket = player;
  type = 'O';
}

Move *OnlinePlayer::getMove() {
  QCoreApplication::processEvents();
  string strRead;
  //cteni tahu
  try {
    bool quit = false;
    while (!quit) {
      
      QApplication::processEvents();
      
      if (!socket->waitForReadyRead(50)) {
        QByteArray data = socket->readAll();
        // prevedeni tahu
        strRead = data.data();
        //prisel podvrh, nechci data...
        if (strRead.size() != 4) {
          continue;
        }
        //nepritel nema kam hrat -- konec hry
        if (!strRead.compare("NULL")) {
          return NULL;
        }
        if (strRead.size() == 4) {
          break;

        }
      }
    }
  } catch (exception e) {
    cout << "Nepritel se odpojil!" << endl;
    
    return NULL;
  }
  return decodeStringToMove(strRead);
}

/**
 * Prevedeni tahy v textove podobe do tridy Move;
 * 
 * @param strMove Tah v zakladni notaci
 * @return Move
 */
Move *OnlinePlayer::decodeStringToMove(string strMove) {
  // move example: a3b4
  string fromStr = strMove.substr(0, 2); // a3
  string toStr = strMove.substr(2, 4); // b4

  Position *from = game->getDesk()->getPositionAt(fromStr.at(0), fromStr.at(1) - '0');
  Position *to = game->getDesk()->getPositionAt(toStr.at(0), toStr.at(1) - '0');

  return new Move(from, to);
}

void OnlinePlayer::remindPlayer(Move *move) {
  if (move == NULL) {
    socket->write("NULL");
    return;
  }
  string s = codeMoveToString(move);
  try {
    socket->write(s.c_str());
  } catch (exception e) {
    cerr << "Error" << endl;
  }
}
//    
