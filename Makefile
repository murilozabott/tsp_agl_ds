all: main.c lista.c
	gcc main.c lista.c -o main
run:
	./main