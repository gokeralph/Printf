#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>


/* FLAGS */
#define PRINTF_ZERO 4
#define PRINTF_HASH 8
#define PRINTF_MINUS 1
#define PRINTF_PLUS 2
#define PRINTF_SPACE 16

/* SIZES */
#define PRINTS_SHORT 1
#define PRINTS_LONG 2

#define NONUSED(y) (void)(y)
#define BUFFER_SIZE 1024


/**
 * struct fmt - Struct op
 *
 * @fmtt: The format.
 * @func: The function associated.
 */
struct fmtt
{
	char fmtt;
	int (*f)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmtt fmtt_t;

int _printf(const char *format, ...);
int printf_handler(const char *fmtt, int *i,
va_list list, char letter[], int flags, int width, int precision, int letter_size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int printf_character(va_list types, char letter[],
	int flags, int width, int precision, int letter_size);
int printf_string(va_list types, char letter[],
	int flags, int width, int precision, int letter_size);
int printf_percentage(va_list types, char letter[],
	int flags, int width, int precision, int letter_size);

/* Functions to print numbers */
int printf_integer(va_list types, char letter[],
	int flags, int width, int precision, int letter_size);
int printf_binary(va_list types, char letter[],
	int flags, int width, int precision, int letter_size);
int printf_unsigned(va_list types, char letter[],
	int flags, int width, int precision, int letter_size);
int printf_octal(va_list types, char letter[],
	int flags, int width, int precision, int letter_size);
int printf_hexadecimal(va_list types, char letter[],
	int flags, int width, int precision, int letter_size);
int printf_hexa_upper(va_list types, char letter[],
	int flags, int width, int precision, int letter_size);

int printf_hexa(va_list types, char map_to[],
char letter[], int flags, char flag_ch, int width, int precision, int letter_size);

/* Function to print non printable characters */
int printf_non_printable(va_list types, char letter[],
	int flags, int width, int precision, int letter_size);

/* Funcion to print memory address */
int printf_pointer(va_list types, char letter[],
	int flags, int width, int precision, int letter_size);

/* Funciotns to handle other specifiers */
int printf_get_flags(const char *format, int *i);
int printf_get_width(const char *format, int *i, va_list list);
int printf_get_precision(const char *format, int *i, va_list list);
int printf_get_size(const char *format, int *i);

/*Function to print string in reverse*/
int printf_reverse(va_list types, char letter[],
	int flags, int width, int precision, int letter_size);

/*Function to print a string in rot 13*/
int printf_rot13string(va_list types, char letter[],
	int flags, int width, int precision, int letter_size);

/* width handler */
int writef_char_handler(char c, char letter[],
	int flags, int width, int precision, int letter_size);
int writef_number(int is_positive, int din, char letter[],
	int flags, int width, int precision, int letter_size);
int writef_num(int din, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int writef_pointer(char letter[], int din, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int writef_unsgnd(int is_negative, int din,
char letter[],
	int flags, int width, int precision, int letter_size);

/****************** UTILS ******************/
int is_printablef(char);
int append_hexa_codef(char, char[], int);
int is_digitf(char);

long int convert_number_size(long int number, int letter_size);
long int convert_unsigned_size(unsigned long int number, int letter_size);

#endif /* MAIN_H */

