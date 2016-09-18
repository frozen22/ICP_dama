/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   XMLGameSave
 */


#include "XMLGameSave.h"

/**
 * XMLGameSave.
 *
 * @author Frantisek Nemec (xnemec61)
 */

XMLGameSave::XMLGameSave(Moves *moves) {
  doc = new QDomDocument;
  doc->appendChild(doc->createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\""));
  doc->appendChild(doc->createElement("game"));




  maxNum = 1;
  string from, to, taken;
  Move *move;
  bool color = WHITE;



  while ((move = moves->getNextMove()) != NULL) {

    from = move->getFrom()->toString();
    to = move->getTo()->toString();

    if (move->getTaken() != NULL) {
      taken = move->getTaken()->toString();
    } else {
      taken = "";
    }

    addMove(color, from, to, taken);
    if (color == WHITE) {
      color = BLACK;
    } else {
      color = WHITE;
    }

  }

}

string XMLGameSave::getBasic() {
  if (doc == NULL) {
    return NULL;
  }

  QDomElement root = doc->documentElement();
  

  std::ostringstream ss;


  string movesStr;
  int turnCount = 1;
  int i = 1;

  QDomNode child = root.firstChild();
  while (!child.isNull()) {
    ss.str(""); //vycisteni streamu

    if (i % 2 == 1) {
      ss << turnCount;

      movesStr += (ss.str() + ". " + static_cast<string> (getMove(i)) + " ");

    } else {
      movesStr += getMove(i) + "\n";
      turnCount++;
    }
    i++;

    child = child.nextSibling();
  }
  cout << movesStr << endl;
  return movesStr;
}

XMLGameSave::XMLGameSave(QFile *file) {
  file->open(QFile::ReadOnly | QFile::Text);
  if (!file->isOpen()) {
    cerr << "Chyba pri nacitani ze souboru!" << endl;
  }

  QString errorMsg;
  int errorLine;
  int errorColumn;

  doc = new QDomDocument;
  if (!doc->setContent(file, false, &errorMsg, &errorLine, &errorColumn)) {
    std::cerr << "Chyba pri analyze dat..." << endl;
  }

  file->close();
}

string XMLGameSave::getMove(int num) {
  string from = "";
  string to = "";
  string taken = "";
  QString strNum = QString::number(num);

  QDomElement root = doc->documentElement();
  QDomElement innerEle;

  QDomElement move = root.firstChildElement();
  while (!move.isNull()) {
    if (move.attribute("number").compare((strNum)) == 0) {
      QDomElement elems = move.firstChildElement();


      // load from
      innerEle = elems;
      from = innerEle.text().toStdString();

      elems = elems.nextSiblingElement();
      // load to
      innerEle = elems;
      to = innerEle.text().toStdString();

      elems = elems.nextSiblingElement();
      // load taken
      innerEle = elems;
      taken = innerEle.text().toStdString();
    }

    move = move.nextSiblingElement();
  }

  // num++;
  if (!taken.compare("")) {
    return (from + "-" + to);
  } else {
    return (from + "x" + to);
  }

}

void XMLGameSave::addMove(bool color, string from, string to, string taken) {

  QDomElement root = doc->documentElement();

  QDomElement moveElement = doc->createElement("move");
  root.appendChild(moveElement);

  moveElement.setAttribute("number", maxNum);
  moveElement.setAttribute("color", color);


  QDomElement fromElement = doc->createElement("from");
  moveElement.appendChild(fromElement);

  QDomText fromTxt = doc->createTextNode(QString::fromStdString(from));
  fromElement.appendChild(fromTxt);


  QDomElement toElement = doc->createElement("to");
  moveElement.appendChild(toElement);

  QDomText toTxt = doc->createTextNode(QString::fromStdString(to));
  toElement.appendChild(toTxt);


  QDomElement takenElement = doc->createElement("taken");
  moveElement.appendChild(takenElement);
  if (taken.size() != 0) {

    QDomText takenTxt = doc->createTextNode(QString::fromStdString(taken));
    takenElement.appendChild(takenTxt);
  }


  maxNum++;

}

void XMLGameSave::printFile(QFile *file) {

  if (file->open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream TextStream(file);
    TextStream << doc->toString();
    file->close();
  }
  else {
    cerr << "Chyba pri IO operaci!" << endl;
  }


}


