/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   ReplayGame
 */

#include "ReplayGame.h"

/**
 * Prehravaci hra. Tato trida obsahuje metody urcene jen k prehravani ulozene
 * hry.
 *
 * @author Frantisek Nemec (xnemec61)
 */

/**
 * Vykonani tahu. Vykonani tahu obsahuje: samotne vykonani tahu, prekresleni
 * grafickeho rozhrani a tisk tahu do tiskove pole u hraci desky
 * @param m Konany tah.
 */
bool ReplayGame::makeMove(Move *m) {
  // provedeni tahu

  if (m->getFrom() == NULL || m->getTo() == NULL || m->getFrom()->getFigure() == NULL) {
    return false;
  }

  // ulozeni odstranene figurky do Move.
  // figurka je pouzita pri vypisovani tahu (a1-c3, a1xc3)
  Figure *midFig = m->getFrom()->figBetween(m->getTo());
  if (midFig == NULL) {
    return false;
  }

  if (midFig != m->getFrom()->getFigure()) {
    m->setTaken(midFig->getPosition());
    m->setTakenFig(midFig);
  }


  list<Position *> validPosList = desk->getPlayablePositions(playingPlayer);
  list<Position *>::iterator it = find(validPosList.begin(), validPosList.end(), m->getFrom());
  //neobsahuje prvek
  if (it != validPosList.end() && *it != m->getFrom()) {
    return false;
  }

  validPosList = m->getFrom()->getFigure()->getPlayableMoves();

  it = find(validPosList.begin(), validPosList.end(), m->getTo());

  if (it != validPosList.end() && *it != m->getTo()) {
    return false;
  }

  m->getFrom()->getFigure()->move(m->getTo()); // provedeni tahu


  if (playingPlayer == WHITE) {
    playingPlayer = BLACK;
  } else {
    playingPlayer = WHITE;
  }

  return true;
}

void ReplayGame::goToMove(int num, int interval) {
  int actMoveNum = moves->getActualMoveNum();
  int maxMoveNum = moves->getMaxMoveNum();
  if (num < 0 || num > maxMoveNum) {
    cout << "Nespravny rozsah pohybu!" << endl;
    return; 
  }

  autoPlaySign = true;
  
  //Provedeni vsech tahu mezi aktualnim a zadanym
  if (num > actMoveNum) {
    while (moves->getActualMoveNum() != num) {
      if(autoPlaySign){
        replayNextMove();
        
        if(interval != 0){
          autoPlayInter = interval * 1000;
          try{
            //usleep(autoPlayInter);
          }
          catch(std::exception e){
            return;
          }
        }
      }
      
    }
  } else if (num < actMoveNum) {
    while (moves->getActualMoveNum() != num) {
      if(autoPlaySign){
        replayUndoMove();
        if(interval != 0){
          autoPlayInter = interval * 1000;
          try{
            //usleep(autoPlayInter);
          }
          catch(std::exception e){
            return;
          }
        }
      } 
    }
  }
  desk->print(); //vykresleni pozadovaneho tahu
  cout << endl;
}



Move *ReplayGame::replayUndoMove() {

    int actSaveMove = moves->getActualMoveNum();

    moves->resetNum();
    desk->clear();
    desk->initDesk();

    playingPlayer = WHITE;

    while (moves->getActualMoveNum() < (actSaveMove - 1)){
        replayNextMove();
    }

    return NULL;
}

/**
 * Pouzito pri prehrani hry
 * @return vraci informaci o moznosti provest tah
 */
int ReplayGame::replayNextMove() {
  Move *move;
  move = moves->getNextMove();
  if (move == NULL) { // ziskani tahu
    desk->print();
    cout << endl;
    return END_OF_LIST; // jsme na konci seznamu s tahy
  }

  if (makeMove(move) == false) { // Tah nelze provest
    return INVALID;
  }
  desk->print();
  cout << endl;
  return PLAYABLE;
}



