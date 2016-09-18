#include "greplaywindow.h"
#include "ui_greplaywindow.h"

gReplayWindow::gReplayWindow(ReplayGame *rGame,QString strMoves,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gReplayWindow)
{
    ui->setupUi(this);

    // nacteni ikonec figurek (tlacitek)
    this->pixmapBPawn = new QPixmap("./images/blackPawn.png");
    this->ButtonIconBPawn = new QIcon(*this->pixmapBPawn);
    QPixmap pixmapWPawn("./images/whitePawn.png");
    this->ButtonIconWPawn = new QIcon(pixmapWPawn);
    QPixmap pixmapWQueen("./images/whiteQueen.png");
    this->ButtonIconWQueen = new QIcon(pixmapWQueen);
    QPixmap pixmapBQueen("./images/blackQueen.png");
    this->ButtonIconBQueen = new QIcon(pixmapBQueen);

    // prazdna mista
    QPixmap pixmapEmptyW("./images/emptyWhite.png");
    this->ButtonIconEmptyW = new QIcon(pixmapEmptyW);
    QPixmap pixmapEmptyB("./images/emptyBlack.png");
    this->ButtonIconEmptyB = new QIcon(pixmapEmptyB);

    // ulozeni hry
    this->repGame = rGame;
    this->desk = rGame->getDesk();

    // inicializace figurek/prazdnych poli na hraci desce
    Figure *tmpFig;
    for (int i = 0; i < DESKDIM; i++) {
        for (int j = 0; j < DESKDIM; j++) {
            tmpFig = desk->getFigureAt(i+'a',j+1);

            figGrid[i+j*DESKDIM] = new GFigure(i+DESKDIM*j,tmpFig,pixmapBPawn,ButtonIconBPawn,ButtonIconWPawn,
                                               ButtonIconBQueen,ButtonIconWQueen,ButtonIconEmptyW,ButtonIconEmptyB,
                                               ButtonIconEmptyB,ButtonIconEmptyB,ButtonIconEmptyB,ButtonIconEmptyB,this);

            ui->gridLayout->addWidget(figGrid[i+j*DESKDIM],DESKDIM-j,i);
        }
    }

    // vypis ulozene hry v zakladni notaci do textoveho pole
    ui->textEditGame->setText(strMoves);

    // timer pro automaticke prehravani tahu pri goTo
    autoGotoTimer = new QTimer(this);
    // pripojeni slotu timeru k signalu
    QObject::connect(autoGotoTimer, SIGNAL(timeout()), this, SLOT(nextGoTo()));

    // Nelze stopovat bez spusteni
    ui->btnStop->setEnabled(false);
}

gReplayWindow::~gReplayWindow()
{
    delete(pixmapBPawn);
    delete(ButtonIconBPawn);
    delete(ButtonIconWPawn);
    delete(ButtonIconBQueen);
    delete(ButtonIconWQueen);
    delete(ButtonIconEmptyW);
    delete(ButtonIconEmptyB);

    delete(autoGotoTimer);

    for (int i = 0; i < DESKDIM; i++) {
        for (int j = 0; j < DESKDIM; j++) {
            delete(figGrid[i+j*DESKDIM]);
        }
    }

    delete ui;
}



void gReplayWindow::on_btnNext_clicked()
{
    repGame->replayNextMove();
    refreshDesk();
}

void gReplayWindow::refreshDesk(){
    Figure *tmpFig;

    for (int i = 0; i < DESKDIM; i++) {
        for (int j = 0; j < DESKDIM; j++) {
            tmpFig = desk->getFigureAt(i+'a',j+1);
            figGrid[i+j*DESKDIM]->setFig(tmpFig);
        }
    }
}

void gReplayWindow::on_btnUndo_clicked()
{
    repGame->replayUndoMove();
    refreshDesk();
}

void gReplayWindow::on_btnGoTo_clicked()
{
    // ulozeny hodnoty tahu
    int maxMoveNum = repGame->getMoves()->getMaxMoveNum();

    // konverze tahu
    goToMoveNum = ui->editGoToNum->text().toInt();
    if (goToMoveNum < 0 || goToMoveNum > maxMoveNum) {
      ui->statusbar->showMessage("Nespravny rozsah pohybu!");
      return;
    }

    // ulozeni intervalu
    int interval = ui->editAutoPlayInterval->text().toInt();
    if (interval < 0) {
        ui->statusbar->showMessage("Nevalidni interval");
        return;
    }

    ui->statusbar->showMessage("");

    // start
    autoGotoTimer->start(interval);
    ui->btnStop->setEnabled(true);
    ui->btnGoTo->setEnabled(false);
    ui->btnNext->setEnabled(false);
    ui->btnUndo->setEnabled(false);
}

void gReplayWindow::nextGoTo() {


    int actMoveNum = repGame->getMoves()->getActualMoveNum();

    if (goToMoveNum > actMoveNum) {
      on_btnNext_clicked();
    } else if (goToMoveNum < actMoveNum) {
      on_btnUndo_clicked();
    }
    else { // posledni tah
        autoGotoTimer->stop();
        ui->btnStop->setEnabled(false);
        ui->btnGoTo->setEnabled(true);
        ui->btnNext->setEnabled(true);
        ui->btnUndo->setEnabled(true);
    }
}


void gReplayWindow::on_btnStop_clicked()
{
    ui->statusbar->showMessage("AutoPlay stopped",2000);
    autoGotoTimer->stop();
    ui->btnStop->setEnabled(false);
    ui->btnGoTo->setEnabled(true);
    ui->btnNext->setEnabled(true);
    ui->btnUndo->setEnabled(true);
}

void gReplayWindow::on_btnClose_clicked()
{
    autoGotoTimer->stop();
    this->close();
}
