#
# Predmet: Seminar C++ (ICP)
# Autori:  Frantisek Nemec (xnemec61)
#          Jan Opalka      (xopalk01)
# 
# Datum:   Duben 2013
# Popis:   Makefile dama2013
#

.PHONY: all run pack doxygen clean runcli cli

PATH:=$(QTDIR):/usr/local/share/Qt-4.7.3/qt/bin:$(PATH)
PATH:=$(QTDIR):/usr/local/share/Qt/bin:$(PATH)

QT += core xml network gui

CPP=g++
CPPFLAGS= -Wall -pedantic -W -g
DEFINES += GUI


#	cd src; qmake "DEFINES += GUI" dama2013.pro
#	cd src; qmake -project QT+=network xml core -o dama2013.pro
#	qmake QT+= core network xml CONFIG+=debug qt -o src/Makefile src/dama2013.pro 

#gui
all: clean 
	cd src; qmake "DEFINES += GUI" dama2013.pro
	cd src; make


 
 
#gui
run: src/dama2013 
	cd src; ./dama2013
#konzole
cli: clean 
	cd src; qmake dama2013.pro
	cd src; make dama2013
	cd src; mv dama2013 dama2013-cli
#konzole
runcli: 
	cd src; ./dama2013-cli

pack: clean
	zip xopalk01.zip -r ../xopalk01
  
doxygen:
	doxygen Doxyfile

clean:  
	rm -rf src/*.o src/dama2013 src/dama2013-cli doc/* src/Makefile  src/moc_*.c*       
