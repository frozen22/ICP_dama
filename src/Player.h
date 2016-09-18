/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Abstraktni trida hrace
 */

#ifndef Player_H
#define Player_H

#include "Move.h"

const bool WHITE = 1;
const bool BLACK = 0;

class Game; //forward deklarace

/**
 * Player.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */
class Player {
protected:
  Game *game; // hra ve ktere hrac particupuje
  bool color; // barva hrace
  bool wantSave; //slouzi pro signalizaci ulozeni hry
  char type; //druh hrace

public:

  /**
   * Inicializuje barvu hrace, vyuziva explicitniho konstruktoru vytvoreneho prekladacem
   * @param c  - barva hrace
   */
  void setPlayer(bool c);
  ~Player(){
  }
  /**
   * Pripojeni hrace ke hre
   * @param g Hra ke ktere je hrac pripojen.
   * @return this
   */
  Player *initPlayer(Game *g);

  /**
   * Ziskani tahu.
   * 
   * @return Tah hrace
   */
  virtual Move *getMove() = 0;

  /**
   * Odeslani zpravy o provedeni tahu online hraci. Metoda slouzi k odeslani 
   * tahu online hraci, ktery jej provede na sve desce. Implementace je 
   * obsazena jen u tridy onlinePlayer. U ostatnich typu hracu je metoda
   * prazdna.
   * 
   * Neni to nejlepsi reseni oznamovani tahy online hraci, ale nejjednoduseji
   * implementovatelne.
   * 
   * @param move Tah ktery chceme odeslat.
   */
  virtual void remindPlayer(Move *move) = 0;

  /**
   * Zjisteni, jestli chce hrac ulozit hru
   */
  bool wantToSave(){
    bool tmp = wantSave;
    wantSave = false;
    return tmp;
  }

  
  /**
   * Ziskani barvy hrace
   * @return barva hrace
   */
  bool getColor() {
    return color;
  }
  
  /**
   * Ziskani typu hrace
   */
  virtual char getType() = 0;
  
};
#endif
