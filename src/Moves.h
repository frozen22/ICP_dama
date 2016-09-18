/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Moves
 */

#ifndef Moves_H
#define Moves_H

#include <list>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */
#include <algorithm> 
#include <string>
#include <iostream>
#include <sstream>

#include "Move.h"
#include "Desk.h"


using std::list;
using std::string;
using std::cout;
using std::endl;
using std::flush;
using std::find_if;
using std::replace;

/**
 * Soubor obsahujici vyuzivane informace k ulozeni tahu hry. 
 * 
 * @author Frantisek Nemec
 */
class Moves {
protected:
  list<Move*> moveList; // Seznam tahu
  Desk *desk; // Deska na ktere byli tahy provedeny
  unsigned int moveNum; // identifikator soucasneho pohybu
  int maxMoveNum; // Pocet tahu 
  string movesInBasicNotation; //retezec reprezentujici zakladni notaci tahu

public:

  /**
   * Inicializacni konstruktor
   */
  Moves() {
    desk = NULL;
    moveNum = 0;
    maxMoveNum = 0;
    movesInBasicNotation = "";
  }

  /**
   * konstruktor nastavujici seznam tahu k instanci hraci desky
   */
  Moves(Desk *d) {
    desk = d;
    moveNum = 0;
    maxMoveNum = 0;
    movesInBasicNotation = "";
  }
  ~Moves(){
  }
  
  /**
   * Prirazeni desky k seznamu
   * @param d - prirazovana deska
   */
  void setDesk(Desk *d) {
    desk = d;
  }

  /**
   * Ziskani poradoveho cisla aktualniho tahu
   * @return - cisla aktualniho tahu
   */
  int getActualMoveNum() {
    return moveNum;
  }

  /**
   * Ziskani maximalniho poctu tahu
   * @return - maximalni pocet tahu
   */
  int getMaxMoveNum() {
    return maxMoveNum;
  }

  /**
   * Ziskani zakladni notace seznamu tahu
   * @return - retezec zakladni notace
   */
  string getMovesInBasicNotation() {
    return movesInBasicNotation;
  }

  /**
   * Naplneni seznamu z retezce tahu v zakladni notaci.
   * 
   * @param str Retezec ktery obsahuje zaznam v zakladni notaci.
   */
  void loadWithBasic(string str);

  /**
   * Nastaveni citace na nulu. Ziskavani tahu bude od prvniho tahu.
   */
  void resetNum() {
    moveNum = 0;
  }

  /**
   * Pridani tahu do seznamu.
   * 
   * @param move Pridany hrat
   */
  void addMove(Move *move) {
    moveList.push_back(move);
  }

  /**
   * Ziskani tahu pred posledne ziskanym.
   * 
   * @return Predposledne ziskany tah. Null - pokud jsme na zacatku seznamu.
   */
  Move *getPrevMove();

  /**
   * Ziskani nasledujiciho tahu.
   * 
   * @return Dalsi tah v seznamu. Null - pokud jsme na konci seznamu
   */
  Move *getNextMove();

  /**
   * Funkce nahradi vsechny vyskyty retezce target za ratezec replacement
   * @param str - retezec v nemz se nahrazuje
   * @param target - nahrazovany vzor
   * @param replacement - nahrazeny vzor
   */
  void replaceAll(string *str, string target, string replacement);
  
  /**
   * Metoda pro prevod tahu do retezce v zakladni notaci
   */
  void movesToBasicString();

};

#endif