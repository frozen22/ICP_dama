/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Figurka
 */

#include <list>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */


#include "Figure.h"
#include "Queen.h"
#include "Pawn.h"
#include "Desk.h"

using std::list;


/**
 * Figurka.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */

/**
 * Presunuti figurky na pozici p. Obsahuje kontrolu hranic hraci desky, zda
 * pozice neni jiz obsazena a jestli figurka muze provest dany tah. Zaroven
 * neni povolen tah na stejne pole (tento fakt je kontrolovan v metodach
 * canMove jednotlivych figurek).
 *
 * @param p Cilova pozice
 * @return Bool hodnota zda je tah legalni a provedl se
 */
bool Figure::move(Position *p) {
  Figure *midFig;

  //        if (p != NULL && p->desk->inBorders(p)&& p->desk->isEmpty(p) && canMove(p)) {
  if (p != NULL && p->desk->isEmpty(p) && canMove(p)) {

    // Odstraneni figurky mezi pozicemi skoku

    if ((midFig = pos->figBetween(p)) != NULL && midFig != this) {
      midFig->removeFigure();
    }

    // presun figurky
    this->removeFigure();
    p->putFigure(this);
    pos = p;

    // povyseni Pesce na Kralovnu
    if (this->isInstanceOf() == PAWN && ((color == WHITE && p->row == p->desk->getDim()) || (color == BLACK && p->row == 1))) {
      promoteRook();
    }

    return true;
  } else {

    return false;
  }
}

/**
 * Povyseni pesce na kralovnu. Tato metoda je volana z metodu move pokud
 * jsou splnena pravidla pro povyseni.
 */
void Figure::promoteRook() {
  removeFigure();
  pos->putFigure(new Queen(pos, color));
}

/**
 * Odstraneni figurky.
 * @return odstranena figurka
 */
Figure *Figure::removeFigure() {
  //        delete &pos->fig;
  pos->fig = NULL;

  return this;
}

/**
 * Ziska barvu figurky
 */
char Figure::getColor() {
  return color;
}

/**
 * Ziska pozici figurky
 */
Position *Figure::getPosition() {
  return pos;
}



