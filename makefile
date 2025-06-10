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
