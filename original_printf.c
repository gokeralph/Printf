#include "main.h"

void printf_buffer(char letter[], int *lett_nid);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, what_is_printed = 0, printed_characters = 0;
	int flags, width, precision, letter_size, lett_nid = 0;
	va_list args_list;
	char letter[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args_list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			letter[lett_nid++] = format[i];
			if (lett_nid == BUFFER_SIZE)
				printf_buffer(letter, &lett_nid);
			/* write(1, &format[i], 1);*/
			printed_characters++;
		}
		else
		{
			printf_buffer(letter, &lett_nid);
			flags = printf_get_flags(format, &i);
			width = printf_get_width(format, &i, args_list);
			precision = printf_get_precision(format, &i, args_list);
			letter_size = printf_get_size(format, &i);
			++i;
			what_is_printed = printf_handler(format, &i, args_list, letter,
				flags, width, precision, letter_size);
			if (what_is_printed == -1)
				return (-1);
			printed_characters += what_is_printed;
		}
	}

	printf_buffer(letter, &lett_nid);

	va_end(args_list);

	return (printed_characters);
}

/**
 * printf_buffer - Prints the contents of the letter if it exist
 * @letter: Array of chars
 * @lett_nid: Index at which to add next char, represents the length.
 */
void printf_buffer(char letter[], int *lett_nid)
{
	if (*lett_nid > 0)
		write(1, &letter[0], *lett_nid);

	*lett_nid = 0;
}
