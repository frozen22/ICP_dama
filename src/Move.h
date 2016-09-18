/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Move
 */
#ifndef Move_H
#define Move_H

#include <stdio.h>      /* NULL */
#include "iostream"

#include "Position.h"

using std::string;

/**
 * Tah figurky. 
 * 
 * @author Frantisek Nemec
 */
class Move {
protected:
  Position *fromPos; // Odkud
  Position *toPos; // Kam 
  Position *takenPos; // Pozice odstranene figurky (Pokud nejaka byla)
  Figure *takenFig; // Odstranena figurka (Pokud nejaka byla)

  friend class Moves;

public:
  /**
   * Konstruktor naplneni prazdnymi hodnotami.
   */
  Move();
  
  /**
   * Destruktor
   */
  ~Move(){
  }
  
  /**
   * Kontruktor naplneni skoku bez odstraneni figurky.
   * 
   * @param fromP Odkud 
   * @param toP   Kam
   */
  Move(Position *fromP, Position *toP);
  /**
   * Kontruktor naplneni skoku s odstraneni figurky.
   * @param fromP Odkud
   * @param toP Kam
   * @param takenP Odstraneni figurka
   */
  Move(Position *fromP, Position *toP, Position *takenP);

  /**
   * Nastavit odkud se figurka presouva
   * @param p - Pozice odkud
   */
  void setFrom(Position*p);
  /**
   * Nastavit kam se figurka presouva
   * @param p - Pozice kam
   */
  void setTo(Position *p);

  /**
   * Nastavit pozice, kde byla odbrana figurka
   * @param p - Pozice odebirane figurky
   */
  void setTaken(Position *p);

  /**
   * Nastavit odbranou figurku
   * @param p - odebirana figurka
   */
  void setTakenFig(Figure *f);

  /**
   * Ziska Pozici odkud se tahlo
   * @return Pozice odkud
   */
  Position *getFrom();

  /**
   * Ziska Pozici kam se tahlo
   * @return Pozice kam
   */
  Position *getTo();

  /**
   * Zjisti, zda je nejaka pozice, kde se odebirala figurka
   * @return Pozice, kde byla odebrana figurka
   */
  Position *getTaken();

  /**
   * Ziskani odkazu na odebranou figurku
   * @return odebirana figurka
   */
  Figure *getTakenFig();

  /**
   * Prevod tahu do zakladni notace.
   * 
   * @return Retezec v zakladni notaci.
   */
  string moveToString();
};

#endif