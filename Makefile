all: main.c lista.c caminho.c
	gcc main.c lista.c caminho.c -o main
run:
	./main