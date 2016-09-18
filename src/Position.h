/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Pozice na hraci desce
 */
#ifndef Position_H
#define Position_H
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */
#include <iostream>
#include <sstream>

using std::string;
using std::ostringstream;
//#include "Figure.h"
class Desk;
class Figure;

/**
 * Pozice.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */
class Position {
protected:
  char col; //sloupce pozice na sachovnici
  int row; //radek pozice na sachovnici
  Desk *desk; //deska, na ktere se pozice nachazi
  Figure *fig; //figurka, ktera se na pozici nachazi

  friend class Figure;

public:
  /**
   * Konstruktor Pozice - inicializacni
   */
  Position();
  /**
   * Konstruktor Pozice
   * @param d - deska
   * @param c - pismeno pozice
   * @param r - cislo pozice
   */
  Position(const Desk *d, char c, int r);
  /**
   * Destruktor pozice - nic se nevytvari, nic s nemaze
   */
  ~Position(){}
  /**
   * Metoda vraci pozici posunutou dC sloupcu a dR radku od this pozice
   * 
   * @param dC Rozdil sloupcu 
   * @param dR Rozdil radku
   * @return Posunuta pozice
   */
  Position *nextPosition(int dC, int dR);
  
  

  /**
   * Vlozeni figurky na this pozici. Pokud se jiz na pozici nejaka figurka
   * vyskytuje je vracena.
   *
   * @param f Vkladana figurka
   * @return Jiz vyskytujici se figurka
   */
  Figure *putFigure(Figure *f);

  /**
   * Odstraneni figurky na this pozici.
   *
   * @return Odstranena figurka
   */
  Figure *removeFigure();

  /**
   * Zjisteni zda mezi pozici this a parametrem p lezi figurka. Pokud se zadna
   * figurka nenachazi je vracena figurka na pozici this. Kdyz je nalezeno
   * vice figurek je vracen null.
   *
   * @param p Hranicni pozice
   * @return Vnitrni figurka
   */
  Figure *figBetween(Position *p);

  /**
   * Test zda na teto pozici neni figurka.
   * 
   * @return true/false
   */
  bool isEmpty();
  /**
   * Vytvari retezec z objektu Position pro vypis
   * 
   * @return vysledny retezec
   */
  string toString();

  /**
   * Ziska figurku na pozici
   * @return figurka
   */
  Figure *getFigure();
  /**
   * Ziska desku, na ktere je Pozice
   * @return deska
   */
  Desk *getDesk();

  /**
   * Zjisti sloupec Pozice
   * @return pismeno sloupce
   */
  char getCol();

  /**
   * Zjisti radek Pozice
   * @return cislici Pozice
   */
  int getRow();


};

#endif