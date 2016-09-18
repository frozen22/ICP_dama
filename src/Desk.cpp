/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Hraci deska
 */




#include "Desk.h"
/**
 * Hraci deska.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */

/**
 * Nalezeni pozic figurek s kterymi je mozno hrat.
 *
 * @param color Barva prave hrajiciho hrace
 * @return Seznam moznych pozic
 */
list<Position*> Desk::getPlayablePositions(bool color) {
  list<Position*> takePosList; // = new ArrayList<>();  -- mel by byt dynamicky list
  list<Position*> movePosList; // = new ArrayList<>();
  int retCode;
  Figure *auxFig;

  // pruchod pres vsechny pole hraci desky (Nalezeni figurek)
  for (char col = 'a'; col < dim + 'a'; col++) {
    for (int row = 1; row <= dim; row++) {

      // Nachazi se na teto pozici figurka? a zadane barvy?
      if ((auxFig = getFigureAt(col, row)) != NULL && auxFig->color == color) {

        // Ziskani moznych tahu figurky
        retCode = auxFig->getTypeOfMoves();

        if (retCode == BLOCKED) // figurka nemuze tahnout
          continue;
        else if (retCode == JUMP) { // figurka muze preskocit nepritele
          takePosList.push_back(auxFig->pos);
        } else { // figurka nemuze odstrani nepritelovu figurku MOVE
          movePosList.push_back(auxFig->pos);
        }
      }
    }
  }


  if (takePosList.empty()) { // muze nektera figurka odstranit nepritele?
    return movePosList;

  } else {
    return takePosList;

  }
}

/**
 * Metoda vraci objekt pozice ze zadanych parametru. Pokud nejsou zadany
 * validni souradnice je vracem null.
 *
 * @param c Col (sloupec)
 * @param r Row (radek)
 * @return Objekt pozice pri uspechu jinak null
 */
Position *Desk::getPositionAt(char c, int r) {
  if (inBordersSimple(c, r)) {
    return desk[c - 'a'][r - 1];
  } else {
    return NULL;
  }
}

/**
 * Test zda je na zadane pozici figurka.
 *
 * @param p Pozadovana pozice
 * @return true/false
 */
bool Desk::isEmpty(Position *p) {
  if (desk[p->getCol() - 'a'][p->getRow() - 1]->getFigure() == NULL) {
    return true;
  } else {
    return false;
  }
}

/**
 * Vrati figurku na danych souradnicich. Pokud se na zadane pozici
 * nevyskytuje zadna figurka nebo jsou zadany souradnice mimo rozmery hraci
 * desky je vracen null.
 *
 * @param c Col (Sloupec)
 * @param r Row (radek)
 * @return Hledana figurka
 */
Figure *Desk::getFigureAt(char c, int r) {

  if (inBordersSimple(c, r)) {
    return (desk[c - 'a'][r - 1])->getFigure();
  } else {
    return NULL;
  }
}

/**
 * Kontrola souradnic zda nejsou mimo hranice hraci desky.
 *
 * @param c Col testovane pozice (Sloupec)
 * @param r Row testovane pozice (Radek)
 * @return true/false
 */
bool Desk::inBordersSimple(char c, int r) {
  c -= '`'; // zarovnani c
  if (r < 1 || r > dim || c < 1 || c > dim) {
    return false;
  } else {

    return true;
  }

}

/**
 * Temer identicka metoda jako inBordersSimple. Pro lepsi manipulaci tato
 * metoda pozaduje objekt pozice misto souradnic.
 *
 * @param p Testovana pozice
 * @return true/false
 */
bool Desk::inBorders(Position *p) {
  if (p == NULL) {
    return false;
  }
  int r = p->getRow();
  char c = p->getCol();
  return inBordersSimple(c, r);
}

/**
 * Odstraneni vsech figurek z hraci desky.
 */
void Desk::clear() {
  for (char col = 0; col < dim; col++) {
    for (int row = 0; row < dim; row++) {
      desk[static_cast<int> (col)][row]->removeFigure();
    }
  }
}

int Desk::getDim() {
  return dim;
}


bool Desk::contains(list<Position *> pList, Position * p) {
  list<Position *>::iterator result;
  result = pList.begin();
  result = std::find(result, pList.end(), p);
  if (result != pList.end()) {
    return true;
  }
  return false;
}

void Desk::print() {
  // naplneni pole pozicemi
  Figure *fig;
  char figType = '-';


  cout << "+-----------------+" << endl;
  cout << "  A B C D E F G H  " << endl;
  for (int row = (dim - 1); row >= 0; row--) {
    cout << (row + 1) << " " << flush;
    for (char col = 0; col < dim; col++) {
      fig = desk[static_cast<int> (col)][row]->getFigure();

      if (fig == NULL) {
        figType = '-';
      }        //pesec
      else if (fig->isInstanceOf() == PAWN) {
        if (fig->getColor() == WHITE) {
          figType = 'r';
        } else {
          figType = 'R';
        }
      }        //kralovna
      else if (fig->isInstanceOf() == QUEEN) {
        if (fig->getColor() == WHITE) {
          figType = 'q';
        } else {
          figType = 'Q';
        }
      }

      cout << figType << flush;
      cout << " " << flush;
    }
    cout << row + 1 << flush;
    if (row == 0) {
      cout << "  For end type \"exit\"" << flush;
    } else if (row == 2) {
      cout << "  Q - black queen" << flush;
    } else if (row == 3) {
      cout << "  q - white queen" << flush;
    } else if (row == 4) {
      cout << "  R - black pawn" << flush;
    } else if (row == 5) {
      cout << "  r - white pawn" << flush;
    } else if (row == 7) {
      cout << "  Pr. format zadani tahu: a3 b6 c8 a6 g8 h1" << flush;
    }

    cout << endl;


  }
  cout << "  A B C D E F G H  " << endl;
  cout << "+-----------------+" << flush;
}


