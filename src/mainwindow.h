/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 *
 * Datum:   Duben 2013
 * Popis:   gui main window
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gfigure.h"
#include "Desk.h"
#include "XMLGameSave.h"
#include "ggamewindow.h"
#include "greplaywindow.h"
#include "Server.h"
#include "Client.h"
#include "LocalPlayer.h"
#include "OnlinePlayer.h"
#include "RandomAI.h"


namespace Ui {
class MainWindow;
}

/** 
 * Hlavni okno se vsemi menu. Menu obsahuje hlavni menu s vyberem typu hry 
 * (local vs AI, local vice hracu, online a prehravani hry). Dale obsahuje 
 * menu s vyberem nove hry, pokracovani ve hre a vyberem barvy. Pri zvoleni 
 * online hry je zobrazeno menu s vyberem hostovani hry nebo pripojeni se  
 * k cekajicimu hostovy, s timto menu jsou take spojena dalsi menu ktera 
 * slouzi pro vytvoreni hosta resp. pripojeni se k hostovy. 
 *  
 * @author Frantisek Nemec (xnemec61), Jan Opalka xopalk01 
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_btnLocalAI_clicked();

    void on_btnLocalMP_clicked();

    void on_btnOnlineMP_clicked();

    void on_btnBackGameType_clicked();

    void on_btnHostHostConnect_clicked();

    void on_btnConnectHostConnect_clicked();

    void on_btnBackHostConnect_clicked();

    void on_btnBackHost_clicked();

    void on_btnConnectBack_clicked();

    void on_btnReplay_clicked();

    void on_btnLoadBasic_clicked();

    void on_btnLoadXML_clicked();

    void on_btnLoadContinue_clicked();

    void on_btnNewGame_clicked();

    void on_btnContinueGame_clicked();

    void on_btnLoadBack_clicked();

    void on_btnExit_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_btnHost_clicked();

    void on_btnConnect_clicked();
protected:
    virtual void closeEvent ( QCloseEvent * event );

private:
    Ui::MainWindow *ui;

    /**
     * Zobrazeni gameType menu. Metoda obsahuje nastaveni enable vybrani barvy
     * ktere je pri localMultiPlayer hre zakazano.
     */
    void showGameTypeFrame();


    /**
     * Nacteni obsahu souboru. Obsahuje zobrazeni dialogu vyberu barvy a nasledne
     * nacteni jeho obsahu.
     *
     * @return Retezec s obsahem souboru
     */
    QString loadFileContent();


    // Typy hry, mozne typy hry zvolene v hlavnim menu
    enum GameTypes {
        localAI, localMP, onlineMP, replay
    };
    // Typ hry zvoleny v hlavnim menu
    GameTypes gameType;

    // Barvy ktere lze zvolit v gameType menu
    enum ColorChosen {
        white,black
    };
    // Zvolena barva v gameTypeMenu
    ColorChosen colorChosen;


    Client *clientOper;

};

#endif // MAINWINDOW_H
