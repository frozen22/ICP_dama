/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   LocalPlayer
 */


#include "LocalPlayer.h"

/**
 * Lokalni hrac. Tahy jsou nacitany z grafickeho rozhrani
 *
 * @author Frantisek Nemec (xnemec61)
 */
LocalPlayer::LocalPlayer(bool c) {
  
  Player::setPlayer(c);
  type = 'L';
}

Move *LocalPlayer::getMove() {
  list<Position *> auxList;
  Position * fromPos;
  Position * toPos;

  cout << "Zadejte pozici figurky: " << std::flush;

  auxList = game->getDesk()->getPlayablePositions(color);
  fromPos = getHumanPos();
  //zadano exit
  if (fromPos == NULL) {
    cout << "Hrac " << this->getColor() << " ukoncil hru... " << endl;
    return NULL;
  }
  while (!contains(auxList, fromPos)) {
    cout << "Nevalidni tah! Zadejte novou pozici: " << std::flush;
    fromPos = getHumanPos();
    //zadano exit
    if (fromPos == NULL) {
      cout << "Hrac " << this->getColor() << " ukoncil hru... " << endl;
      return NULL;
    }
  }

  auxList = fromPos->getFigure()->getPlayableMoves();

  cout << "Zadejte cil figurky: " << std::flush;

  toPos = getHumanPos();
  //zadano exit
  if (toPos == NULL) {
    cout << "Hrac " << this->getColor() << " ukoncil hru... " << endl;
    return NULL;
  }
  while (!contains(auxList, toPos)) {
    cout << "Nevalidni tah, zadejte novou cilovou pozici: " << std::flush;
    toPos = getHumanPos();
    //zadano exit
    if (toPos == NULL) {
      cout << "Hrac " << this->getColor() << " ukoncil hru... " << endl;
      return NULL;
    }
  }

  return new Move(fromPos, toPos);


}

bool LocalPlayer::contains(list<Position *> pList, Position * p) {
  list<Position *>::iterator result;
  result = pList.begin();
  result = std::find(result, pList.end(), p);
  if (result != pList.end()) {
    return true;
  }
  return false;
}

Position *LocalPlayer::getHumanPos() {
  string s;

  s.clear();

  std::getline(cin, s);


  if (!s.compare("exit")) {
    return NULL;
  }

  //pokud chce hrac ulozit hru
  if (!s.compare("save")) {
    wantSave = true;
    cout << "Ulozeni hry bude provedeno po odehrati tahu." << endl;
    
    cout << "Zadejte pozici figurky:" << endl;
  }
  
  if( s[0] < 'a' || s[0] > 'h' || s[1] < '1' || s[1] > '8'){
    s = "fail"; //zaruci vchod do while    
  }
    

  while (s.length() != 2 ) {
    if(s.compare("save")){
      cout << "Spatne zadany pohyb! Zkuste znovu." << endl;
    }
    
    s.clear();

    std::getline(cin, s);
    
     //pokud chce hrac ulozit hru
    if (!s.compare("save")) {
      wantSave = true;
      cout << "Ulozeni hry bude provedeno po odehrati tahu." << endl;
       
      cout << "Zadejte pozici figurky:" << endl;
      continue;
    }
    if( s[0] < 'a' || s[0] > 'h' || s[1] < '1' || s[1] > '8'){
      s = "fail";
      continue;
    }
    
    if (!s.compare("exit")) {
      return NULL;
    }
  }

  return game->getDesk()->getPositionAt(s[0], s[1] - '0');
}

