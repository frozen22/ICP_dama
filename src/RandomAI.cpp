/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   RandomAI
 */

#include "RandomAI.h"

/**
 * Umela inteligence s nahodnym vyberem tahu.
 *
 * @author Frantisek Nemec (xnemec61)
 */

RandomAI::RandomAI(bool c) {

  Player::setPlayer(c);
  type = 'R';

}

Move *RandomAI::getMove() {
  srand(time(NULL));
  int randNum;
  list<Position*> l;
  Position *from;
  Position *to;
  // ziskani pozic figurek s kterymi lze hrat
  l = game->getDesk()->getPlayablePositions(color);

  // nelze provest zadny tah
  if (l.empty())
    return NULL;

  // jen jeden tah na vyber
  if (l.size() == 1) {
    from = l.front();
    
  } else {// nahodny vyber
    randNum = rand() % (l.size() - 1); 
    list<Position*>::iterator it = l.begin();
    std::advance(it, randNum);
    from = *it;
  }
  // nalezeni moznych pohuby s figurkouy
  l = from->getFigure()->getPlayableMoves();

  // nelze provest zadny tah
  if (l.empty())
    return NULL;

  // jen jeden tah na vyber
  if (l.size() == 1) {
    to = l.front();
    
  } else {// nahodny vyber
    randNum = rand() % (l.size() - 1); 
    list<Position*>::iterator it = l.begin();
    std::advance(it, randNum);
    to = *it;
  }

  //predstirani vypoctu 1s
  try{
    usleep(1000000);
  }
  catch(std::exception e){
    string s;
    cout << "Chcete pokracovat? Y/N" << endl;
    std::getline(cin,s);
    while(s.compare("Y") && s.compare("N")){
      cout << "Zadejte znovu volbu: Y/N" << endl;
      std::getline(cin,s);
      
    }
    if(!s.compare("N")){
      return NULL;
    }
    if(!s.compare("Y")){
      return new Move(from,to);
    }
  }


  return new Move(from, to);
}

