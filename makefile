UNAME := $(shell uname)

tetris: tetris.o ./gfx/libisentlib.a
ifeq ($(UNAME), Darwin)
	gcc -Wall tetris.o -o tetris gfx/libisentlib.a -lm -framework OpenGL -framework GLUT
else
	gcc -Wall tetris.o -o tetris gfx/libisentlib.a -lm -lglut -lGL -lX11
endif

gfx/libisentlib.a:
	echo "Building libisentlib.a..."
	cd gfx && make && cd ..