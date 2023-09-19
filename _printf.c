#include "main.h"

/**
  * _printf - writes the character c to stdout
  * @format: The character to print
  *Return: count of strings printed
  */


int _printf(const char *format, ...)
{
	int char_printed = 0;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
	{
	printError("You cannot print % alone");
	return (-1);
	}
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			my_write(*format);
			char_printed++;
		}
		else
		{
			format++;
			if (*format == '%')
			{
			my_write('%');
			char_printed++;
			}
			else if (*format == 'c')
			{
				char x = va_arg(args, int);

				my_write(x);
				char_printed++;
			}
			else if (*format == 's')
			{
				char *y = va_arg(args, char*);

				char_printed += strlen(y);
				write(1, y, strlen(y));
			}
			else if (*format == 'i' || *format == 'd')
			{
				char buffer[12];
				int x = va_arg(args, int);

				snprintf(buffer, 12, "%d", x);
				write(1, buffer, strlen(buffer));
				char_printed++;
			}
		}
		va_end(args);

		format++;

	}
	return (char_printed);
}
