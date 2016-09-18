/**
 * Predmet: Seminar C++ (ICP)
 * Autori:  Frantisek Nemec (xnemec61)
 *          Jan Opalka      (xopalk01)
 * 
 * Datum:   Duben 2013
 * Popis:   Main
 */


#include "Main.h"

/**
 * Main.
 *
 * @author Frantisek Nemec (xnemec61), Jan Opalka (xopalk01)
 */
#ifdef GUI


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setFixedSize(w.size());

    return a.exec();
}


#else

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  string s;
  Game *g = NULL;
  while (true) {

    s = mainMenu();
    
    /*--------------------- Ukonceni hry -------------------------------------*/
    if (!s.compare("8")) {
      return EXIT_SUCCESS;
    }
    /*------------------------------------------------------------------------*/

    /*--------------------- lokalni AI vs AI ---------------------------------*/
    if (!s.compare("1")) {
      g = new Game(new RandomAI(WHITE), new RandomAI(BLACK));
    }
    /*------------------------------------------------------------------------*/
    
    /*--------------------- lokalni Player vs AI -----------------------------*/
    if (!s.compare("2")) {
      
      
      
      //volba barvy pro hrace
      s = colorChoose();
      
      //krok zpet
      if (!s.compare("8")) {
        continue;
      }
      if (!s.compare("exit")) {//ukonceni hry
        return EXIT_SUCCESS;
      }

      char AI = WHITE, chosenColor = BLACK;
      //vybrana barva je bila
      if (!s.compare("1")) {
        chosenColor = WHITE;
        AI = BLACK;
      }
      
      s = typeOfGameStart();

      if(!s.compare("8")){
        continue;
      }
      if (!s.compare("exit")) {//ukonceni hry
        return EXIT_SUCCESS;
      }  
      
      
      g = new Game(new LocalPlayer(chosenColor), new RandomAI(AI));
      //nacitani hry
      if(!s.compare("2")){
        
      
        Moves *moveToDo = loadGame(g->getDesk());
        delete g->getMovesDone(); //uklid tahu...
        g->makeMoves(moveToDo);
      }
      
    }
    /*------------------------------------------------------------------------*/
    
    /*--------------------- lokalni Player vs Player -------------------------*/
    if (!s.compare("3")) {
      g = new Game(new LocalPlayer(WHITE), new LocalPlayer(BLACK));
      
      s = typeOfGameStart();

      if(!s.compare("8")){
        continue;
      }
      if (!s.compare("exit")) {//ukonceni hry
        return EXIT_SUCCESS;
      }  
      
      
      //rozehrana hra
      if(!s.compare("2")){
        
        Moves *moveToDo = loadGame(g->getDesk());
        delete g->getMovesDone(); //uklid tahu...
        g->makeMoves(moveToDo);
      }
      
    }
    /*------------------------------------------------------------------------*/

    /*--------------------- online hra - Hot Seat ----------------------------*/
    if (!s.compare("4")) {
      s = hostOrCreate();
      
      //krok zpet
      if (!s.compare("8")) {
        continue;
      }
      if (!s.compare("exit")) {//ukonceni hry
        return EXIT_SUCCESS;
      }
      
      //cekame na pripojeni => vytvarime server
      if(!s.compare("1")){
          
          stringstream stream;
          int port = 0;
          cout << "Zadejte port na kterem budete cekat pripojeni: " << endl;
          s.clear();
          std::getline(cin, s);
          stream << s;
          stream >> port;
          
          while(port == 0){
            s.clear();
            std::getline(cin, s);
            stream << s;
            stream >> port;
            
            if(port == 0){
              cout << "Zadejte validni port!" << endl;
            }
          }
          //vytvoreni serveru
          Server serverSock(port);
          while(!serverSock.isReady()) 
          {
              QCoreApplication::processEvents();
          }
          
          
          if(serverSock.isReady()){
            
            g = new Game(new LocalPlayer(serverSock.getColor()),new OnlinePlayer(!serverSock.getColor(),serverSock.getSocket()));
            
            if(serverSock.getBasicStr().size()){
              //musime nacist
              Moves * moveToDo = new Moves(g->getDesk());
              moveToDo->loadWithBasic(serverSock.getBasicStr());
              g->makeMoves(moveToDo);
            }
            
            g->start();
            
          }
          return app.exec();
          
      }
      else{
        //inicializujume spojeni
        
        stringstream stream;
        int port = 0;
        cout << "Zadejte port, na ktery se chcete pripojit: " << endl;
        s.clear();
        std::getline(cin, s);
        stream << s;
        stream >> port;
        
        if(!s.compare("exit")){
          return EXIT_SUCCESS;
        }

        while (port == 0) {
          s.clear();
          std::getline(cin, s);
          stream << s;
          stream >> port;

          if (port == 0) {
            cout << "Zadejte validni port!" << endl;
          }
        }
        cout << "Zadejte IP adresu hrace, ke kteremu se chcete pripojit: " << endl;
        std::getline(cin, s);
        //nejake osetreni??
        string ipadress = s;
        if (!s.compare("exit")) {//ukonceni hry
          return EXIT_SUCCESS;
        }
        
        Client client(ipadress, port);
        
        //volba barvy pro hrace
        s = colorChoose();

        //krok zpet
        if (!s.compare("8")) {
          continue;
        }
        if (!s.compare("exit")) {//ukonceni hry
          return EXIT_SUCCESS;
        }

        bool chosenColor = BLACK;
        //vybrana barva je bila
        if (!s.compare("1")) {
          chosenColor = WHITE;
        }
        string onlineCol ;
        //v pripade, ze si iniciator vybral bilou, hras v druhe aplikaci ma cernou a naopak
        //WHITE == 1!!
        chosenColor ? onlineCol = "b" : onlineCol = "w";

        //volba zacatku hry
        s = typeOfGameStart();

        //krok zpet
        if (!s.compare("8")) {
          continue;
        }
        if (!s.compare("exit")) {//ukonceni hry
          return EXIT_SUCCESS;
        }
        g = new Game(new LocalPlayer(chosenColor), new OnlinePlayer(!chosenColor,client.getSocket()));
        
        if (!s.compare("1")) {
          cout << "Inicialize" << endl;
          
          if (client.prepareConnect()) {
            client.send((onlineCol+"n"));
          }
          else{
            //nastala chyba pri utvareni spojeni
            continue;
          }

          

        }
        if (!s.compare("2")) {
          cout << "Loading" << endl;
          if (client.prepareConnect()) {
            client.send((onlineCol+"c"));
          }            
          else{
            //nastala chyba pri utvareni spojeni
            continue;
          }
          
          Moves *moveToDo = loadGame(g->getDesk());
          g->makeMoves(moveToDo);
          
          //odesleme aktualni rozlozeni serveru
          client.send(moveToDo->getMovesInBasicNotation());
          
          



        }
        
//        g = new Game(new LocalPlayer(chosenColor), new OnlinePlayer(!chosenColor,client.getSocket()));
        g->start();
        return app.exec();

      }
      //         Game *g = new Game(new LocalPlayer('w'),new OnlinePlayer('b'));
    }
    /*------------------------------------------------------------------------*/

    /*--------------------- prehravani tahu ----------------------------------*/
    if (!s.compare("5")) {
      //vyber, co budeme prehravat
      
      ReplayGame * replay = NULL;
      
      cout << "V jake notaci chcete soubor?" << endl;
      cout << "XML.................................1" << endl;
      cout << "Basic...............................2" << endl;

      std::getline(cin, s);
      while (s.compare("1") && s.compare("2")) {

        std::getline(cin, s);
        cout << "Zadejte jednu z moznosti!" << endl;
      }
      
      cout << "Zadejte soubor pro prehravani: " << endl;

      if(!s.compare("2")) {
        Moves *moveToDo;
        moveToDo = new Moves(new Desk(8));
        
        string line, fileContain = "", fileName;
        std::getline(cin, fileName);
        while (true) {
          std::ifstream input(fileName.c_str());
          if (input.is_open()) {
            while (input.good()) {
              getline(input, line);
              fileContain += line;
            }
            input.close();
            break;
          }
          cout << "Zadejte validni soubor!" << endl;
          std::getline(cin, fileName);
        }
        cout << fileContain << endl;
        moveToDo->loadWithBasic(fileContain);


        replay = new ReplayGame(moveToDo->getMovesInBasicNotation());
      }
      
      if(!s.compare("1")){
      QFile *input;
      while(true){
        std::getline(cin,s);
        input = new QFile(QString::fromStdString(s));
        if( input->exists() )
        {
          break;
        }
        cout << "Soubor neexistuje, zadejte znovu: " << endl;
      }
      
      
      XMLGameSave *doc = new XMLGameSave(input);
      
      replay = new ReplayGame(doc->getBasic());
      delete doc;
      }
      
      //vytiskneme inicializovane pole
      replay->getDesk()->print(); cout << endl;
      while(true){
        stringstream stream;
      
        s = replayWay();
        
        
        //krok zpet
        if (!s.compare("8")) {
          break; //vyskoci jen z  jednoho while?
        }
        if (!s.compare("exit")) {//ukonceni hry
          return EXIT_SUCCESS;
        }

        if(!s.compare("1")){
          int flag = replay->replayNextMove();
          if(flag == END_OF_LIST){
            cout << "Hra dokoncena!" << endl;
          }
        }
  
        if(!s.compare("2")){
          Move *tah = replay->replayUndoMove();
          if(tah == NULL){
            cout << "Nelze se vratit, jsme na zacatku!" << endl;
          }
        }
  
        if(!s.compare("3")){
          
          int num = 0;
          cout << "Zadejte pozadovany tah: " << endl;
          
          while(num == 0){
            s.clear();
            std::getline(cin, s);
            stringstream stream1;
            stream1 << s;
            stream1 >> num;
            
            if(num == 0){
              cout << "Zadejte validni hodotu tahu! pr: pro paty tah:5 " << endl;
            }
          }
          
          int interval = 0;
          cout << "Zadejte interval prehravani: " << endl;
          
          while(interval == 0){
            s.clear();
            std::getline(cin, s);
            stringstream stream2;
            stream2 << s;
            stream2 >> interval;
            
            if(interval == 0){
              cout << "Zadejte validni interval tahu pro prehravani!" << endl;
            }
          }
          //thread + getch
          replay->goToMove(num,interval);
       
        }
  
        if(!s.compare("4")){
          
          int num = 0;
          cout << "Zadejte pozadovany tah: " << endl;
          s.clear();
          std::getline(cin, s);
          stream << s;
          stream >> num;
          
          while(num == 0){
            s.clear();
            std::getline(cin, s);
            stream << s;
            stream >> num;
            
            if(num == 0){
              cout << "Zadejte validni hodotu tahu! pr: pro paty tah:5 " << endl;
            }
          }

          replay->goToMove(num,500);
       
        }

      }
      
      continue; //hra se nespousti v tomto pripade
    }
    /*------------------------------------------------------------------------*/

    //spusteni hry
    char winner = g->start();
    delete g;
    
    if (winner == WHITE) {
      cout << endl << "Zvitezil bily!!! Gratulace ... " << endl << endl;
    } else {
      cout << endl << "Zvitezil cerny!!! Gratulace ... " << endl << endl;
    }
  }
  return EXIT_SUCCESS;
}
#endif

