/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Moves
 */



#include "Moves.h"


/**
 * Soubor obsahujici vyuzivane informace k ulozeni tahu hry. 
 * 
 * @author Frantisek Nemec
 */



    void Moves::replaceAll(string *str, string target, string replacement) {
      size_t start = 0;
      if(target.size() == 0) //pokud je nulovy target => nedefinovane chovani,
                             //resp. nedelat nic
        return;
    
      //pokud exituje vzor v retezci pokracujeme
      while((start = str->find(target, start)) != string::npos) {
        
          //nahrada za vzor
          str->replace(start, target.length(), replacement);
        
          //uprava odrazoveho bodu pro vyhledavani
          start += replacement.length(); 
      }
      return;
    }
    
    void Moves::loadWithBasic(string str) {
        Position *from, *to;
        string sub;
      
        movesInBasicNotation = ""+str;// Ulozeni retezce
        maxMoveNum = 0;
        
        // Upraveni retezce
        replaceAll(&str,string("\r\n"),string("\n"));
        replaceAll(&str,string("\t"),string(""));
        replaceAll(&str,string("\n"),string(""));
        replaceAll(&str,string(" "),string(""));
        
       // Dokud je co zpracovavat
        while(str.length() > 6) {
            
            // odstraneni cisla tahu
            str = str.erase(0,str.find('.')+1); 

            
            // ziskani tahu 
            sub = str.substr(0, 5);
            // zpracovani tahu
            from = desk->getPositionAt(sub.at(0), sub.at(1) - '0');
            to = desk->getPositionAt(sub.at(3), sub.at(4) - '0');

            addMove(new Move(from,to));
            maxMoveNum++;

            // odstraneni tahu, ktery byl prave zpracovan z retezce
            str = str.erase(0,5);
            
            if (str.length() < 5) { // byl zadan jen move z turnu
                return;
            }
            
            //zpracovani dalsiho tahu v turnu
            sub = str.substr(0, 5);

            from = desk->getPositionAt(sub.at(0), sub.at(1) - '0');
            to = desk->getPositionAt(sub.at(3), sub.at(4) - '0');
            addMove(new Move(from,to));
            maxMoveNum++;


            str = str.erase(0,5);
        }
        
    }
    
    Move *Moves::getPrevMove() {
        Move *move;
        if (moveNum > 0) {
            moveNum--;
            list<Move *>::iterator it = moveList.begin();
            for(int tmp = moveNum;tmp != 0;tmp--){
              it++;
            }
            move = *it;
            return move;
        }
        else {  // Cteni pred zacatek seznamu
            return NULL;
        }
    }
    
    Move *Moves::getNextMove() {
        Move *move;
        if (moveNum < moveList.size()) {
            list<Move *>::iterator it = moveList.begin();
            for(int tmp = moveNum;tmp != 0;tmp--){
              it++;
            }
            move = *it;
            moveNum++;
            return move;
        }
        else {
            return NULL;
        }
    }
    
    void Moves::movesToBasicString(){
    
      string tmp;
      int turnCount = 1;
     
      Move *move;
      while ((move = this->getNextMove()) != NULL){
        
          if((moveNum%2 )== 1){
            std::stringstream count;
            count << turnCount;
            
            tmp += count.str() + "." + move->moveToString() +" ";
          }
          
          else{
            tmp += move->moveToString()+" \n";
            turnCount++;
          }
          
        }
      movesInBasicNotation = tmp;
    
    }