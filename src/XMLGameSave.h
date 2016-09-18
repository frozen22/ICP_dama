/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   XMLGameSave
 */


#ifndef XMLGAMESAVE_H
#define	XMLGAMESAVE_H


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


#include "Player.h" //WHITE,BLACK
#include "Moves.h"

#include <QFile>
#include <QDomDocument>
#include <QTextStream>
#include <QString>


using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::flush;
using std::ofstream;



/*
 <?xml version="1.0" encoding="UTF-8"?> 
 <game> 
   <move number=1 color="w"> 
     <from>d3</from>
     <to>d4</to>
     <taken>d5</taken>
   </move> 
 </game>
 */

/**
 * XMLGameSave.
 *
 * @author Frantisek Nemec (xnemec61)
 */

class XMLGameSave {
protected:
  QDomDocument *doc; //struktura dokumentu
  int maxNum;
public:

  /**
   * Vytvori prazdnou strukturu s elementem game
   */
  XMLGameSave() {
    doc = new QDomDocument;
    doc->appendChild(doc->createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\""));
    QDomElement root = doc->createElement("game");
    doc->appendChild(root);
    maxNum = 1;

  }
    /**
   * Destruktor
   */

  ~XMLGameSave(){
   delete doc; 
  }
  /**
   * Vytvori strukturu s elementem game a tahy Moves
   */
  XMLGameSave(Moves *moves);

  /**
   * Zanalyzuje strukturu xml dokumentu 
   * @return retezec zpracovanych dat pouzivanych dale
   */
  string getBasic();

  /**
   * Vytvari XML strukturu ze zadaneho retezce
   * @param fileContent - obsah dokumentu
   */
  XMLGameSave(QFile *file);

  /**
   * Metoda slouzici k ziskani num-teho tahu
   * @param num - oznaceni pozadopvaneho tahu
   * @return - retezec dat z pozadovaneho tahu pro dalsi zpracovani
   */
  string getMove(int num);

  /**
   * Prida do XML interni struktury udaj o dalsim tahu
   * @param color - oznaceni hrace ktery tah vykonal
   * @param from - Pozice, z ktere se figurka premistila
   * @param to - Pozice, na kterou se figurka premistila
   * @param taken - oznaceni druhu tahu("x" - skok, "-" - obycejny pohyb)
   */
  /*final*/ void addMove(bool color, string from, string to, string taken);

  /**
   * Provadi tisk do vystupniho souboru
   * @param file - vystupni soubor
   */
  void printFile(QFile *file);

};


#endif	/* XMLGAMESAVE_H */