string mainMenu() {
  string s;

  cout << "Zadejte pozadovanou moznost:" << endl;

  cout << "Local AI vs. AI:.1" << endl;
  cout << "Player vs. AI:...2" << endl;
  cout << "Hot Seat:........3" << endl;
  cout << "Online Game:.....4" << endl;
  cout << "Replay:..........5" << endl;

  cout << "Exit:............8" << endl;

  std::getline(cin, s);
  //Ukonceni aplikace
  if (!s.compare("8")) {
    return "8";
  }
  if (!s.compare("exit")) {//ukonceni hry
    return "exit";
  }
  //V pripade spatne zadane moznosti
  while (s.length() != 1 || (s.compare("1") && s.compare("2")
          && s.compare("3") && s.compare("4") && s.compare("5"))) {

    cout << "Spatne zadana volba! Zkuste znovu." << endl;
    s.clear();
    std::getline(cin, s);
    //Ukonceni aplikace
    if (!s.compare("8")) {
      return "8";
    }
    if (!s.compare("exit")) {//ukonceni hry
      return "exit";
    }
  }
  return s;
}

string colorChoose() {
  string s;

  cout << "Vyberte si barvu:" << endl;

  cout << "WHITE:...1" << endl;
  cout << "BLACK:...2" << endl;

  cout << "Back:....8" << endl;

  std::getline(cin, s);

  if (!s.compare("8")) {
    return "8";
  }
  if (!s.compare("exit")) {//ukonceni hry
    return "exit";
  }
  //V pripade spatne zadane moznosti
  while (s.length() != 1 || (s.compare("1") && s.compare("2"))) {
    cout << "Spatne zadana volba! Zkuste znovu." << endl;
    s.clear();
    std::getline(cin, s);
    //krok zpet
    if (!s.compare("8")) {
      return "8";
    }
    if (!s.compare("exit")) {//ukonceni hry
      return "exit";
    }
  }

  return s;
}

