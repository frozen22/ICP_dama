/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 *
 * Datum:   Duben 2013
 * Popis:   gui - GameWindow
 */

#ifndef GGAMEWINDOW_H
#define GGAMEWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "gfigure.h"
#include "Desk.h"
#include "Game.h"

namespace Ui {
class gGameWindow;
}

/** 
 * Formular pro hrani hry. Okno obsahuje hraci desku, textove pole pro zobrazeni 
 * provedenych tahu a tlacitka. 
 * Tlacitka: HighLight - zvyrazneni figurek se kterymi lze hrat 
 *           Save - basic - ulozeni zaznamu hry v zakladni notaci 
 *           Save - XML - ulozeni zaznamu hry v XML formatu 
 *  
 * @author Frantisek Nemec (xnemec61), Jan Opalka xopalk01 
 */
  
class gGameWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit gGameWindow(Game *game,Moves *movesToDo, QWidget *parent = 0);
    ~gGameWindow();
    void startGame();
    
private slots:

    /**
     * Kliknuti na tlacitko zvyrazneni figurek.
     */
    void on_btnHighLightGame_clicked();

    /**
     * Kliknuti na figurku. Obsahuje zpracovani tahu hrace a dale zpracovani tahu oponenta.
     */
    void figClicked(int index);

    /**
     * Kliknuti na tlacitko zavreni okna.
     */
    void on_btnBackGame_clicked();

    /**
     * Kliknuti na tlacitko ulozeni zaznamu hry v zakladni notaci.
     */
    void on_btnSaveBasicGame_clicked();

    /**
     * Kliknuti na tlacitko ulozeni zaznamu hry v XML formatu.
     */
    void on_btnSaveXMLGame_clicked();

private:
    Ui::gGameWindow *ui;

    /**
     * Ziskani tahu od online hrace.
     *
     * @param onlinePlayer Online hrac.
     */
    void getOnlinePlayerMove(Player *onlinePlayer);

    /**
     * Ziskani oznaceni vitezneho hrace.
     *
     * @return White/Black
     */
    QString getWinPlayer();

    /**
     * Zmemeni privatni promene, ktera obsahuje oznaceni prave hrajiciho hrace.
     */
    void invertPlayingPlayer();


    /**
     * Zvirazneni figurky.
     *
     * @param figIndex Index figurky
     */
    void highLightFig(int figIndex);

    /**
     * Znevyzarneni vsech zvyraznenych figurek/
     */
    void deHighLightFigs();

    /**
     * Provedeni tahu. Obsahuje obnoveni hraci desky.
     *
     * @param move Tah k provedeni
     */
    void makeGMove(Move *move);

    /**
     * Prekresleni hraci desky.
     */
    void refreshDesk();

    /**
     * Prevedeni Position figurky na index
     *
     * @param pos Position
     * @return Index figurky
     */
    int posToIndex(Position *pos);

    /**
     * Prevedeni indexu figurky na typ Position.
     *
     * @param index Index figurky
     * @return Position figurky
     */
    Position *indexToPos(int index);


    /**
     * Ukonceni hry. Nastaveni stavu automatu a zobrazeni viteze.
     */
    void endTheGame();


    /**
     * Zobrazeni kdo je prave na tahu. Zobrazeni je provedeno do statusbaru.
     */
    void showWhoIsOnTurn();

    // ikony policek
    QPixmap *pixmapBPawn;
    QIcon *ButtonIconBPawn;
    QIcon *ButtonIconWPawn;
    QIcon *ButtonIconBQueen;
    QIcon *ButtonIconWQueen;
    QIcon *ButtonIconBPawnHL;
    QIcon *ButtonIconWPawnHL;
    QIcon *ButtonIconBQueenHL;
    QIcon *ButtonIconWQueenHL;
    QIcon *ButtonIconEmptyW;
    QIcon *ButtonIconEmptyB;

    static const int DESKDIM = 8;

    // pole figurek
    GFigure *figGrid[DESKDIM*DESKDIM];

    // deska hrajici hru
    Desk *desk;

    // hrajici hra
    Game *game;


    // Stavy automatu ziskavani tahu
    enum AutomatStates {
        getMoveFrom, getMoveTo, getEnemyMove, getOnMove, gameEnded
    }autoState;

    // delka zobrazeni hlaseni o nevalidnim tahu (ms)
    const static int WRONGMOVETIMEOUT = 2000;

    // pomocna promena pouzita pri kompletaci tahu
    Move *MOVE;


    // prave hrajici hrac
    char playingPlayer;

    // zvyraznene figurky
    QVector<int> highLightFigsVec;

    // promene ukladajici pocty tahu hry
    int moveCount;
    int turnCount;
};

#endif // GGAMEWINDOW_H
