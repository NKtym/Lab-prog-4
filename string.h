#pragma once

#include <stdio.h>

size_t slen(char *str);

int scmp(char *str1, char *str2);

char *scpy(char *str1, char *str2);

char* stok(char *str, char *delim);

char *schr(char *str, char c);

int is_del(char c, char *delim);