string replayWay() {
  string s;

  cout << "Vyberte zpusob prehravani:" << endl;

  cout << "Next step:...............1" << endl;
  cout << "Prev step:...............2" << endl;
  cout << "Jump to with interval:...3" << endl;
  cout << "Jump to:.................4" << endl;

  cout << "Back:....................8" << endl;

  std::getline(cin, s);
  if (!s.compare("8")) {
    return "8";
  }
  if (!s.compare("exit")) {//ukonceni hry
    return "exit";
  }
  //V pripade spatne zadane moznosti
  while (s.length() != 1 || (s.compare("1") && s.compare("2") && s.compare("3") && s.compare("4"))) {
    cout << "Spatne zadana volba! Zkuste znovu." << endl;
    s.clear();
    std::getline(cin, s);
    //krok zpet
    if (!s.compare("8")) {
      return "8";
    }
    if (!s.compare("exit")) {//ukonceni hry
      return "exit";
    }
  }

  return s;
}

string typeOfGameStart() {

  string s;

  cout << "Zvolte zacatek hry:" << endl;

  cout << "New Game:.........1" << endl;
  cout << "Load Game:........2" << endl;

  cout << "Back:.............8" << endl;

  std::getline(cin, s);
  
  if (!s.compare("8")) {
    return "8";
  }
  if (!s.compare("exit")) {//ukonceni hry
    return "exit";
  }


  while (s.compare("1") && s.compare("2")) {

    cout << "Spatne zadana volba! Zkuste znovu." << endl;
    s.clear();
    std::getline(cin, s);
    //Ukonceni aplikace

    if (!s.compare("8")) {
      return "8";
    }
    if (!s.compare("exit")) {//ukonceni hry
      return "exit";
    }

  }
  return s;
}

