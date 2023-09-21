#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * printf_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @letter: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @letter_size: Size specifier
 * Return: Number of chars printed.
 */
int printf_pointer(va_list types, char letter[],
	int flags, int width, int precision, int letter_size)
{
	char more_character = 0, space = ' ';
	int din = BUFFER_SIZE - 2, len = 2, space_beginning = 1; /* len=2, for '0x' */
	unsigned long number_adress;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	NONUSED(width);
	NONUSED(letter_size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	letter[BUFFER_SIZE - 1] = '\0';
	NONUSED(precision);

	number_adress = (unsigned long)address;

	while (number_adress > 0)
	{
		letter[din--] = map_to[number_adress % 16];
		number_adress /= 16;
		len++;
	}

	if ((flags & PRINTF_ZERO) && !(flags & PRINTF_MINUS))
		space = '0';
	if (flags & PRINTF_PLUS)
		more_character = '+', len++;
	else if (flags & PRINTF_SPACE)
		more_character = ' ', len++;

	din++;

	/*return (write(1, &letter[i], BUFFER_SIZE - i - 1));*/
	return (writef_pointer(letter, din, len,
		width, flags, space, more_character, space_beginning));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * printf_non_printable - Prints ascii codes inner hexa of non printable chars
 * @types: Lista of arguments
 * @letter: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @letter_size: Size specifier
 * Return: Number of chars printed
 */
int printf_non_printable(va_list types, char letter[],
	int flags, int width, int precision, int letter_size)
{
	int k = 0, offset = 0;
	char *character = va_arg(types, char *);

	NONUSED(flags);
	NONUSED(width);
	NONUSED(precision);
	NONUSED(letter_size);

	if (character == NULL)
		return (write(1, "(null)", 6));

	while (character[k] != '\0')
	{
		if (is_printablef(character[k]))
			letter[k + offset] = character[k];
		else
			offset += append_hexa_codef(character[k], letter, k + offset);

		k++;
	}

	letter[k + offset] = '\0';

	return (write(1, letter, k + offset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @letter: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @letter_size: Size specifier
 * Return: Numbers of chars printed
 */

int printf_reverse(va_list types, char letter[],
	int flags, int width, int precision, int letter_size)
{
	char *character;
	int l, sum = 0;

	NONUSED(letter);
	NONUSED(flags);
	NONUSED(width);
	NONUSED(letter_size);

	character = va_arg(types, char *);

	if (character == NULL)
	{
		NONUSED(precision);

		character = ")Null(";
	}
	for (l = 0; character[l]; l++)
		;

	for (l = l - 1; l >= 0; l--)
	{
		char z = character[l];

		write(1, &z, 1);
		sum++;
	}
	return (sum);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @letter: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @letter_size: Size specifier
 * Return: Numbers of chars printed
 */
int printf_rot13string(va_list types, char letter[],
	int flags, int width, int precision, int letter_size)
{
	char y;
	char *character;
	unsigned int a, b;
	int sum = 0;
	char inner[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char outer[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	character = va_arg(types, char *);
	NONUSED(letter);
	NONUSED(flags);
	NONUSED(width);
	NONUSED(precision);
	NONUSED(letter_size);

	if (character == NULL)
		character = "(AHYY)";
	for (a = 0; character[a]; a++)
	{
		for (b = 0; inner[b]; b++)
		{
			if (inner[b] == character[a])
			{
				y = outer[b];
				write(1, &y, 1);
				sum++;
				break;
			}
		}
		if (!inner[b])
		{
			y = character[a];
			write(1, &y, 1);
			sum++;
		}
	}
	return (sum);
}
