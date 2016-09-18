/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   ReplayGame
 */

#ifndef REPLAYGAME_H
#define	REPLAYGAME_H




#include <iostream>
#include "Game.h"

#include <stdlib.h>
#include <list>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::list;
using std::find;

const int PLAYABLE = 0;
const int END_OF_LIST = 1;
const int INVALID = 2;

/**
 * Prehravaci hra. Tato trida obsahuje metody urcene jen k prehravani ulozene
 * hry.
 *
 * @author Frantisek Nemec (xnemec61)
 */
class ReplayGame {
protected:
  Moves *moves; // ulozene tahu
  Desk *desk; // deska na ktere je prehravani proveden

  bool autoPlaySign; // automaticke prehravani
  int autoPlayInter; // interval tahu v automatickem prehravani
  char playingPlayer; // prave hrajici hrac

public:

  /**
   * Konstrukce prehravajici hry.
   * 
   * @param movesString Tahy v zakladni notaci.
   */
  ReplayGame(string movesString) {
    desk = new Desk(8);
    autoPlaySign = false;
    autoPlayInter = 0;
    playingPlayer = WHITE;
    moves = new Moves(desk);
    moves->loadWithBasic(movesString);
  }
  ~ReplayGame(){
   delete moves; 
  }
  /**
   * Zjisti, zda je zapnute automaticke prehravani
   * @return true/false
   */
  bool autoPlaying() {
    return autoPlaySign;
  }

  /**
   * Pozastaveni automatickeho prehravani.
   */
  void stopAutoPlay() {
    autoPlaySign = false;
  }

  /**
   * Vykonani tahu. Vykonani tahu obsahuje: samotne vykonani tahu, prekresleni
   * grafickeho rozhrani a tisk tahu do tiskove pole u hraci desky
   * @param m Konany tah.
   * @param interval Interval mezi jednolivymi tahy (ms).
   */
  bool makeMove(Move *m);


  /**
   * Skok na zadany tah.
   * 
   * @param num Cislo pozadovaneho tahu
   */
  void goToMove(int num, int interval);

  /**
   * Tah zpet.
   */
  Move *replayUndoMove();


  /**
   * Prehrani nasledujici tahy.
   *
   * @return PLAYABLE - tah lze provest, END_OF_LIST - jsme na konci v seznamu tahu
   *         INVALID - tah nelze provest
   */
  int replayNextMove();

  /**
   * Vraci aktualni stav desky
   * @return deska
   */
  Desk *getDesk() {
    return desk;
  }
  
   /**
   * Vraci aktualni stav moves
   * @return deska
   */
  Moves *getMoves() {
    return moves;
  }

  /**
   * Vymena prave hrajicich hracu.
   */
  void switchPlayingPlayer() {
    //slo by to i takto: playingPlayer = !playingPlayer;
    if (playingPlayer == WHITE) {
      playingPlayer = BLACK;
    } else {
      playingPlayer = WHITE;
    }
  }


};


#endif	/* REPLAYGAME_H */

