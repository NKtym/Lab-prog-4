#pragma once

#define MAX_PATH 260

char *input(char *argument);
int check(char *argument);
int output(char *str);
int symbols_check(char *argument);
char* process(char* tmp, char* result);
int check_cygwin(char* str);
char* assembly(char* str1);
