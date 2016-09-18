/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   RandomAI
 */

#ifndef RandomAI_H
#define RandomAI_H

#include <list>
#include <stdio.h>      /* NULL */
#include <cstdlib> 
#include <iostream>
#include <time.h>
#include <unistd.h>

#include "Game.h"
#include "Player.h"
#include "Move.h"

class Player;

using std::list;

/**
 * Umela inteligence s nahodnym vyberem tahu.
 *
 * @author Frantisek Nemec (xnemec61)
 */
class RandomAI : public Player {
public:
  /**
   * Konsstruktor Umele inteligence
   * @param c - barva
   */
  RandomAI(bool c);
  ~RandomAI(){}
  /**
   * Ziskani tahu.
   * 
   * @return Tah hrace
   */
  Move *getMove();
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