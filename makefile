UNAME := $(shell uname)

tetris: src/tetris.o ./gfx/libisentlib.a
ifeq ($(UNAME), Darwin)
	gcc -Wall src/tetris.o -o tetris gfx/libisentlib.a -lm -framework OpenGL -framework GLUT
else
	gcc -Wall src/tetris.o -o tetris gfx/libisentlib.a -lm -lglut -lGL -lX11
endif

# GFXLIB
gfx/libisentlib.a:
	@echo "Building libisentlib.a..."
	@cd gfx && make && cd ..

# Tetris dans src
src/tetris.o: src/tetris.c gfx/GfxLib.h gfx/BmpLib.h gfx/ESLib.h
	gcc -Wall -c src/tetris.c -o src/tetris.o

# Initialisation
src/initialisation.o: src/initialisation.c gfx/GfxLib.h gfx/BmpLib.h gfx/ESLib.h
	gcc -Wall -c src/initialisation.c -o src/initialisation.o

# Affichage
src/affichage/jeu.o: src/affichage/jeu.c gfx/GfxLib.h gfx/BmpLib.h gfx/ESLib.h
	gcc -Wall -c src/affichage/jeu.c -o src/affichage/jeu.o
src/affichage/menu.o: src/affichage/menu.c gfx/GfxLib.h gfx/BmpLib.h gfx/ESLib.h
	gcc -Wall -c src/affichage/menu.c -o src/affichage/menu.o
src/affichage/fin.o: src/affichage/fin.c gfx/GfxLib.h gfx/BmpLib.h gfx/ESLib.h
	gcc -Wall -c src/affichage/fin.c -o src/affichage/fin.o

# Temporisation
src/temporisation/jeu.o: src/temporisation/jeu.c gfx/GfxLib.h gfx/BmpLib.h gfx/ESLib.h
	gcc -Wall -c src/temporisation/jeu.c -o src/temporisation/jeu.o
src/temporisation/menu.o: src/temporisation/menu.c gfx/GfxLib.h gfx/BmpLib.h gfx/ESLib.h
	gcc -Wall -c src/temporisation/menu.c -o src/temporisation/menu.o
src/temporisation/fin.o: src/temporisation/fin.c gfx/GfxLib.h gfx/BmpLib.h gfx/ESLib.h
	gcc -Wall -c src/temporisation/fin.c -o src/temporisation/fin.o

# Entrees
src/entrees/jeu.o: src/entrees/jeu.c gfx/GfxLib.h gfx/BmpLib.h gfx/ESLib.h
	gcc -Wall -c src/entrees/jeu.c -o src/entrees/jeu.o
src/entrees/menu.o: src/entrees/menu.c gfx/GfxLib.h gfx/BmpLib.h gfx/ESLib.h
	gcc -Wall -c src/entrees/menu.c -o src/entrees/menu.o
src/entrees/fin.o: src/entrees/fin.c gfx/GfxLib.h gfx/BmpLib.h gfx/ESLib.h
	gcc -Wall -c src/entrees/fin.c -o src/entrees/fin.o