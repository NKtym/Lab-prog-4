#include <stdio.h>
#include <stdlib.h>

#include "lib.h"
#include "string.h"

int main(){
	char* delim = malloc(1);
	char *paths = malloc(MAX_PATH * 12);
	char *tmp = malloc(MAX_PATH);
	input(delim);
	input(paths);
	tmp = stok(paths, delim);
	while(tmp != NULL){
		
	}
}
