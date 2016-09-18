/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   LocalPlayer
 */

#ifndef LocalPlayer_H
#define LocalPlayer_H

#include <stdio.h>      /* NULL */
#include <list>
#include <algorithm> 
#include <iostream>

#include "Player.h"
#include "Move.h"
#include "Position.h"
#include "Figure.h"
#include "Game.h"
#include "XMLGameSave.h"

using std::cin;
using std::cout;
using std::endl;
using std::list;

/**
 * Lokalni hrac. Tahy jsou nacitany z grafickeho rozhrani
 *
 * @author Frantisek Nemec (xnemec61)
 */
class LocalPlayer : public Player {
public:
  /**
   * Konstruktor Lokalniho hrace
   * @param c - barva hrace
   */
  LocalPlayer(bool c);
  /**
   * Destruktor Lokalniho hrace
   */
  ~LocalPlayer(){}
  /**
   * Ziskani tahu. Tah je ziskavan z grafickeho rozhrani.
   * @return Tah hrace
   */
  Move *getMove();

  /**
   * Ziska pozadavek na provedeni tahu od hrace 
   * @return - zadana pozice
   */
  Position* getHumanPos();

  /**
   * Metoda zjistuje, jestli je Pozice obsazena v tadanem seznamu
   * @param pList - prohledavany seznam
   * @param p - zkoumana pozice
   * @return - true/false
   */
  bool contains(list<Position *> pList, Position * p);


  
  /**
   * Fiktivni metoda pro odeslani tahu 
   * @param move
   */
  void remindPlayer(Move *move){
    if(move == NULL){}
  }
  
  /**
   * Vraci druh hrace
   * @return druh hrace
   */
  char getType(){
    return type;
  }
  
};
#endif
