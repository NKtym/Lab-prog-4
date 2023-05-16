#pragma once

#define MAX_PATH 260

char *input(char *argument);

char *check(char *argument, char **error);

int output(char *str);

int symbols_check(char *argument);
