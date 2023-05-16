#include <stdio.h>

#include "string.h"

size_t slen(char *str)//+
{
    size_t len = 0;
    for (int i = 0; str[i] != '\0'; i++)
        len++;
    return len;
}
char* stok(char *str, char *delim)//+
{
    static char *p;
    if (!str)
    {
        str = p;
    }
    if (!str)
    {
        return NULL;
    }
    while (1)
    {
        if (is_del(*str, delim))
        {
            str++;
            continue;
        }
        if (*str == '\0')
        {
            return NULL;
        }
        break;
    }
    char *ret = str;
    while (1)
    {
        if (*str == '\0')
        {
            p = str;
            return ret;
        }
        if (is_del(*str, delim))
        {
            *str = '\0';
            p = str + 1;
            return ret;
        }
        str++;
    }
}

/*void suntok(char* str, char* delim; char** ptr; int cnt){
    for(int i = 1; i < cnt; i++){
	*(ptr[i]-1)=delim;
    }
}
*/

int scmp(char *str1, char *str2)//+
{
    while (*str1)
    {
        if (*str1 != *str2)
            break;
        str1++;
        str2++;
    }
    if((*str1 - *str2)>0)
	return 1;
    else if((*str1 - *str2)<0)
	return -1;
    return 0;
}

char *scpy(char *str1, char *str2)//+
{
    if (str1 == NULL)
    {
        return NULL;
    }
    int len = slen(str1);
    for(int i = 0; i < len; i++){
	str2[i] = str1[i];
    }
    str2[len] = '\0';
    return str2;
}

char *schr(char *str, char c)//+
{
    while (*str != c && *str != '\0')
        str++;
    if (*str == c)
        return str;
    else
        return NULL;
}

int is_del(char c, char *delim)//+
{
    while (*delim != '\0')
    {
        if (c == *delim)
            return 1;
        delim++;
    }
    return 0;
}
