UNAME := $(shell uname)
# exemple: exemple.o libisentlib.a
# 	gcc -Wall exemple.o -o exemple libisentlib.a -lm -lglut -lGL -lX11
# # Sous macOS, commenter la ligne de commande ci-dessus (en mettant un # au debut)
# # et de-commenter la ligne de commande ci-apres :
# #	gcc -Wall exemple.o -o exemple libisentlib.a -lm -framework OpenGL -framework GLUT

# exempleTortue: exempleTortue.o libisentlib.a
# 	gcc -Wall exempleTortue.o -o exempleTortue libisentlib.a -lm -lglut -lGL -lX11
# # Sous macOS, commenter la ligne de commande ci-dessus (en mettant un # au debut)
# # et de-commenter la ligne de commande ci-apres :
# #	gcc -Wall exempleTortue.o -o exempleTortue libisentlib.a -lm -framework OpenGL -framework GLUT

# exemple.o: exemple.c GfxLib.h BmpLib.h ESLib.h
# 	gcc -Wall -c exemple.c

# exempleTortue.o: exempleTortue.c GfxLib.h BmpLib.h ESLib.h TortueLib.h
# 	gcc -Wall -c exempleTortue.c


libisentlib.a: BmpLib.o ErreurLib.o ESLib.o GfxLib.o OutilsLib.o SocketLib.o ThreadLib.o TortueLib.o VectorLib.o WavLib.o
	ar r libisentlib.a BmpLib.o ErreurLib.o ESLib.o GfxLib.o OutilsLib.o SocketLib.o ThreadLib.o TortueLib.o VectorLib.o WavLib.o
	ranlib libisentlib.a

BmpLib.o: BmpLib.c BmpLib.h OutilsLib.h
	gcc -Wall -O2 -c BmpLib.c

ESLib.o: ESLib.c ESLib.h ErreurLib.h
	gcc -Wall -O2 -c ESLib.c

ErreurLib.o: ErreurLib.c ErreurLib.h
	gcc -Wall -O2 -c ErreurLib.c

GfxLib.o: GfxLib.c GfxLib.h ESLib.h
ifeq ($(UNAME), Darwin)
	gcc -Wall -O2 -c GfxLib.c -Wno-deprecated-declarations
else
	gcc -Wall -O2 -c GfxLib.c -I/usr/include/GL
endif

OutilsLib.o: OutilsLib.c OutilsLib.h
	gcc -Wall -O2 -c OutilsLib.c

SocketLib.o: SocketLib.c SocketLib.h
	gcc -Wall -O2 -c SocketLib.c

ThreadLib.o: ThreadLib.c ThreadLib.h
	gcc -Wall -O2 -c ThreadLib.c

TortueLib.o: TortueLib.c TortueLib.h GfxLib.h
	gcc -Wall -O2 -c TortueLib.c

WavLib.o: WavLib.c WavLib.h OutilsLib.h
ifeq ($(UNAME), Darwin)
	gcc -Wall -O2 -c WavLib.c
else
	gcc -Wall -O2 -c WavLib.c -Wno-unused-result
endif

zip:
	zip libisentlib.zip *.[ch] *.bmp *.pdf makefile
#	tar -cvzf libisentlib.tgz *.[ch] *.bmp *.pdf makefile

clean:
	rm -f *~ *.o libisentlib.a

deepclean: clean
	rm -f exemple exempleTortue libisentlib.a

