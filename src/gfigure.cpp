/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 *
 * Datum:   Duben 2013
 * Popis:   gui - figure
 */


#include "gfigure.h"
GFigure::GFigure(int index, Figure *fig,QPixmap *pixmap, QIcon *ButtonIconBPawn,
                 QIcon *ButtonIconWPawn, QIcon *ButtonIconBQueen,QIcon *ButtonIconWQueen,
                 QIcon *ButtonIconEmptyW, QIcon *ButtonIconEmptyB,QIcon *ButtonIconBPawnHL,
                 QIcon *ButtonIconWPawnHL, QIcon *ButtonIconBQueenHL,QIcon *ButtonIconWQueenHL,
                 QWidget *parent)
       : QPushButton(parent)
{
    this->ButtonIconBPawn = ButtonIconBPawn;
    this->ButtonIconWPawn = ButtonIconWPawn;
    this->ButtonIconBQueen = ButtonIconBQueen;
    this->ButtonIconWQueen = ButtonIconWQueen;
    this->ButtonIconEmptyW = ButtonIconEmptyW;
    this->ButtonIconEmptyB = ButtonIconEmptyB;
    this->ButtonIconBPawnHL = ButtonIconBPawnHL;
    this->ButtonIconWPawnHL = ButtonIconWPawnHL;
    this->ButtonIconBQueenHL = ButtonIconBQueenHL;
    this->ButtonIconWQueenHL = ButtonIconWQueenHL;
    this->pixmap = pixmap;
    this->index = index;
    this->fig = fig;

    this->initIcon();

    connect(this, SIGNAL(clicked()), this, SLOT(reemitClicked()));
}

void GFigure::initIcon(){
    if (fig == NULL){
        // Prazdne misto svetle (na ktere nemuzou zadne figurky)
        if( ((((index / 8) % 2) == 0) && ((index % 2) == 1)) ||
            ((((index / 8) % 2) == 1) && ((index % 2) == 0)) ) {
            this->setIcon(*ButtonIconEmptyW);
        }
        else {
            this->setIcon(*ButtonIconEmptyB);
        }
    }
    else if (fig->isInstanceOf() == PAWN) {
        if (fig->getColor() == WHITE){
             this->setIcon(*ButtonIconWPawn);
        }
        else {
             this->setIcon(*ButtonIconBPawn);
        }
    }
    else { // instanceof == QUEEN
        if (fig->getColor() == WHITE){
             this->setIcon(*ButtonIconWQueen);
        }
        else {
             this->setIcon(*ButtonIconBQueen);
        }
    }

    this->setIconSize(pixmap->size());

}

void GFigure::setEmpty(){
    this->setIcon(*ButtonIconEmptyW);
}

Figure *GFigure::getFig() {
    return fig;
}

void GFigure::setFig(Figure *fig) {
    this->fig = fig;
    initIcon();
}

void GFigure::highLight() {
    if (fig != NULL) {
        if (fig->isInstanceOf() == PAWN) {
            if (fig->getColor() == WHITE){
                this->setIcon(*ButtonIconWPawnHL);
            }
            else {
                this->setIcon(*ButtonIconBPawnHL);
            }
        }
        else if (fig->isInstanceOf() == QUEEN){
            if (fig->getColor() == WHITE){
                this->setIcon(*ButtonIconWQueenHL);
            }
            else {
                this->setIcon(*ButtonIconBQueenHL);
            }
        }
    }
}

void GFigure::deHighLight() {
    if (fig != NULL) {
        if (fig->isInstanceOf() == PAWN) {
            if (fig->getColor() == WHITE){
                 this->setIcon(*ButtonIconWPawn);
                }
            else {
                 this->setIcon(*ButtonIconBPawn);
            }
        }
        else if (fig->isInstanceOf() == QUEEN){
            if (fig->getColor() == WHITE){
                 this->setIcon(*ButtonIconWQueen);
            }
            else {
                 this->setIcon(*ButtonIconBQueen);
            }
        }
    }
}

void GFigure::reemitClicked()
{
    emit clicked(index);
}
