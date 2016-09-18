/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Game
 */



#include "Game.h"

/**
 * Game.
 *
 * @author Frantisek Nemec (xnemec61)
 */

Game::Game(Player *p1, Player *p2) {
  desk = new Desk(8);
  movesDone = new Moves();

  //osetreni, aby hral bily prvni
  if (p1->getColor() == BLACK) {
    player1 = p2->initPlayer(const_cast<Game *> (this));
    player2 = p1->initPlayer(const_cast<Game *> (this));
  } else {
    player1 = p1->initPlayer(const_cast<Game *> (this));
    player2 = p2->initPlayer(const_cast<Game *> (this));
  }
  playingPlayer = WHITE;
  turnCount = 1;
}

char Game::start() {
  Move *move;
  string actualcol;
  while (true) {
    desk->print();
    playingPlayer? actualcol = "white": actualcol = "black";
    
    cout << "  na tahu je: " << actualcol << endl;
    
    if (playingPlayer == WHITE) {
      
        move = player1->getMove();
      
      if(player1->wantToSave()){
        saveGame(movesDone);
      }
      
      if (move != NULL) {
        player2->remindPlayer(move);
        
        makeMove(move);
        
      } else { // hrac nemuze nikam tahnout tedy prohral
        player2->remindPlayer(NULL);

        saveGame(movesDone);
        return player2->getColor();

      }
    } else {
      
        move = player2->getMove();
      
      if(player1->wantToSave()){
        saveGame(movesDone);
      }
      if (move != NULL) {
        player1->remindPlayer(move);
        
        makeMove(move);
      } else { // hrac nemuze nikam tahnout tedy prohral
        player1->remindPlayer(NULL);
        
        saveGame(movesDone);
        return player1->getColor();
      }
    }
  }
}

char Game::replayNextMove() {
  Move *move;
  if (playingPlayer == WHITE) {
    move = player1->getMove();
    if (move != NULL) {
      makeMove(move);
    } else {
      return player2->getColor();
    }
  } else {
    move = player2->getMove();
    if (move != NULL) {
      makeMove(move);
    } else {
      return player1->getColor();
    }
  }
  return 0;
}

bool Game::contains(list<Position *> pList, Position * p) {
  list<Position *>::iterator result;
  result = pList.begin();
  result = std::find(result, pList.end(), p);
  if (result != pList.end()) {
    return true;
  }
  return false;
}

bool Game::makeMove(Move *m) {
  // Test pozic v Move
  if (m->getFrom() == NULL || m->getTo() == NULL || m->getFrom()->getFigure() == NULL) {
    return false;
  }

  // Test figurek mezi skoky
  Figure *midFig = m->getFrom()->figBetween(m->getTo());

  if (midFig == NULL) { // neplatny tah, mezi skoky je vice figurek
    return false;
  }

  // ulozeni odstranene figurky do Move.
  // figurka je pouzita pri vypisovani tahu (a1-c3, a1xc3)
  if (midFig != m->getFrom()->getFigure()) {
    m->setTaken(midFig->getPosition());
    m->setTakenFig(midFig);
  }


  // Test validnosti zadaneho tahu
  // Test oznacene figurky
  list<Position *> validPosList = desk->getPlayablePositions(playingPlayer);
  list<Position *>::iterator result;
  result = validPosList.begin();
  result = std::find(result, validPosList.end(), m->getFrom());
  //neni v seznamu
  if (result != validPosList.end() && *result != m->getFrom()) {
    return false;
  }
  

  // Test cile skoku figurky
  validPosList = m->getFrom()->getFigure()->getPlayableMoves();

  result = validPosList.begin();
  result = std::find(result, validPosList.end(), m->getTo());
  //neni v seznamu
  if (result != validPosList.end() && *result != m->getTo()) {
    return false;
  }


  m->getFrom()->getFigure()->move(m->getTo()); // provedeni tahu

  if (playingPlayer == WHITE) {
    
                playingPlayer = BLACK;
  } else {
    
                turnCount++;
                playingPlayer = WHITE;
  }



  movesDone->addMove(m);

  return true;
}



