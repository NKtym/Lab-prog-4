#include <stdio.h>
#include <stdlib.h>

#include "lib.h"
#include "strings.h"

int main(){
	char* delim = malloc(1);
	char *paths = malloc(MAX_PATH * 12);
	char *result = malloc(MAX_PATH * 12);
	char *tmp = malloc(MAX_PATH);
	printf("delim: ");
	input(delim);
	printf("paths: ");
	input(paths);
	tmp = stok(paths, delim);
	while(tmp != NULL){
		if(!check(tmp)){
			process(tmp,result);
		}
		else{
			return -1;
		}
		tmp = stok(NULL,delim);
	}
	printf("new paths: %s\n",result);
	free(delim);
	free(paths);
	free(tmp);
	return 0;
}
