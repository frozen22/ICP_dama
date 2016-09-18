/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 *
 * Datum:   Duben 2013
 * Popis:   gui - mainWindow
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFile>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    clientOper = NULL;
    ui->setupUi(this);

    int x,y,w,h;

    // nastaveni rozmisteni komponent v menu
    ui->mainMenuFrame->setShown(true);
    ui->mainMenuFrame->geometry().getRect(&x,&y,&w,&h);
    ui->gameTypeFrame->setShown(false);
    ui->gameTypeFrame->setGeometry(x,y,w,h);
    ui->hostConnectFrame->setShown(false);
    ui->hostConnectFrame->setGeometry(x,y,w,h);
    ui->hostFrame->setShown(false);
    ui->hostFrame->setGeometry(x,y,w,h);
    ui->connectFrame->setShown(false);
    ui->connectFrame->setGeometry(x,y,w,h);
    ui->loadFrame->setGeometry(x,y,w+80,h+250);
    ui->loadFrame->setShown(false);

    this->setGeometry(100,100,190,410);

    colorChosen = white;
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* ======================= MENU CONTROL ======================= */

/** Main menu -> Local AI -> Game Type */
void MainWindow::on_btnLocalAI_clicked()
{
    gameType = localAI;
    ui->mainMenuFrame->hide();
    showGameTypeFrame();
}

/** Main menu -> Local MP -> Game Type */
void MainWindow::on_btnLocalMP_clicked()
{
    gameType = localMP;
    ui->mainMenuFrame->hide();
    showGameTypeFrame();
}

/** Main menu -> Online MP -> HostConnect */
void MainWindow::on_btnOnlineMP_clicked()
{
    gameType = onlineMP;
    ui->mainMenuFrame->hide();
    ui->hostConnectFrame->show();
}

/** Game Type -> Back -> Main Menu */
void MainWindow::on_btnBackGameType_clicked()
{
    ui->mainMenuFrame->show();
    ui->gameTypeFrame->hide();
}

/** HostConnect -> Host -> Host */
void MainWindow::on_btnHostHostConnect_clicked()
{
    ui->hostConnectFrame->hide();
    ui->hostFrame->show();
}

/** HostConnect -> Connect -> Connect */
void MainWindow::on_btnConnectHostConnect_clicked()
{
    ui->hostConnectFrame->hide();
    ui->connectFrame->show();
}

/** HostConnect -> Back -> Main Menu */
void MainWindow::on_btnBackHostConnect_clicked()
{
    ui->hostConnectFrame->hide();
    ui->mainMenuFrame->show();
}

/** Host -> Back -> HostConnect */
void MainWindow::on_btnBackHost_clicked()
{
    ui->hostFrame->hide();
    ui->hostConnectFrame->show();
}

/** Connect -> Back -> HostConnect */
void MainWindow::on_btnConnectBack_clicked()
{
    ui->connectFrame->hide();
    ui->hostConnectFrame->show();
}


/** Game Type -> Continue */
void MainWindow::on_btnContinueGame_clicked()
{
    ui->gameTypeFrame->hide();
    ui->loadFrame->show();
}

/** Replay clicked */
void MainWindow::on_btnReplay_clicked()
{
    gameType = replay;
    ui->mainMenuFrame->hide();
    ui->loadFrame->show();

}

/** LoadFrame btnContinue -> start game */
void MainWindow::on_btnLoadContinue_clicked()
{
    if (ui->textEditLoad->toPlainText() == "") {
        ui->statusBar->showMessage("Load some game!");
        return;
    }

    if (gameType == replay) {
        // vytvoreni replay hry
        ReplayGame *repGame = new ReplayGame(ui->textEditLoad->toPlainText().toStdString());
        gReplayWindow *repWin = new gReplayWindow(repGame,ui->textEditLoad->toPlainText(),this);
        repWin->show();
        repWin->setFixedSize(repWin->size());
    }
    else {
        // vytvoreni normalni hry
        Game *newGame;
        Player *p1;
        Player *p2;

        if (gameType == localAI){
            if (colorChosen == white) {
                p1 = new LocalPlayer(WHITE);
                p2 = new RandomAI(BLACK);
            }
            else {
                p1 = new RandomAI(WHITE);
                p2 = new LocalPlayer(BLACK);
            }
        }
        else if (gameType == localMP) {
            p1 = new LocalPlayer(WHITE);
            p2 = new LocalPlayer(BLACK);
        }
        else { // (gameType == onlineMP)
            if (colorChosen == white) {
                p1 = new LocalPlayer(WHITE);
                p2 = new OnlinePlayer(BLACK,clientOper->getSocket());
                if (clientOper->prepareConnect()) {
                    clientOper->send(("bc"));
                }
            }
            else {
                p1 = new OnlinePlayer(WHITE,clientOper->getSocket());
                p2 = new LocalPlayer(BLACK);
                if (clientOper->prepareConnect()) {
                    clientOper->send(("wc"));
                }

            }
        }

        // vytvoreni hry
        newGame = new Game(p1,p2);

        // nacteni zaznamu ulozene hry
        Moves *movesToDo = new Moves(newGame->getDesk());
        movesToDo->loadWithBasic(ui->textEditLoad->toPlainText().toStdString());

        if (gameType == onlineMP){
            //odesleme aktualni rozlozeni "zakladajiciho"
            clientOper->send(movesToDo->getMovesInBasicNotation());
        }

        gGameWindow *gWin = new gGameWindow(newGame,movesToDo,this);
        gWin->show();
        gWin->setFixedSize(gWin->size());
        gWin->startGame();
    }


    ui->loadFrame->hide();
    ui->mainMenuFrame->show();

}

