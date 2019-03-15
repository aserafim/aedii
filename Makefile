testa:testa.o
	gcc -o testa testa.o
testa.o:testa.c grafo_matrizadj.h
	gcc -O -c testa.c
testa2:testa2.o
	gcc -o testa2 testa2.o
testa2.o:testa2.c grafo_listaadj.h
	gcc -O -c testa2.c
clean:
	rm -f testa testa.o testa2 testa2.o
