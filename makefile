UNAME := $(shell uname)

exemple: exemple.o ./gfx/libisentlib.a
ifeq ($(UNAME), Darwin)
	gcc -Wall exemple.o -o exemple gfx/libisentlib.a -lm -framework OpenGL -framework GLUT
else
	gcc -Wall exemple.o -o exemple gfx/libisentlib.a -lm -lglut -lGL -lX11
endif

gfx/libisentlib.a:
	echo "Building libisentlib.a..."
	cd gfx && make && cd ..