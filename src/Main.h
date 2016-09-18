/* 
 * File:   MAIN.h
 * Author: Jan Opalka
 *
 * Created on 28. duben 2013, 23:23
 */

#ifndef MAIN_H
#define	MAIN_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include <QDomDocument>
#include <QApplication>
#include <QtGui/QApplication>

#include "mainwindow.h"
#include "Game.h"
#include "Desk.h"
#include "Figure.h"
#include "Position.h"
#include "LocalPlayer.h"
#include "OnlinePlayer.h"
#include "Moves.h"
#include "ReplayGame.h"
#include "Server.h"
#include "Client.h"

using std::cout;
using std::cerr;
using std::flush;
using std::endl;
using std::cin;
using std::stringstream;
using std::fstream;
using std::getline;

/**
 * Hlavni menu pro konzolovou verzi
 * @return retezec s vybranou moznosti
 */
string mainMenu();

/**
 * Vyber barvy pro hrace pro konzoli
 * @return retezec s vybranou variantou
 */
string colorChoose();

/**
 * Vybirame zpusob prehravani tahu konzolova verze
 * @return zvolnea moznost
 */
string replayWay();

/**
 * Slouzi k vyberu typu zacatku hry
 * @return vybrany typ
 */
string typeOfGameStart();

/**
 * Zjisteni zda budeme vytvaret nebo se pripoovat pri online hre
 * @return zvolena moznost
 */
string hostOrCreate();

/**
 * Ulozi hru
 * @param movesDone - zaznam z hry
 */
void saveGame(Moves *movesDone);

/**
 * Funkce nacitajici tahy z XML a zakladni notace
 * @return tahy pripravene k inicializaci hry
 */
Moves *loadGame(Desk *);

#endif	/* MAIN_H */

