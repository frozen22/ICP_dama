/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 *
 * Datum:   Duben 2013
 * Popis:   gui - figure
 */

#ifndef GFIGURE_H
#define GFIGURE_H

#include <QPushButton>
#include "Figure.h"
#include "Desk.h"


/** 
 * Graficke znazorneni figurky na hraci desce. Tlacitka obsahuji ikony  
 * podle toho jakou figurku zastupuji a mezi jednotlivymi ikonami prepinaji 
 * podle potreby. 
 *  
 * @author Frantisek Nemec (xnemec61), Jan Opalka xopalk01 
 */
class GFigure : public QPushButton
{
    Q_OBJECT
public:
GFigure(int index, Figure *fig,QPixmap *pixmap, QIcon *ButtonIconBPawn,
                 QIcon *ButtonIconWPawn, QIcon *ButtonIconBQueen,QIcon *ButtonIconWQueen,
                 QIcon *ButtonIconEmptyW, QIcon *ButtonIconEmptyB,QIcon *ButtonIconBPawnHL,
                 QIcon *ButtonIconWPawnHL, QIcon *ButtonIconBQueenHL,QIcon *ButtonIconWQueenHL,
                 QWidget *parent);

    /** 
     * Nastaveni ikony na prazdne policko. 
     */
    void setEmpty();

    /** 
     * Ziskani figurky kterou tato trida zobrazuje. 
     *  
     * @return Figure 
     */
    Figure *getFig();

    /** 
     * Nastaveni figurky kterou ma tato trida zastupovat (zobrazit). 
     * @param fig 
     */
    void setFig(Figure *fig);

    /** 
     * Nastaveni ikony podle ulozene Figure. 
     */
    void initIcon();

    /** 
     * Zvyrazneni figurky. To je reseni zmenenim ikony. 
     */
    void highLight();

    /** 
     * Znevyrazneni figurky 
     */
    void deHighLight();

signals:
    void clicked(int digit);

private slots:
    void reemitClicked();

private:

    int index;
    Figure *fig;

    QPixmap *pixmap;
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

};

#endif // GFIGURE_H
