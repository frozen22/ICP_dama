/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 *
 * Datum:   Duben 2013
 * Popis:   gui - GameWindow
 */



#include "ggamewindow.h"
#include "ui_ggamewindow.h"

#include <QFileDialog>
#include <QFile>

gGameWindow::gGameWindow(Game *game,Moves *movesToDo, QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::gGameWindow)
{
    ui->setupUi(this);

    // normal
    this->pixmapBPawn = new QPixmap("./images/blackPawn.png");
    this->ButtonIconBPawn = new QIcon(*this->pixmapBPawn);
    QPixmap pixmapWPawn("./images/whitePawn.png");
    this->ButtonIconWPawn = new QIcon(pixmapWPawn);
    QPixmap pixmapWQueen("./images/whiteQueen.png");
    this->ButtonIconWQueen = new QIcon(pixmapWQueen);
    QPixmap pixmapBQueen("./images/blackQueen.png");
    this->ButtonIconBQueen = new QIcon(pixmapBQueen);

    // zvyraznene
    QPixmap pixmapBPawnHL("./images/blackPawnHL.png");
    this->ButtonIconBPawnHL = new QIcon(pixmapBPawnHL);
    QPixmap pixmapWPawnHL("./images/whitePawnHL.png");
    this->ButtonIconWPawnHL = new QIcon(pixmapWPawnHL);
    QPixmap pixmapWQueenHL("./images/whiteQueenHL.png");
    this->ButtonIconWQueenHL = new QIcon(pixmapWQueenHL);
    QPixmap pixmapBQueenHL("./images/blackQueenHL.png");
    this->ButtonIconBQueenHL = new QIcon(pixmapBQueenHL);

    // prazdne
    QPixmap pixmapEmptyW("./images/emptyWhite.png");
    this->ButtonIconEmptyW = new QIcon(pixmapEmptyW);
    QPixmap pixmapEmptyB("./images/emptyBlack.png");
    this->ButtonIconEmptyB = new QIcon(pixmapEmptyB);

    this->game = game;
    this->desk = game->getDesk();

    Figure *tmpFig;
    for (int i = 0; i < DESKDIM; i++) {
        for (int j = 0; j < DESKDIM; j++) {
            tmpFig = desk->getFigureAt(i+'a',j+1);

            figGrid[i+j*DESKDIM] = new GFigure(i+DESKDIM*j,tmpFig,pixmapBPawn,ButtonIconBPawn,ButtonIconWPawn,
                                                          ButtonIconBQueen,ButtonIconWQueen,ButtonIconEmptyW,ButtonIconEmptyB,
                                                          ButtonIconBPawnHL,ButtonIconWPawnHL, ButtonIconBQueenHL,ButtonIconWQueenHL, // highLight
                                                          this);

            connect(figGrid[i+j*DESKDIM], SIGNAL(clicked(int)), this, SLOT(figClicked(int)));
            ui->gridLayout->addWidget(figGrid[i+j*DESKDIM],DESKDIM-j,i);
        }
    }


    // pokud se pokracuje ve hre je potreba provest tahy
    if (movesToDo != NULL) {
        game->makeMoves(movesToDo); // provedeni tahu

        // vypis provedenych tahu
        ui->textEditGame->setText(QString::fromStdString(movesToDo->getMovesInBasicNotation()));

        // nastaveni hodnot tahu a pohybu
        moveCount = movesToDo->getMaxMoveNum() + 1;
        turnCount = (moveCount / 2);

        if ((moveCount % 2) == 1) {
            turnCount++;
        }

        // obnoveni hraci desky po provedeni tahu movesToDo
        refreshDesk();

        // Seznam tahu jiz neni potreba
        delete(movesToDo);
    }
    else { // nova hra
        moveCount = 1;
        turnCount = 1;
    }
}

gGameWindow::~gGameWindow()
{
    delete(pixmapBPawn);
    delete(ButtonIconBPawn);
    delete(ButtonIconWPawn);
    delete(ButtonIconBQueen);
    delete(ButtonIconWQueen);
    delete(ButtonIconBPawnHL);
    delete(ButtonIconWPawnHL);
    delete(ButtonIconBQueenHL);
    delete(ButtonIconWQueenHL);
    delete(ButtonIconEmptyW);
    delete(ButtonIconEmptyB);

    for (int i = 0; i < DESKDIM; i++) {
        for (int j = 0; j < DESKDIM; j++) {
            delete(figGrid[i+j*DESKDIM]);
        }
    }

    delete ui;
}


