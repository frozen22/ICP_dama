/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Pesec
 */
#ifndef Pawn_H
#define Pawn_H
#include <list>

#include "Figure.h"
#include "Player.h"
using std::list;

/**
 * Pesec.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */
class Pawn : public Figure {
  //nasleduji metody
public:
  /**
   * Konstruktor figurky pesce
   * @param p - pozice figurky
   * @param player - hrac, ktery figurku vlastni
   */
  Pawn(Position *p, bool player);
  /**
   * Destruktor pesce
   */
  ~Pawn(){
  }
  
  /**
   * Zjistuje pozice na hraci desce, kam mohou jednotlivi pesci
   * @return - seznam hratelnych tahu
   */
  list<Position*> getPlayableMoves();

  /**
   * Ziska druh pohybu
   * @return kontantu podle druhu pohybu
   */
  int getTypeOfMoves();
  /**
   * Test na povoleni pohybu
   * @param p - pozice, na kterou se ptame
   * @return ANO/NE
   */
  bool canMove(Position *p);
  /**
   * Zjisti instanci figurky
   */
  bool isInstanceOf();
};
#endif