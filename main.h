#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);
void printError(const char *message);
void my_write(const char message);
void print_integer(int n);
int _putchar(char c);

#endif /*MAIN_H*/
