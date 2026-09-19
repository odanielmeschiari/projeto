FLAGS = -std=c99 -Wall -Wpedantic
CC = gcc

all: programa

programa:
	$(CC) main.o lista.o celula.o horario.o $(FLAGS) -o programa

horario.o: horario.c horario.h
	$(CC) horario.c $(FLAGS) -c

celula.o: celula.c celula.h horario.h
	$(CC) celula.c $(FLAGS) -c

lista.o: lista.c lista.h celula.h horario.h
	$(CC) lista.c $(FLAGS) -c

main.o: main.c lista.h celula.h horario.h
	$(CC) main.c $(FLAGS) -c

run:
	./programa

clean:
	rm -f *.o programa
