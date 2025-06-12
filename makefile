UNAME := $(shell uname)

BUILDDIR := ./build
SRC := ./src
SRCFILES := tetris.c tetrominos.c outils.c \
	affichage/jeu.c affichage/menu.c affichage/fin.c \
	temporisation/jeu.c temporisation/menu.c temporisation/fin.c \
	entrees/jeu.c entrees/menu.c entrees/fin.c
OBJFILES := $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCFILES))

all: $(BUILDDIR) $(BUILDDIR)/affichage $(BUILDDIR)/entrees $(BUILDDIR)/temporisation \
	gfx/libisentlib.a tetris -lpthread

tetris: $(OBJFILES) gfx/libisentlib.a 
ifeq ($(UNAME), Darwin)
	gcc -Wall -o $@ $^ -lm -framework OpenGL -framework GLUT -lpthread
else
	gcc -Wall -o $@ $^ -lm -lglut -lGL -lX11 -lpthread
endif

$(BUILDDIR):
	mkdir $(BUILDDIR)
$(BUILDDIR)/affichage:
	mkdir $(BUILDDIR)/affichage
$(BUILDDIR)/entrees:
	mkdir $(BUILDDIR)/entrees
$(BUILDDIR)/temporisation:
	mkdir $(BUILDDIR)/temporisation

$(BUILDDIR)/%.o: $(SRC)/%.c
	gcc -Wall -o $@ -c $< -Wno-unused-result

# GFXLIB
gfx/libisentlib.a:
	@echo "Building libisentlib.a..."
	@cd gfx && make && cd ..

clean:
	cd gfx && make clean && cd ..
	rm -rf $(BUILDDIR)
	rm -f tetris