/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Pesec
 */
#include <list>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */
#include <iostream>

#include "Pawn.h"

using std::list;
using std::cout;
using std::endl;

/**
 * Pesec.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */
Pawn::Pawn(Position *p, bool player) {
  setFigure(p, player);
}

list<Position*> Pawn::getPlayableMoves() {
  list<Position*> posList; //= new ArrayList<>(); -- empty list???
  Position *toPos; // pomocna promena 
  Figure *midFig; // pomocna promena 
  int dR, ddR; // pomocne promene pro ulozeny rozdilu radku
  bool moveSet = false; // priznak zda byl nalezen tah

  // urceni smeru kontroly tahu
  if (color == WHITE) {
    dR = 1;
    ddR = 2;
  } else {
    dR = -1;
    ddR = -2;
  }


  // Tahy ktere lze provest jen pri odstraneni nepratelske figurky
  if ((toPos = pos->nextPosition(2, ddR)) != NULL && toPos->isEmpty()) {
    midFig = pos->figBetween(toPos); // je zde nepratelska figurka?
    if (midFig != this && color != midFig->getColor()) {
      posList.push_back(toPos); //  -- kam vklada add ???
    }
  }
  if ((toPos = pos->nextPosition(-2, ddR)) != NULL && toPos->isEmpty()) {
    midFig = pos->figBetween(toPos); // je zde nepratelska figurka?
    if (midFig != this && color != midFig->getColor()) {
      posList.push_back(toPos);
    }
  }

  if (!posList.empty()) {
    return posList;
  }



  // Tahy pri kterych nelze odstranit figurku
  if ((toPos = pos->nextPosition(1, dR)) != NULL && toPos->isEmpty()) {
    posList.push_back(toPos);
    moveSet = true;
  }
  if ((toPos = pos->nextPosition(-1, dR)) != NULL && toPos->isEmpty()) {
    posList.push_back(toPos);
    moveSet = true;
  }



  if (moveSet) {
    return posList;
  } else { // zadny tah nebyl nalezen
    posList.clear();
    return posList;
  }
}

int Pawn::getTypeOfMoves() {
  Position *toPos; // pomocna promena 
  Figure *midFig; // pomocna promena 
  int dR, ddR; // pomocne promene pro ulozeny rozdilu radku

  // urceni smeru kontroly tahu
  if (color == WHITE) {
    dR = 1;
    ddR = 2;
  } else {
    dR = -1;
    ddR = -2;
  }

  // Tahy ktere lze provest jen pri odstraneni nepratelske figurky
  if ((toPos = pos->nextPosition(2, ddR)) != NULL && toPos->isEmpty()) {
    midFig = pos->figBetween(toPos); // je zde nepratelska figurka?
    if (midFig != this && color != midFig->getColor()) {
      return 1;
    }
  }
  if ((toPos = pos->nextPosition(-2, ddR)) != NULL && toPos->isEmpty()) {
    midFig = pos->figBetween(toPos); // je zde nepratelska figurka?
    if (midFig != this && color != midFig->getColor()) {
      return 1;
    }
  }

  // Tahy pri kterych nelze odstranit figurku
  if ((toPos = pos->nextPosition(1, dR)) != NULL && toPos->isEmpty()) {
    return 2;
  }
  if ((toPos = pos->nextPosition(-1, dR)) != NULL && toPos->isEmpty()) {
    return 2;
  }

  return 0;
}

bool Pawn::canMove(Position *p) {
  int colDiff = p->getCol() - pos->getCol();
  int rowDiff = p->getRow() - pos->getRow();

  // posunuti o jedno dopredu diagonalne. White mohou "nahoru" a Black "dolu"
  if (abs(colDiff) == 1 && ((color == WHITE && rowDiff == 1) || (color == BLACK && rowDiff == -1))) {
    return true;
  }

  // skok o dva, ale jen za predpokladu ze je mezi skoky nepratelska figurka
  if (abs(colDiff) == 2 && ((color == WHITE && rowDiff == 2) || (color == BLACK && rowDiff == -2))) {

    Figure *midFig = pos->figBetween(p);
    // Figurka neni tedy nelze provest skok o dva || figurky jsou stejneho hrace
    if (midFig == this || color == midFig->getColor()) {
      return false;
    }

    return true;
  }

  return false;
}

bool Pawn::isInstanceOf() {
  return PAWN;
};