void gGameWindow::startGame(){

    // kvuli continue hre
    playingPlayer = game->getPlayingPlayer();
    showWhoIsOnTurn();

    // pokud hraji protihraci, kteri jsou RandomAI nebo onlinePlayer zpracovava se jejich tah
    if(game->getFirstPlayer()->getColor() == playingPlayer && game->getFirstPlayer()->getType() == 'R') {
        makeGMove(game->getFirstPlayer()->getMove());
    }
    else if (game->getSecondPlayer()->getColor() == playingPlayer && game->getSecondPlayer()->getType() == 'R'){
        makeGMove(game->getSecondPlayer()->getMove());
    }
    else if(game->getFirstPlayer()->getColor() == playingPlayer && game->getFirstPlayer()->getType() == 'O') {
        getOnlinePlayerMove(game->getFirstPlayer());
        makeGMove(MOVE);
    }
    else if(game->getSecondPlayer()->getColor() == playingPlayer && game->getSecondPlayer()->getType() == 'O') {
        getOnlinePlayerMove(game->getSecondPlayer());
        makeGMove(MOVE);
    }

    refreshDesk();
    repaint();
    autoState = getMoveFrom;
    showWhoIsOnTurn();
}

void gGameWindow::getOnlinePlayerMove(Player *onlinePlayer){
    list<Position *> posList;
    posList = game->getDesk()->getPlayablePositions(playingPlayer);

    if(posList.empty()) {
        MOVE = NULL;
    }
    else {
        MOVE = onlinePlayer->getMove();
        autoState = getOnMove;
    }

}

void gGameWindow::on_btnHighLightGame_clicked()
{
    list<Position *> posList;

    // zvyrazneni figurek jen pokud hraje lokalni hrac tzn. pokud je na tahu AI nebo Online hrac
    // figurky nebudou zvyrazneny
    if ((game->getFirstPlayer()->getColor() == playingPlayer && (game->getFirstPlayer()->getType() == 'L')) ||
        (game->getSecondPlayer()->getColor() == playingPlayer && (game->getSecondPlayer()->getType() == 'L'))){

        posList = game->getDesk()->getPlayablePositions(playingPlayer);
        Position *auxPos;

        while (!posList.empty()) {
            auxPos = posList.back();
            highLightFig(posToIndex(auxPos));
            posList.pop_back();
        }
    }
}

void gGameWindow::makeGMove(Move *move) {
    // samotne provedeni tahu
    game->makeMove(move);
    refreshDesk();

    QString s = "";

    // zpracovani tahu a jeho tisk do textoveho pole
    if ((moveCount % 2) == 1) {
        s.append(QString::number(turnCount)+". ");
    }

    s.append(QString::fromStdString(move->getFrom()->toString()));

    if (move->getTaken() != NULL) {
        s += 'x';
    }
    else {
        s += '-';
    }

    s.append(QString::fromStdString(move->getTo()->toString()));

    if ((moveCount % 2) == 1) {
        s += " ";
    }
    else {
        s += "\n";
        turnCount++;
    }

    moveCount++;
    ui->textEditGame->setText(ui->textEditGame->toPlainText()+s);

    invertPlayingPlayer();
    showWhoIsOnTurn();
}


void gGameWindow::invertPlayingPlayer(){
    if (playingPlayer == WHITE) {
        playingPlayer = BLACK;
    }
    else {
        playingPlayer = WHITE;
    }
}

void gGameWindow::highLightFig(int figIndex) {
    figGrid[figIndex]->highLight();
    highLightFigsVec.push_back(figIndex);
}

void gGameWindow::deHighLightFigs() {
    int figIndex;
    while(!highLightFigsVec.isEmpty()){
        figIndex = highLightFigsVec.back();
        figGrid[figIndex]->deHighLight();
        highLightFigsVec.pop_back();
    }
}


