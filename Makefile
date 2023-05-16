app: main.o lib.o strings.o
	gcc -Wall -O0 -g  -o app strings.o lib.o main.o 
main.o: main.c
	gcc -Wall -O0 -g  -c -o main.o main.c
lib.o: lib.c
	gcc -Wall -O0 -g  -c -o lib.o lib.c
strings.o: string.c
	gcc -Wall -O0 -g -c -o strings.o string.c

clean: 
	rm *.o
