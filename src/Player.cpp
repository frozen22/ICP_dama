/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Abstraktni trida hrace
 */

#include "Player.h"

/**
 * Player.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */

void Player::setPlayer(bool c) {
  color = c;
  wantSave = false;
}

Player *Player::initPlayer(Game *g) {
  game = g;
  return this;
}


