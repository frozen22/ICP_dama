/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Move
 */


#include "Move.h"

/**
 * Tah figurky. 
 * 
 * @author Frantisek Nemec
 */

Move::Move() {
  fromPos = NULL;
  toPos = NULL;
  takenPos = NULL;
  takenFig = NULL;
}

Move::Move(Position *fromP, Position *toP) {
  fromPos = fromP;
  toPos = toP;
  takenPos = NULL;
  takenFig = NULL;

}

Move::Move(Position *fromP, Position *toP, Position *takenP) {
  fromPos = fromP;
  toPos = toP;
  takenPos = takenP;
  takenFig = NULL;

}

void Move::setFrom(Position *p) {
  fromPos = p;
}

void Move::setTo(Position *p) {
  toPos = p;
}

void Move::setTaken(Position *p) {
  takenPos = p;
}

void Move::setTakenFig(Figure *f) {
  takenFig = f;
}

Position *Move::getFrom() {
  return fromPos;
}

Position *Move::getTo() {
  return toPos;
}

Position *Move::getTaken() {
  return takenPos;
}

Figure *Move::getTakenFig() {
  return takenFig;
}

/**
 * Prevod tahu do zakladni notace.
 * @return Retezec v zakladni notaci.
 */
string Move::moveToString() {
  string s = fromPos->toString();
  if (takenPos != NULL) {
    s += "x";
  } else {
    s += "-";
  }
  s += toPos->toString();

  return s;
}


