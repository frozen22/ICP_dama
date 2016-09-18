/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Kralovna
 */
#ifndef Queen_H
#define Queen_H
#include <list>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */

////pomocne konstanty
//const int BLOCKED = 0;
//const int JUMP = 1;
//const int MOVE = 2;

/**
 * Kralovna.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */
class Queen : public Figure {
public:
  /**
   * Konstruktor figurky kralovny
   * @param p - pozice figurky
   * @param player - hrac, ktery figurku vlastni
   */
  Queen(Position *p, bool player);
  /**
   * Destruktor kralovny
   */
  ~Queen(){
  }
  /**
   * Ziska druh pohybu
   * @return kontantu podle druhu pohybu
   */
  int getTypeOfMoves();


  /**
   * Metoda vrati typ pohybu ktery muze figurka vykonat na pozici toPos. 
   * 
   * @return BLOCKED == nelze vykonat pohyb.
   *         JUMP == pohyb pri kterem je odstranena nepratelska figurka.
   *         MOVE == jen pohyb.
   */
  int isMoveable(Position *toPos);

  /**
   * Zjistuje pozice na hraci desce, kam mohou jednotlivi pesci
   * @return - seznam hratelnych tahu
   */
  list<Position*> getPlayableMoves();

  /**
   * Zpracovani tahu. Provadi se kontrola zda je cilova pozice prazdna,
   * je-li mezi pozici figurky a cilovou pozici figurka je provedena kontrola
   * teto figurku.
   * @param toPos Testovana pozice
   * @param takeList Seznam pro pozice, pri kterych je odstranena nepratelska figurka
   * @param moveList Seznam pro pozice, pri kterych neni odstranena nepratelska figurka
   */
  void addPos(Position *toPos, list<Position*> &takeList, list<Position*> &moveList);
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