/** Game Type -> New game. Vytvoreni nove hry */
void MainWindow::on_btnNewGame_clicked()
{
    Game *newGame;
    Player *p1 = NULL;
    Player *p2 = NULL;

    if (gameType == localAI) {
        if (colorChosen == white) {
            p1 = new LocalPlayer(WHITE);
            p2 = new RandomAI(BLACK);
        }
        else {
            p1 = new RandomAI(WHITE);
            p2 = new LocalPlayer(BLACK);
        }
    }
    else if (gameType == localMP) {
        p1 = new LocalPlayer(WHITE);
        p2 = new LocalPlayer(BLACK);
    }
    else if (gameType == onlineMP) {
        if (colorChosen == white) {
            p1 = new LocalPlayer(WHITE);
            p2 = new OnlinePlayer(BLACK, clientOper->getSocket());
            if (clientOper->prepareConnect()) {
                clientOper->send(("bn"));
            }
        } else {
            p1 = new OnlinePlayer(WHITE, clientOper->getSocket());
            p2 = new LocalPlayer(BLACK);
            if (clientOper->prepareConnect()) {
                clientOper->send(("wn"));
            }
        }
    }


    newGame = new Game(p1,p2);
    gGameWindow *gWin = new gGameWindow(newGame,NULL,this);
    gWin->show();
    gWin->setFixedSize(gWin->size());
    gWin->startGame();

    ui->gameTypeFrame->hide();
    ui->mainMenuFrame->show();
}


QString MainWindow::loadFileContent(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",tr("Files (*.*)"));
    QString s = "";
    QFile f(fileName);
         if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
             return "";

         while (!f.atEnd()) {
                  QByteArray line = f.readLine();
                  s += line;
              }
         f.close();
         return s;
}

/* Load Game - load Basic */
void MainWindow::on_btnLoadBasic_clicked()
{
    ui->textEditLoad->setText(loadFileContent());
}

/* Load Game - load XML */
void MainWindow::on_btnLoadXML_clicked()
{
     // XML Convert
     QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",tr("Files (*.*)"));
     if( !fileName.isNull() )
     {
         QFile f(fileName);
         if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
         {
             return;
         }
         XMLGameSave xml(&f);
         QString s = QString::fromStdString(xml.getBasic());
         ui->textEditLoad->setText(s);
     }
}


/** Load Game -> Back -> show Menu */
void MainWindow::on_btnLoadBack_clicked()
{
    ui->loadFrame->hide();
    ui->mainMenuFrame->show();
}

/** Color choosing - White */
void MainWindow::on_radioButton_clicked()
{
    colorChosen = white;
}

/** Color choosing - Black */
void MainWindow::on_radioButton_2_clicked()
{
    colorChosen = black;
}

/* Host setup -> Host */
void MainWindow::on_btnHost_clicked()
{
    int serverPort = ui->editPortHost->text().toInt();

    //kontrola portu
    if (serverPort <= 0) {
        ui->statusBar->showMessage("Non-valid port!");
        return;
    }

    ui->statusBar->showMessage("Creating server");

    Server *server = new Server(serverPort);

    // kontrola za byl serve opravdu vytvoren
    if (!server->getServer()->isListening()) {
        ui->statusBar->showMessage("Error while creating server");
        return;
    }

    ui->statusBar->showMessage("Waiting for client");
  
    ui->btnHost->setEnabled(false);

    while(!server->isReady())
    {
        QCoreApplication::processEvents();
    }

    ui->statusBar->showMessage("Waiting");

    Game *newGame;


    ui->statusBar->showMessage("");
    if(server->isReady()){

        ui->hostFrame->hide();
        ui->mainMenuFrame->show();
   
        if (server->getColor() == WHITE){
            newGame = new Game(new LocalPlayer(WHITE),new OnlinePlayer(BLACK,server->getSocket()));
        }
        else {
            newGame = new Game(new OnlinePlayer(WHITE,server->getSocket()),new LocalPlayer(BLACK));
        }
   
        Moves * movesToDo = NULL;
         if(server->getBasicStr().size()){
            movesToDo = new Moves(newGame->getDesk());
            movesToDo->loadWithBasic(server->getBasicStr());

         }
    
         gGameWindow *gWin = new gGameWindow(newGame,movesToDo,this);
             
         gWin->show();
             
         ui->btnHost->setEnabled(true);
         gWin->setFixedSize(gWin->size());
         gWin->startGame();
            
    }



}

/* Connection setup -> Connec */
void MainWindow::on_btnConnect_clicked()
{
    int port = ui->editPortConnect->text().toInt();
    QString addr = ui->editAddrConnect->text();
    //kontrola zadanych!

    std::cout << "Creating client" << std::endl;
    Client *client = new Client(addr.toStdString(),port);
    clientOper = client;
    std::cout << "client created - prepare to conect" << std::endl;

    ui->connectFrame->hide();
    ui->gameTypeFrame->show();


}

void MainWindow::showGameTypeFrame(){
    if (gameType == localMP) {
        ui->groupBox->setEnabled(false);
    }
    else {
        ui->groupBox->setEnabled(true);
    }

    ui->gameTypeFrame->show();
}

void MainWindow::closeEvent ( QCloseEvent * event )
{
    exit(0);
}

void MainWindow::on_btnExit_clicked()
{
    this->close();

}


