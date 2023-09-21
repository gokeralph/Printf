#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * printf_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @letter: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @letter_size: Size specifier
 * Return: Number of chars printed.
 */
int printf_unsigned(va_list types, char letter[],
	int flags, int width, int precision, int letter_size)
{
	int j = BUFFER_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = convert_unsigned_size(number, letter_size);

	if (number == 0)
		letter[j--] = '0';

	letter[BUFFER_SIZE - 1] = '\0';

	while (number > 0)
	{
		letter[j--] = (number % 10) + '0';
		number /= 10;
	}

	j++;

	return (writef_unsgnd(0, j, letter, flags, width, precision, letter_size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * printf_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @letter: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @letter_size: Size specifier
 * Return: Number of chars printed
 */
int printf_octal(va_list types, char letter[],
	int flags, int width, int precision, int letter_size)
{

	int j = BUFFER_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int initial_num = number;

	NONUSED(width);

	number = convert_unsigned_size(number, letter_size);

	if (number == 0)
		letter[j--] = '0';

	letter[BUFFER_SIZE - 1] = '\0';

	while (number > 0)
	{
		letter[j--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & PRINTF_HASH && initial_num != 0)
		letter[j--] = '0';

	j++;

	return (writef_unsgnd(0, j, letter, flags, width, precision, letter_size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * printf_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @letter: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @letter_size: Size specifier
 * Return: Number of chars printed
 */
int printf_hexadecimal(va_list types, char letter[],
	int flags, int width, int precision, int letter_size)
{
	return (printf_hexa(types, "0123456789abcdef", letter,
		flags, 'x', width, precision, letter_size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * printf_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @letter: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @letter_size: Size specifier
 * Return: Number of chars printed
 */
int printf_hexa_upper(va_list types, char letter[],
	int flags, int width, int precision, int letter_size)
{
	return (printf_hexa(types, "0123456789ABCDEF", letter,
		flags, 'X', width, precision, letter_size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * printf_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @letter: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @letter_size: Size specifier
 * @letter_size: Size specification
 * Return: Number of chars printed
 */
int printf_hexa(va_list types, char map_to[], char letter[],
	int flags, char flag_ch, int width, int precision, int letter_size)
{
	int k = BUFFER_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int initial_num = number;

	NONUSED(width);

	number = convert_unsigned_size(number, letter_size);

	if (number == 0)
		letter[k--] = '0';

	letter[BUFFER_SIZE - 1] = '\0';

	while (number > 0)
	{
		letter[k--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & PRINTF_HASH && initial_num != 0)
	{
		letter[k--] = flag_ch;
		letter[k--] = '0';
	}

	k++;

	return (writef_unsgnd(0, k, letter, flags, width, precision, letter_size));
}
