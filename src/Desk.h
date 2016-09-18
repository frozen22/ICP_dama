/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Hraci deska
 */

#ifndef Desk_H
#define Desk_H

#include <iostream>  /*cout,cin,cerr, endl*/
#include <list>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */
#include <algorithm>

#include "Position.h"
#include "Figure.h"
#include "Queen.h"
#include "Pawn.h"
#include "Player.h"

using std::list;
using std::cout;
using std::endl;
using std::flush;

/**
 * Hraci deska.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */
class Desk {
protected:
  Position * **desk; // jednotliva pole hraci desky
  int dim; // rozmer desky

public:

  /**
   * Kontruktor hraci plochy
   * @d - velikost vytvarene plochy 
   */
  Desk(const int d) {
    // Kontrola zda neni dimenze zaporna nebude potreba. Hraci plocha bude
    // vzdy konstantni.
    Position *tmp;
    desk = new Position**[d];
    for (int i = 0; i < d; i++) {
      desk[i] = new Position*[d];
    }

    // naplneni pole pozicemi
    for (char col = 0; col < d; col++) { // indexovani podle char!
      for (int row = 0; row < d; row++) {
        tmp = new Position(this, (char) (col + 'a'), row + 1);
        desk[static_cast<int> (col)][row] = tmp;
      }
    }

    dim = d;
    initDesk();
  }
  /**
  * Destruktor desky, prochazi a maze postupne vsechny dimenze...
  */
  ~Desk() {
    for (char col = 0; col < dim; col++) { // indexovani podle char!
      for (int row = 0; row < dim; row++) {
        
        delete desk[static_cast<int> (col)][row]; //maze Position *
      }
    }
    for (int i = 0; i < dim; i++) {
      delete desk[i]; //maze Position **
    }
    
    delete desk; //maze Position ***
    
  }

  /**
   * Nalezeni pozic figurek s kterymi je mozno hrat. Pokud nektera figurka 
   * muze brat nepratelovu figurku jsou vraceny jen tahy kde tomu tak je.
   *
   * @param color Barva prave hrajiciho hrace
   * @return Seznam moznych pozic
   */
  list<Position*> getPlayablePositions(bool color);

  /**
   * Metoda vraci objekt pozice ze zadanych parametru. Pokud nejsou zadany
   * validni souradnice je vracem null.
   *
   * @param c Col (sloupec)
   * @param r Row (radek)
   * @return Objekt pozice pri uspechu jinak null
   */
  Position *getPositionAt(char c, int r);

  /**
   * Test zda je na zadane pozici figurka.
   *
   * @param p Pozadovana pozice
   * @return true/false
   */
  bool isEmpty(Position *p);

  /**
   * Vrati figurku na danych souradnicich. Pokud se na zadane pozici
   * nevyskytuje zadna figurka nebo jsou zadany souradnice mimo rozmery hraci
   * desky je vracen null.
   *
   * @param c Col (Sloupec)
   * @param r Row (radek)
   * @return Hledana figurka
   */
  Figure *getFigureAt(char c, int r);

  /**
   * Kontrola souradnic zda nejsou mimo hranice hraci desky.
   *
   * @param c Col testovane pozice (Sloupec)
   * @param r Row testovane pozice (Radek)
   * @return true/false
   */
  bool inBordersSimple(char c, int r);

  /**
   * Temer identicka metoda jako inBordersSimple. Pro lepsi manipulaci tato
   * metoda pozaduje objekt pozice misto souradnic.
   *
   * @param p Testovana pozice
   * @return true/false
   */
  bool inBorders(Position *p);

  /**
   * Zjisti jestli zadana pozice je obsazene v seznamu
   * @param pList - kontrolovany seznam
   * @param p - kontrolovana pozice
   * @return true/false
   */
  bool contains(list<Position *> pList, Position * p);
  
  /**
   * Odstraneni vsech figurek z hraci desky.
   */
  void clear();

  /**
   * Zjisteni velikosti hraci desky
   * @return velikost hraci plochy
   */
  int getDim();

  /**
   * Tisk hraci desky na stdout.
   */
  void print();


  /**
   * Pocatecni rozestaveni figurek.
   * @param d Hraci deska
   */

  /*final*/ void initDesk() {
    // nove instance figurek neni potreba ukladat, protoze jsou ulozeny 
    // pri jejich kontrukci do zadanych pozic       
    new Pawn(getPositionAt('a', 1), WHITE);
    new Pawn(getPositionAt('c', 1), WHITE);
    new Pawn(getPositionAt('e', 1), WHITE);
    new Pawn(getPositionAt('g', 1), WHITE);
    new Pawn(getPositionAt('b', 2), WHITE);
    new Pawn(getPositionAt('d', 2), WHITE);
    new Pawn(getPositionAt('f', 2), WHITE);
    new Pawn(getPositionAt('h', 2), WHITE);
    new Pawn(getPositionAt('a', 3), WHITE);
    new Pawn(getPositionAt('c', 3), WHITE);
    new Pawn(getPositionAt('e', 3), WHITE);
    new Pawn(getPositionAt('g', 3), WHITE);


    new Pawn(getPositionAt('b', 6), BLACK);
    new Pawn(getPositionAt('d', 6), BLACK);
    new Pawn(getPositionAt('f', 6), BLACK);
    new Pawn(getPositionAt('h', 6), BLACK);
    new Pawn(getPositionAt('a', 7), BLACK);
    new Pawn(getPositionAt('c', 7), BLACK);
    new Pawn(getPositionAt('e', 7), BLACK);
    new Pawn(getPositionAt('g', 7), BLACK);
    new Pawn(getPositionAt('b', 8), BLACK);
    new Pawn(getPositionAt('d', 8), BLACK);
    new Pawn(getPositionAt('f', 8), BLACK);
    new Pawn(getPositionAt('h', 8), BLACK);
  }
};

#endif