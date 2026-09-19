FLAGS = -std=c99 -Wall -Wpedantic

all: programa

programa:
	gcc main.o lista.o celula.o horario.o $(FLAGS) -o programa

horario.o: horario.c horario.h
	gcc horario.c $(FLAGS) -c

celula.o: celula.c celula.h horario.h
	gcc celula.c $(FLAGS) -c

lista.o: lista.c lista.h celula.h horario.h
	gcc lista.c $(FLAGS) -c

main.o: main.c lista.h celula.h horario.h
	gcc main.c $(FLAGS) -c

run:
	./programa

clean:
	rm -f *.o programa
