UNAME := $(shell uname)

BUILDDIR := ./src/build


SRC := ./src
SRCFILES := tetris.c initialisation.c tetrominos.c \
	affichage/jeu.c affichage/menu.c affichage/fin.c \
	temporisation/jeu.c temporisation/menu.c temporisation/fin.c \
	entrees/jeu.c entrees/menu.c entrees/fin.c
OBJFILES := $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCFILES))

all: $(BUILDDIR) gfx/libisentlib.a tetris

tetris: $(OBJFILES) gfx/libisentlib.a 
ifeq ($(UNAME), Darwin)
	gcc -Wall $@ $^ gfx/libisentlib.a -lm -framework OpenGL -framework GLUT
else
	gcc -Wall $@ $^ gfx/libisentlib.a -lm -lglut -lGL -lX11
endif

$(BUILDDIR):
	mkdir $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRC)/%.c
	gcc -Wall -o $(BUILDDIR)/%.o -c $< -Wno-unused-result

# GFXLIB
gfx/libisentlib.a:
	@echo "Building libisentlib.a..."
	@cd gfx && make && cd ..

clean:
	make clean gfx/
	rm -f $(BUILDDIR)/*.o
	rm -fr $(BUILDDIR)
	rm -f tetris