#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include "printstring.h"
#include "printchar.h"
#include <limits.h>

int _printf(const char *format, ...);
int print_string(const char *str);
int print_char(char ch);

#endif /* MAIN_H */
