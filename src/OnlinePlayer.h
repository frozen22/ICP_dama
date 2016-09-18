/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   OnlinePlayer
 */
#ifndef OnlinePlayer_H
#define OnlinePlayer_H

#include <stdio.h>      /* NULL */
#include <string>
#include <iostream>
#include <exception>

#include "Player.h"
#include "Move.h"
#include "Game.h"

#include <QTcpSocket> 
#include <QCoreApplication>
#include <QApplication>



using std::exception;

/**
 * OnlinePlayer.
 *
 * @author Frantisek Nemec (xnemec61)
 */
class OnlinePlayer : public Player {
protected:
  QTcpSocket * socket;
public:
  /**
   * Konstruktor Online hrace
   * @param c - barva hrace
   * @param socket - socket pro komunikaci se serverem
   */
  OnlinePlayer(bool c, QTcpSocket * socket);
  /**
   * Destruktor Onlinehrace
   */
  ~OnlinePlayer(){
  }

  
  /**
   * Ziskani tahu.
   * 
   * @return Tah hrace
   */
  Move *getMove();

  //    private InputStream sockInput;
  //    private OutputStream sockOutput;

  /**
   * Prevedeni tahy Move do textove podoby. 
   * 
   * @param move Konverovany tah
   * @return Retezec s prevedenym tahem
   */
  string codeMoveToString(Move *move) {
    return (move->getFrom()->toString() + move->getTo()->toString());
  }

  /**
   * Prevedeni tahy v textove podobe do tridy Move;
   * 
   * @param strMove Tah v zakladni notaci
   * @return Move
   */
  Move *decodeStringToMove(string strMove);

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
  void remindPlayer(Move *move);

   /**
   * Vraci druh hrace
   * @return druh hrace
   */
  char getType(){
    return type;
  }
  
  /**
   * Vraci socket online hrace
   * @return socket
   */
  QTcpSocket *getSocket(){
    return socket;
  }
  
};

#endif