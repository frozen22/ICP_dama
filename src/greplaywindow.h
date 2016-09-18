/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 *
 * Datum:   Duben 2013
 * Popis:   gui - replay window
 */

#ifndef GREPLAYWINDOW_H
#define GREPLAYWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "ReplayGame.h"
#include "gfigure.h"

class ReplayGame;

namespace Ui {
    class gReplayWindow;
}

/** 
 * Formular pro prehravani ulozene hry. Formular obsahuje hraci desku, textove 
 * pole s nactenymi tahy a tlacitka pro ovladani prehravani. 
 * Tlacitka: Next - zobrazeni dalsiho tahu 
 *           Undo - zruseni posledniho tahu 
 *           GoTo - prehrani tahu mezi aktualnim a zadanym tahem se zadanym  
 *                  intervalem (v ms) 
 *           Stop - Zastaveni prehravani tahu aktitovane tlacitkem GoTo 
 *  
 * @author Frantisek Nemec (xnemec61), Jan Opalka xopalk01 
 */
class gReplayWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit gReplayWindow(ReplayGame *rGame, QString strMoves, QWidget *parent = 0);
    ~gReplayWindow();

private slots:

    /**
     * Klinuti na tlacitko Next pri prehavani hry. Tlacitko zpusoby
     * nacteni dalsiho ulozeneho tahu a jeho robrazeni.
     */
    void on_btnNext_clicked();

    /**
     * Klinuti na tlacitko Undo pri prehavani hry. Tlacitko zpusoby
     * nacteni predchoziho tahu a jeho zobrazeni
     */
    void on_btnUndo_clicked();

    /**
     * Kliknuti na tlacitko GoTo pri prehravani hry. Spusteni automatickeho
     * prehravani tahy do zadaneho tahu. Interval prehravani jednotlivych
     * tahu je zadan do editu Interaval.
     */
    void on_btnGoTo_clicked();

    /**
     * Kliknuti na tlacitko close. Zavreni okna prehravani hry.
     */
    void on_btnClose_clicked();

    /**
     * Metoda ktera provadi samotne nacteni a provedeni tahu pri goTo.
     */
    void nextGoTo();

    /**
     * Kliknuti na tlacitko stop. Zastaveni automatickeho prehravani.
     */
    void on_btnStop_clicked();

private:
    Ui::gReplayWindow *ui;

    /**
     * Prekresleni hraci desky.
     */
    void refreshDesk();

    // ikony policek
    QPixmap *pixmapBPawn;
    QIcon *ButtonIconBPawn;
    QIcon *ButtonIconWPawn;
    QIcon *ButtonIconBQueen;
    QIcon *ButtonIconWQueen;
    QIcon *ButtonIconEmptyW;
    QIcon *ButtonIconEmptyB;

    // logika prehravane hry
    ReplayGame *repGame;

    // velikost hraci desky
    static const int DESKDIM = 8;
    // hraci deska
    Desk *desk;
    // ulozene figurky
    GFigure *figGrid[DESKDIM*DESKDIM];

    // casovat automatickeho prehravani
    QTimer *autoGotoTimer;
    int goToMoveNum;

};

#endif // GREPLAYWINDOW_H
