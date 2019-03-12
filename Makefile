testa:testa.o
	gcc -o testa testa.o
testa.o:testa.c grafo_matrizadj.h
	gcc -O -c testa.c
clean:
	rm -f testa testa.o
