#
# Predmet: Seminar C++ (ICP)
# Autori:  Frantisek Nemec (xnemec61)
#          Jan Opalka      (xopalk01)
# 
# Datum:   Duben 2013
# Popis:   Hra dama
#

Jedná se o školní projekt do předmětu Seminář C++ v akademickém roce 2012/2013, FIT VUT. Rozhraní aplikace je konzolové i grafické - nutno si vybrat již při překladu pomocí Makefilu.
K síťové komunikaci, zpracování XML souborů a praci s gui se používá knihoven QT 4.7.3.


poznámky k Makefile:
 - make => vytvori dama2013 gui verzi dle zadání
 - make run => spusti dama2013 gui verzi dle zadání

 - make cli => vytvori dama2013-cli konzolovou verzi(požadovanou v zadání)
 - make runcli => spusti dama2013-cli konzolovou verzi

 - make doxygen - dle zadání generuje dokumentaci(HTML) do souboru doc/

 - make clean - uklízecí četa ...


pozn. ke GoTo při přehrávání hry - zadané číslo je označení tahu jednoho hrace(move). Ve výpisu výše je označení 1 tahu hry(2x move - pro každáho hráče jeden).

poznámky ke konzolové verzi: Proces hry je řízen především pomocí textového menu a zadávání příslušných čísel pro výběr možností. V případě přehrávání v konzolové
verzi je možné přehrávat pouze jednu hru(kvůli možnému konfliktu výpisů). Někdy jsou vypsány kontrolní informace pro ujištění uživatele o správnosti.
Jedná se například o tahy načtené hry nebo IP adresu a port protihráče.        

Návod na spuštění konzolové aplikace(pokračování síťová hra): v kořenovém souboru spustit příkaz "make cli" (což provede překlad)
		 >> použít příkaz "make runcli" (spouští konzolovou verzi aplikace) >> vybrat volbu č.4 -> Online Game >> 
		 Zadat port a IP hosta >> vybrat volbu Create -> č.2 >> zvolit si barvu >> zvolit Load Game >> zadat cestu k souboru
		 >> hrát.
		(Pozn.: je potřeba mít připraveného hosta, čekajícího na daném portu.) 

GUI:
V hlavním menu vyberte jaký typ hry chcete hrát (lokální vs. AI, lokální více hráčů nebo online) nebo jestli chcete přehrát uloženou hru.

Přehrání hry:
Při výběru přehrání hry je třeba načít uloženou hru ze souboru a to v zakladní notaci nebo v XML formátu, případně je i možné zadat hru přímo do textového pole.
Přehrání hry je ovládáno tlačítky "Next","Undo", "GoTo" a "Stop". Tlačítko "GoTo" začne přehrávat jednotlivé tahy od aktuálního po zadaný a to se zadanym intervalem.
Tlačítko "Stop" automatické přehrávání zastaví.

Nová hra / pokračování ve hře:
Při výběru normální hry je třeba zvolit z možností nové hry nebo dohrání uložené hry. Po výběru dohrání hry je třeba nahrát uloženou hru stějně jako pri přehravání hry. Po potrvzení načtené hry je hra spuštěna s již s načtenými tahy.

