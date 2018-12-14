main: main.c memcheck.h memcheck.o 
	gcc -Wall -ansi -pedantic -include memcheck.h main.c memcheck.o -o main

memcheck.o: memcheck.c
	gcc -Wall -ansi -pedantic -c memcheck.c -o memcheck.o

