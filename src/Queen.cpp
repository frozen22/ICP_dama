/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Kralovna
 */



#include "Figure.h"
#include "Queen.h"
#include <iostream>

using std::list;
using std::cout;
using std::endl;

/**
 * Kralovna.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */

Queen::Queen(Position *p, bool player) {
  setFigure(p, player);
}

int Queen::getTypeOfMoves() {
  Position *toPos; // pomocna promena 
  int retCode;
  bool moveable = false;


  // pohyb po diagonale smerem k pravemu hornimu rohu
  toPos = pos;
  while ((toPos = toPos->nextPosition(1, 1)) != NULL) {
    if ((retCode = isMoveable(toPos)) == BLOCKED) {
      continue;
    } else if (retCode == JUMP) {
      return JUMP;
    } else {
      moveable = true;
    } // retCode == MOVE
  }

  // pohyb po diagonale smerem k levemu hornimu rohu
  toPos = pos;
  while ((toPos = toPos->nextPosition(-1, 1)) != NULL) {
    if ((retCode = isMoveable(toPos)) == BLOCKED) {
      continue;
    } else if (retCode == JUMP) {
      return JUMP;
    } else {
      moveable = true;
    } // retCode == MOVE        
  }

  // pohyb po diagonale smerem k pravemu dolnimu rohu
  toPos = pos;
  while ((toPos = toPos->nextPosition(1, -1)) != NULL) {
    if ((retCode = isMoveable(toPos)) == BLOCKED) {
      continue;
    } else if (retCode == JUMP) {
      return JUMP;
    } else {
      moveable = true;
    } // retCode == MOVE       

  }

  // pohyb po diagonale smerem k levemu dolnimu rohu
  toPos = pos;
  while ((toPos = toPos->nextPosition(-1, -1)) != NULL) {
    if ((retCode = isMoveable(toPos)) == BLOCKED) {
      continue;
    } else if (retCode == JUMP) {
      return JUMP;
    } else {
      moveable = true;
    } // retCode == MOVE
  }

  if (moveable) {
    return MOVE;
  } else {
    return BLOCKED;
  }
}

/**
 * Metoda vrati typ pohybu ktery muze figurka vykonat na pozici toPos. 
 * 
 * @return BLOCKED == nelze vykonat pohyb.
 *         JUMP == pohyb pri kterem je odstranena nepratelska figurka.
 *         MOVE == jen pohyb.
 */
int Queen::isMoveable(Position *toPos) {
  Figure *midFig;

  if (toPos->isEmpty()) {
    midFig = pos->figBetween(toPos); // zjisteni figurky mezi pozicemi

    if (midFig == this) { // Zadna figurka neni mezi skokem
      return MOVE;
    } else if (midFig != NULL && midFig->getColor() != color) {
      // Byla nalezena jen jedna figurka a nepratelske barvy
      return JUMP;
    }
  }

  return BLOCKED;
}

list<Position*> Queen::getPlayableMoves() {
  list<Position*> posTakeList; //new ArrayList<>(); -- dynamic empty list???
  list<Position*> posMoveList; //new ArrayList<>();
  Position *toPos; // pomocna promena 
  // pohyb po diagonale smerem k pravemu hornimu rohu
  toPos = pos;
  while ((toPos = toPos->nextPosition(1, 1)) != NULL) {
    addPos(toPos, posTakeList, posMoveList);
  }

  // pohyb po diagonale smerem k levemu hornimu rohu
  toPos = pos;
  while ((toPos = toPos->nextPosition(-1, 1)) != NULL) {
    addPos(toPos, posTakeList, posMoveList);
  }

  // pohyb po diagonale smerem k pravemu dolnimu rohu
  toPos = pos;
  while ((toPos = toPos->nextPosition(1, -1)) != NULL) {
    addPos(toPos, posTakeList, posMoveList);
  }

  // pohyb po diagonale smerem k levemu dolnimu rohu
  toPos = pos;
  while ((toPos = toPos->nextPosition(-1, -1)) != NULL) {
    addPos(toPos, posTakeList, posMoveList);
  }

  if (!posTakeList.empty()) {
    return posTakeList;
  } else {
    if (!posMoveList.empty()) {
      return posMoveList;
    } else {// zadny tah nebyl nalezen
      posMoveList.clear();
      return posMoveList; //.empty() == 0 !
    }
  }
}

/**
 * Zpracovani tahu. Provadi se kontrola zda je cilova pozice prazdna,
 * je-li mezi pozici figurky a cilovou pozici figurka je provedena kontrola
 * teto figurku.
 * @param toPos Testovana pozice
 * @param takeList Seznam pro pozice, pri kterych je odstranena nepratelska figurka
 * @param moveList Seznam pro pozice, pri kterych neni odstranena nepratelska figurka
 */
void Queen::addPos(Position *toPos, list<Position*> &takeList, list<Position*> &moveList) {
  Figure *midFig;
  if (toPos->isEmpty()) {
    midFig = pos->figBetween(toPos); // zjisteni figurky mezi pozicemi

    if (midFig == this) { // Zadna figurka neni mezi skokem
      moveList.push_back(toPos);
    } else if (midFig != NULL && midFig->getColor() != color) {
      // Byla nalezena jen jedna figurka a nepratelske barvy
      takeList.push_back(toPos);
    }
  }
}

bool Queen::canMove(Position *p) {
  // Kontrola zda pozice figurky a p lezi na stejne diagonale.
  // Pohyb na stejnou pozici je zakazan.
  if (abs(p->getRow() - pos->getRow()) != abs(p->getCol() - pos->getCol())
          || abs(p->getRow() - pos->getRow()) == 0) {
    return false;
  }

  Figure *midFig = pos->figBetween(p);

  // Mezi pozicemi skoku je vice jak jedna figurka
  if (midFig == NULL) {
    return false;
  }

  // Pokud je vnitrni figurka nalezena nesmi byt stejneho
  if (midFig != this && color == midFig->getColor()) {
    return false;
  }

  return true;
}

bool Queen::isInstanceOf() {
  return QUEEN;
};

