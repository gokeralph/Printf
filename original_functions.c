#include "main.h"

/**
 * printf_character - Prints a char
 * @types: arguments_lists
 * @letter: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @letter_size: Size specifier
 * Return: Number of characters printed
 */
int printf_character(va_list types, char letter[],
	int flags, int width, int precision, int letter_size)
{
	char s = va_arg(types, int);

	return (writef_char_handler(s, letter, flags, width, precision, letter_size));
}

/**
 * printf_string - Prints a string
 * @types: List a of arguments list
 * @letter: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @letter_size: Size specifier
 * Return: Number of chars printed
 */
int printf_string(va_list types, char letter[],
	int flags, int width, int precision, int letter_size)
{
	int len = 0, i;
	char *str = va_arg(types, char *);

	NONUSED(letter);
	NONUSED(flags);
	NONUSED(width);
	NONUSED(precision);
	NONUSED(letter_size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & PRINTF_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
 * printf_percentage - percent sign printer
 * @types: Lista of arguments
 * @letter: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @letter_size: Size specifier
 * Return: Number of chars printed
 */
int printf_percentage(va_list types, char letter[],
	int flags, int width, int precision, int letter_size)
{
	NONUSED(types);
	NONUSED(letter);
	NONUSED(flags);
	NONUSED(width);
	NONUSED(precision);
	NONUSED(letter_size);
	return (write(1, "%%", 1));
}

/**
 * printf_integer - Print integers
 * @types: Lista of arguments
 * @letter: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @letter_size: Size specifier
 * Return: Number of chars printed
 */
int printf_integer(va_list types, char letter[],
	int flags, int width, int precision, int letter_size)
{
	int j = BUFFER_SIZE - 2;
	int neg = 0;
	long int number_list = va_arg(types, long int);
	unsigned long int num;

	number_list = convert_number_size(number_list, letter_size);

	if (number_list == 0)
		letter[j--] = '0';

	letter[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)number_list;

	if (number_list < 0)
	{
		num = (unsigned long int)((-1) * number_list);
		neg = 1;
	}

	while (num > 0)
	{
		letter[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (writef_number(neg, j, letter, flags, width, precision, letter_size));
}

/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @letter: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @letter_size: Size specifier
 * Return: Numbers of char printed.
 */
int printf_binary(va_list types, char letter[],
	int flags, int width, int precision, int letter_size)
{
	unsigned int p, q, i, sum;
	unsigned int a[32];
	int count;

	NONUSED(letter);
	NONUSED(flags);
	NONUSED(width);
	NONUSED(precision);
	NONUSED(letter_size);

	p = va_arg(types, unsigned int);
	q = 2147483648; /* (2 ^ 31) */
	a[0] = p / q;
	for (i = 1; i < 32; i++)
	{
		q /= 2;
		a[i] = (p / q) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
