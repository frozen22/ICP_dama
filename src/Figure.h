/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Figurka
 */

#ifndef Figure_H
#define Figure_H

#include <list>

#include "Position.h"

const bool PAWN = 0;
const bool QUEEN = 1;

//pomocne konstanty
const int BLOCKED = 0;
const int JUMP = 1;
const int MOVE = 2;


using std::list;
/**
 * Figurka.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */
//virtual
class Figure {

  protected:
     Position *pos;
     bool color; // 'w' == white, 'b' == black
     
     friend class Desk; 
     friend class Position;

  public: 
    /**
     * Konfigurace figurky(Konstruktor)
     * @param p - pozice, kde se figurka umisti
     * @param player - barva hrace, ktery figurku vlastni
     */
    void setFigure(Position *p, bool player) {
          color = player;
          pos = p;
          pos->putFigure(this); 
    }
    ~Figure(){
    
    }
    
    /**
     * Presunuti figurky na pozici p. Obsahuje kontrolu hranic hraci desky, zda
     * pozice neni jiz obsazena a jestli figurka muze provest dany tah. Zaroven
     * neni povolen tah na stejne pole (tento fakt je kontrolovan v metodach
     * canMove jednotlivych figurek).
     *
     * @param p Cilova pozice
     * @return Bool hodnota zda je tah legalni a provedl se
     */
    bool move(Position *p);

    /**
     * Povyseni pesce na kralovnu. Tato metoda je volana z metodu move pokud
     * jsou splnena pravidla pro povyseni.
     */
    void promoteRook();

    /**
     * Odstraneni figurky.
     * @return odstranena figurka
     */
    Figure *removeFigure();

    /**
     * Test zda je mozne presunout figurku na danou pozici. Neobsahuje 
     * hranic hraci plochy nebo zda je pozice uz obsazena.
     *
     * @param p Nova pozice
     * @return true/false
     */
    virtual bool canMove(Position *p)=0;
    
    /**
     * Metoda vrati seznam moznych tahu figurky.
     * 
     * @return Nalezene tahy. Pokud nebyl nalezen zadny tah "return null".
     */
    virtual list<Position*> getPlayableMoves()=0;
    
    /**
     * Metoda vrati typ pohybu ktery muze figurka vykonat. Pokud lze vykonat 
     * pohyb pri odstraneni figurky a zaroven normalni pohyb je vraceno cislo 1.
     * @return BLOCKED == nelze vykonat pohyb.
     *         JUMP == pohyb pri kterem je odstranena nepratelska figurka.
     *         MOVE == jen pohyb.
     */
    virtual int getTypeOfMoves()=0;

    /**
     * Ziska barvu figurky
     */
    char getColor();
    
    /**
     * Ziska pozici figurky
     */
    Position *getPosition() ;
    
    /**
     * Metoda k urceni typu figurky
     * @return - vraci P - Pawn
     *           vraci Q - Queen
     */
    virtual bool isInstanceOf()=0;
};
  
#endif