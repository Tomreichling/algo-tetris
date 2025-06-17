UNAME := $(shell uname)

BUILDDIR := ./build
SRC := ./src

# Les fichiers sources
SRCFILES := tetris.c tetrominos.c outils.c animations.c \
	affichage/jeu.c affichage/identification.c affichage/menu.c affichage/fin.c \
	temporisation/jeu.c temporisation/menu.c temporisation/fin.c \
	entrees/jeu.c entrees/menu.c entrees/fin.c

# On trouve les fichiers objets à partir des fichiers sources
OBJFILES := $(patsubst %.c, $(BUILDDIR)/%.o, $(SRCFILES))

# Toutes les règles à suivre lors d'un make
all: $(BUILDDIR) $(BUILDDIR)/affichage $(BUILDDIR)/entrees $(BUILDDIR)/temporisation \
	gfx/libisentlib.a tetris -lpthread

# Commande pour faire le jeu
tetris: $(OBJFILES) gfx/libisentlib.a 
ifeq ($(UNAME), Darwin) # Version macos
	gcc -Wall -o $@ $^ -lm -framework OpenGL -framework GLUT -lpthread
else # Version linux
	gcc -Wall -o $@ $^ -lm -lglut -lGL -lX11 -lpthread
endif

# Création des dossiers (ils ne se créent pas tout seuls)
$(BUILDDIR):
	mkdir $(BUILDDIR)
$(BUILDDIR)/affichage:
	mkdir $(BUILDDIR)/affichage
$(BUILDDIR)/entrees:
	mkdir $(BUILDDIR)/entrees
$(BUILDDIR)/temporisation:
	mkdir $(BUILDDIR)/temporisation

# On transforme les fichiers sources en fichiers objets
$(BUILDDIR)/%.o: $(SRC)/%.c
	gcc -Wall -o $@ -c $< -Wno-unused-result

# GFXLIB (on compile la librairie)
gfx/libisentlib.a:
	@echo "Building libisentlib.a..."
	@cd gfx && make && cd ..

# On nettoie les fichiers objets et les programmes
clean:
	cd gfx && make clean && cd .. 
	
	rm -rf $(BUILDDIR)
	rm -f tetris