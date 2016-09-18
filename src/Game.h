/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Game
 */
#ifndef Game_H
#define Game_H
#include <list>
#include <stdio.h>      /* NULL */
#include <cstdlib> 
#include <iostream>


#include "Main.h"
#include "Desk.h"
#include "Pawn.h"
#include "Queen.h"

#include "Player.h"
#include "Moves.h"
#include "Move.h"
#include "RandomAI.h"
#include "LocalPlayer.h"
#include "XMLGameSave.h"

class Player;

using std::list;
using std::cout;
using std::endl;
using std::string;
using std::cin;


/**
 * Game.
 *
 * @author Frantisek Nemec (xnemec61)
 */
class Game {
  protected:
    Desk *desk;         // hraci plocha  
    Player *player1;    // hraci hry
    Player *player2;
    Moves *movesDone;   // pouziva se pri ulozeni hry do XML
    bool playingPlayer; // hrac na tahu
    int turnCount;      // cislo tahu
    
  public:
    
    /**
     * Konstruktor hry
     * @param p1 - prvni hrac (local, AI, online ?)
     * @param p2 - druhy hrac
     */
    Game(Player *p1, Player *p2);
    
    /**
     * Destruktor Game
     */
    ~Game(){
      delete desk;
      delete movesDone;
      delete player1;  //vytvari se zaroven s game
      delete player2;
    }
    
    /**
     * Zjisteni hrace na tahu
     * @return hrac
     */
    bool getPlayingPlayer(){
        return playingPlayer;
    }
    
    /**
     * Ziskava seznam vykonanych tahu
     * @return seznam tahu  - Moves
     */
    Moves *getMovesDone() {
        return movesDone;
    }
    /**
     * Vraci desku aktualni hry
     * @return deska
     */
    Desk *getDesk(){
        return desk;
    }
    
    /**
     * Odstartovani hry.
     * 
     * @return Barva viteze.
     */
    char start() ;

    /**
     * Vykonani tahu. Vykonani tahu obsahuje: samotne vykonani tahu, prekresleni
     * grafickeho rozhrani a tisk tahu do tiskove pole u hraci desky
     * 
     * @param m Konany tah.
     * @return True - tah byl uspesne proveden. False - nevalidni tah
     */
    bool makeMove(Move *m);
    
    /**
     * Provedeni zadanych tahu. Tato metoda je pouzita pri dokoncovani rozehrane
     * hry, kdy je nutne provest urcite tahy, jeste pred zacatkem samotne hry.
     * 
     * @param movesToDo 
     * @return True - vsechny tahy jsou validni. False - nektery tah nelze provest
     */
    bool makeMoves(Moves *movesToDo){
        Move *move;
        
        // provedeni tahu
        while ((move = movesToDo->getNextMove()) != NULL) {
            if (!makeMove(move)) { 
                return false; // tah nelze provest
            }
        }
        
        return true;
    } 
    /**
     * Pouzito pri prehravani hry
     * @return 
     */
    char replayNextMove();
    
    /**
     * Zjisti, jestli zadana pozice je v seznamu
     * @param pList - prohledavany seznam
     * @param p - vyhledavana pozice
     * @return true/false
     */
    bool contains(list<Position *> pList, Position * p);
    
    /**
     * Vrati ukazatel na prvniho hrace
     * @return - odkaz na prvniho hrace
     */
    Player *getFirstPlayer(){
      return player1;
    }

    /**
     * Vrati ukazatel na druheho hrace
     * @return - odkaz na druheho hrace
     */
    Player *getSecondPlayer(){
      return player2;
    }
    
};
#endif