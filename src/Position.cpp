/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Pozice na hraci desce
 */



#include "Position.h"

#include "Figure.h"
#include "Desk.h"

/**
 * Pozice.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */


Position::Position() {
  col = 0;
  row = 0;
  desk = NULL;
  fig = NULL;
}

Position::Position(const Desk *d, char c, int r) {
  col = c;
  row = r;
  desk = const_cast<Desk *> (d);
  fig = NULL;
}

/**
 * Metoda vraci pozici posunutou dC sloupcu a dR radku od this pozice
 * 
 * @param dC Rozdil sloupcu 
 * @param dR Rozdil radku
 * @return Posunuta pozice
 */
Position *Position::nextPosition(int dC, int dR) {
  char newC;
  int newR;

  newC = (char) (dC + col);
  newR = row + dR;

  if (desk->inBorders(desk->getPositionAt(newC, newR))) {
    return desk->getPositionAt(newC, newR);
  } else {
    return NULL;
  }
}

/**
 * Vlozeni figurky na this pozici. Pokud se jiz na pozici nejaka figurka
 * vyskytuje je vracena.
 *
 * @param f Vkladana figurka
 * @return Jiz vyskytujici se figurka
 */
Figure *Position::putFigure(Figure *f) { //? zde mozna nebude nutne vracet figurku kterou vracim
  Figure *retFig = fig;
  fig = f;
  f->pos = this;
  return retFig;
}

/**
 * Odstraneni figurky na this pozici.
 *
 * @return Odstranena figurka
 */
Figure *Position::removeFigure() {
  Figure *retFig = fig;
  fig = NULL;
  return retFig;
}

/**
 * Zjisteni zda mezi pozici this a parametrem p lezi figurka. Pokud se zadna
 * figurka nenachazi je vracena figurka na pozici this. Kdyz je nalezeno
 * vice figurek je vracen null.
 *
 * @param p Hranicni pozice
 * @return Vnitrni figurka
 */
Figure *Position::figBetween(Position *p) {
  int colEnd;
  int rowDiff, colDiff;
  int c, r;
  bool thereIs = false;
  Figure *midFig = NULL;


  // Lezi pozice na stejne diagonale?
  if (abs(abs(p->getRow()) - abs(row)) != abs(abs(p->getCol()) - abs(col))) {
    return NULL;
  }

  // zjisteni smeru kontroly
  rowDiff = (p->getRow() - row) < 0 ? -1 : 1;
  colDiff = (p->getCol() - col) < 0 ? -1 : 1;

  colEnd = p->getCol();

  c = col + colDiff;
  r = row + rowDiff;

  // samotna kontrola vsech pozic mezi zadanymi pozicemi
  while (c != colEnd) {
    if (desk->getFigureAt((char) (c), r) != NULL) {
      if (thereIs == true) { // vyskyt vice jak jedne figurky
        return NULL;
      }
      midFig = desk->getFigureAt((char) (c), r);
      thereIs = true;
    }

    c += colDiff;
    r += rowDiff;
  }

  if (thereIs == true) {
    return midFig; // jedna figurka se vyskytuje
  } else { // zadna figurka nebyla nalezena
    return fig;
  }
}

/**
 * Test zda na teto pozici neni figurka.
 * 
 * @return true/false
 */
bool Position::isEmpty() {
  if (fig == NULL) {
    return true;
  } else {
    return false;
  }
}

string Position::toString() {
  string tmp;
  ostringstream str;
  str << col << row;
  tmp = str.str();
  return tmp;
}

Figure *Position::getFigure() {
  return fig;
}

Desk *Position::getDesk() {
  return desk;
}

char Position::getCol() {
  return col;
}

int Position::getRow() {
  return row;
}




