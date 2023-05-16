#include <stdio.h>
#include <stdlib.h>

#include "lib.h"
#include "strings.h"

char *input(char *argument)
{
    scanf("%s", argument);
    return argument;
}

int symbols_check(char *argument)
{
    for (char *a = argument; *a != '\0'; a++)
    {
    	if ((*a == '\\')||(*a == ':')||(*a == '*')||(*a == '?')||(*a == '<')||(*a == '>')||(*a == '|')||(*a == '«'))
    	    return -1;
    }
    return 0;
}

int check(char *argument)
{
    if (symbols_check(argument) != 0){
   	printf("Некорректные символы в пути");
	return -1;
    }
    if (slen(argument) > MAX_PATH){
        printf("Превышена максимальная длинна пути");
	return -1;
    }
    return 0;
}

int output(char *str)
{
    if (printf("%s\n", str) != 0)
        return 0;
    else
        return -1;
}

char* process(char* tmp, char* result){
    if(check_cygwin(tmp)==1){
    	for(int i=0;i<9;i++)
	    delchar(tmp);
    	s_upper(tmp);
    	tmp[slen(tmp)]='+';
	assembly(tmp);
    }
    else if(check_cygwin(tmp)==2){
    	for(int i=0;i<10;i++)
	    delchar(tmp);
    	s_upper(tmp);
    	tmp[slen(tmp)]='+';
	assembly(tmp);
    }
    scat(result, tmp);
    return result;
}

int check_cygwin(char* str){
    int flag;
    char data[]="cygdrive/";
    char data2[]="/cygdrive";
    for(int i=0;i<slen(data);i++){
	if(str[i]==data[i])
	    flag=1;
	else{
	    flag=0;
	    break;
	}
    }
    if(flag==0){
    	for(int i=0;i<slen(data);i++){
	    if(str[i]==data2[i])
	    	flag=2;
	    else{
	    	flag=0;
	        break;
	    }
	}
    }
    return flag;
}

char* assembly(char* str){
    char data[MAX_PATH];
    scpy(str,data);
    int size=slen(str);
    for(int i=0;i<size;i++){
	if(str[i]=='/'){
	    str[i]='\\';
	}
	str[i+1]=data[i];
    }
    str[1]=':';
    return str;
}