void gGameWindow::figClicked(int index) {

    Position *tmpPos;
    list<Position *> posList;
    Move *tmpMove;


    // ziskani from casti tahu
    if (autoState == getMoveFrom) {

        // kontrola tahu
        tmpPos = indexToPos(index);
        posList = game->getDesk()->getPlayablePositions(playingPlayer);

        if(posList.empty()) {
            endTheGame();
            return;
        }

        if (game->getDesk()->contains(posList,tmpPos) == true) { // tah je validni
            deHighLightFigs();
            highLightFig(index);
            // ulozeni tahu
            MOVE = new Move();
            MOVE->setFrom(tmpPos);
            autoState = getMoveTo;
        }
        else { // nevalidni tah
            ui->statusbar->showMessage("Wrong move!", WRONGMOVETIMEOUT);
        }

    }
    else if (autoState == getMoveTo) { // ziskani to casti tahu

        tmpPos = indexToPos(index);


        // hrac kliknul na jinou svoji figurku
        posList = game->getDesk()->getPlayablePositions(playingPlayer);
        if (game->getDesk()->contains(posList,tmpPos) == true) {
            deHighLightFigs();
            highLightFig(index);
            MOVE->setFrom(tmpPos);
            return;
        }

        // kontrola tahu
        posList = MOVE->getFrom()->getFigure()->getPlayableMoves();
        if (game->getDesk()->contains(posList,tmpPos) == false) {
            ui->statusbar->showMessage("Wrong move!", WRONGMOVETIMEOUT);
            return;
        }

        // kompletace tahu
        MOVE->setTo(tmpPos);

        //vykonani tahu
        makeGMove(MOVE);
        refreshDesk();

        // ukonceni hry pokud uz nepritel nemuze tahnout
        posList = game->getDesk()->getPlayablePositions(playingPlayer);
        if(posList.empty()) {
            endTheGame();
            return;
        }

        // oznameni tahu online hraci (pokud se hraje proti online hraci)
        if (game->getFirstPlayer()->getType() == 'O') {
           game->getFirstPlayer()->remindPlayer(MOVE);

        }
        else if (game->getSecondPlayer()->getType() == 'O'){
            game->getSecondPlayer()->remindPlayer(MOVE);
        }


        // provedeni tahu AI (pokud je neritel ai)
        autoState = getEnemyMove;
        if (game->getFirstPlayer()->getType() == 'R') {
            tmpMove = game->getFirstPlayer()->getMove();
            if (tmpMove == NULL){
                endTheGame();
                return;
            }
            else {
                makeGMove(tmpMove);
            }

        }
        else if (game->getSecondPlayer()->getType() == 'R'){
            tmpMove = game->getSecondPlayer()->getMove();
            if (tmpMove == NULL){
                endTheGame();
                return;
            }
            else {
                makeGMove(tmpMove);

            }
        }
        else  if (game->getFirstPlayer()->getType() == 'O') {// provedeni tahu online player (pokud je neritel online player)
            getOnlinePlayerMove(game->getFirstPlayer());
            if (MOVE == NULL) {
                endTheGame();
                return;
            }
            makeGMove(MOVE);
        }
        else if (game->getSecondPlayer()->getType() == 'O'){
            getOnlinePlayerMove(game->getSecondPlayer());
            if (MOVE == NULL) {
                endTheGame();
                return;
            }
            makeGMove(MOVE);
        }

        autoState = getMoveFrom;
    }
}


void gGameWindow::showWhoIsOnTurn() {
    QString s;
    if (playingPlayer == WHITE) {
        s = "White";
    }
    else{
        s = "Black";
    }

    s.append("\'s turn...");

    ui->statusbar->showMessage(s);
}


void gGameWindow::endTheGame(){
    ui->statusbar->showMessage("----==== Winner: "+getWinPlayer()+"! ====----");
    autoState = gameEnded;
}

QString gGameWindow::getWinPlayer(){
    if (playingPlayer == WHITE) {
        return "Black";
    }
    else {
        return "White";
    }
}

int gGameWindow::posToIndex(Position *pos){

    int col = static_cast<int>(pos->getCol());
    int row = pos->getRow();

    col -= 'a';
    row -= 1;

    return col + row*DESKDIM;;
}

Position *gGameWindow::indexToPos(int index){
    int col = index % DESKDIM;
    int row = index / DESKDIM;

    col += 'a';
    row += 1;

    return desk->getPositionAt(col,row);
}

void gGameWindow::refreshDesk(){
    Figure *tmpFig;

    for (int i = 0; i < DESKDIM; i++) {
        for (int j = 0; j < DESKDIM; j++) {
            tmpFig = desk->getFigureAt(i+'a',j+1);
            figGrid[i+j*DESKDIM]->setFig(tmpFig);
        }
    }

    this->repaint();
}

void gGameWindow::on_btnSaveBasicGame_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Open File"), "",tr("Files (*.*)"));
    if(!fileName.isNull())
    {
        QFile f(fileName);
        f.open(QIODevice::WriteOnly | QIODevice::Text);
        f.write(ui->textEditGame->toPlainText().toAscii());
        f.close();
    }
}

void gGameWindow::on_btnSaveXMLGame_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Open File"), "",tr("Files (*.*)"));
    if(!fileName.isNull())
    {
        QFile f(fileName);
        XMLGameSave *doc = new XMLGameSave(game->getMovesDone());
        doc->printFile(&f);
    }

}

void gGameWindow::on_btnBackGame_clicked()
{
    this->close();
}