string hostOrCreate() {

  string s;

  cout << "Chcete vytvorit hru, nebo se pripojit:" << endl;

  cout << "Wait for connection:..........1" << endl;
  cout << "Create:.......................2" << endl;

  cout << "Back:.........................8" << endl;

  std::getline(cin, s);
  
  if (!s.compare("8")) {
    return "8";
  }
  if (!s.compare("exit")) {//ukonceni hry
    return "exit";
  }


  while (s.compare("1") && s.compare("2")) {

    cout << "Spatne zadana volba! Zkuste znovu." << endl;
    s.clear();
    std::getline(cin, s);
    //Ukonceni aplikace

    if (!s.compare("8")) {
      return "8";
    }
    if (!s.compare("exit")) {//ukonceni hry
      return "exit";
    }

  }
  return s;
}

Moves *loadGame(Desk *d){

  string s;
  Moves * moveToDo;
  moveToDo = new Moves(d);
  
  cout << "V jake notaci chcete nacist?" << endl;
  cout << "XML.................................1" << endl;
  cout << "Basic...............................2" << endl;

  std::getline(cin, s);
  while (s.compare("1") && s.compare("2")) {

    std::getline(cin, s);
    cout << "Zadejte jednu z moznosti!" << endl;
  }
  cout << "Zadejte soubor, ktery chcete nacist: " << endl;

  //nacte zakladni notaci
  if (!s.compare("2")) {

    string line, fileContain = "", fileName;
    std::getline(cin, fileName);
    while (true) {
      std::ifstream input(fileName.c_str());
      if (input.is_open()) {
        while (input.good()) {
          getline(input, line);
          fileContain += line;
        }
        input.close();
        break;
      }
      cout << "Zadejte validni soubor!" << endl;
      std::getline(cin, fileName);
    }
    moveToDo->loadWithBasic(fileContain);
    
    
  }
  
  //nacte XML
  if(!s.compare("1")){
  
  XMLGameSave *doc = NULL;
  QFile *input = NULL;
  while (input == NULL || !input->exists()) {
    getline(cin, s);
    input = new QFile(s.c_str());
    doc = new XMLGameSave(input);
    if (!input->exists()) {
      cout << "Zadejte validni soubor!" << endl;
    }
  }
  
  moveToDo->loadWithBasic(doc->getBasic());
  delete input; delete doc;
  }
  
  return moveToDo;
}

void saveGame(Moves *movesDone) {
  cout << "Chcete ulozit zaznam Y/N?" << endl;
  string s ;
  std::getline(cin, s);
  while (s.compare("Y") && s.compare("N")) {
    
    std::getline(cin, s);
    cout << "Zadejte jednu z moznosti!" << endl;
  }
  
  if (!s.compare("Y")) {
    cout << "V jake notaci chcete provest ulozeni?" << endl;
    cout << "XML.................................1" << endl;
    cout << "Basic...............................2" << endl;
    
    std::getline(cin, s);
    while (s.compare("1") && s.compare("2")) {
    
      std::getline(cin, s);
      cout << "Zadejte jednu z moznosti!" << endl;
    }
    
    cout << "Zadejte jmeno a cestu, kam chcete hru ulozit: " << endl;
    
    if(!s.compare("2")){
      std::getline(cin, s);
      ofstream file;
      file.open(s.c_str());
      movesDone->movesToBasicString();
      
      file << movesDone->getMovesInBasicNotation();
      file.close();
    }
    
    if(!s.compare("1")){
      std::getline(cin, s);
      QFile *file = NULL;
      file = new QFile(s.c_str());
      XMLGameSave *doc = new XMLGameSave(movesDone);
      doc->printFile(file);
    }
  } 
}
