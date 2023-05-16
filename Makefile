app: main.o lib.o string.o
	gcc -Wall -O0 -g  -o app string.o lib.o main.o 
main.o: main.c
	gcc -Wall -O0 -g  -c -o main.o main.c
lib.o: lib.c
	gcc -Wall -O0 -g  -c -o lib.o lib.c
string.o: string.c
	gcc -Wall -O0 -g -c -o string.o string.c

clean: 
	rm *.o
