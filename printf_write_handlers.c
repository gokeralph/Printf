{

	int length = BUFFER_SIZE - ind - 1, i = 0;
	char space = ' ';

	NONUSED(is_negative);
	NONUSED(letter_size);

	if (precision == 0 && ind == BUFFER_SIZE - 2 && letter[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		space = ' ';

	while (precision > length)
	{
		letter[--ind] = '0';
		length++;
	}

	if ((flags & PRINTF_ZERO) && !(flags & PRINTF_MINUS))
		space = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			letter[i] = space;

		letter[i] = '\0';

		if (flags & PRINTF_MINUS)
		{
			return (write(1, &letter[ind], length) + write(1, &letter[0], i));
		}
		else
		{
			return (write(1, &letter[0], i) + write(1, &letter[ind], length));
		}
	}

	return (write(1, &letter[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @letter: Arrays of chars
 * @ind: Index at which the number starts in the letter
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @space: Char representing the padding
 * @extra_c: Char representing extra char
 * @space_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int writef_pointer(char letter[], int ind, int length,
	int width, int flags, char space, char extra_c, int space_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			letter[i] = space;
		letter[i] = '\0';
		if (flags & PRINTF_MINUS && space == ' ')
		{
			letter[--ind] = 'x';
			letter[--ind] = '0';
			if (extra_c)
				letter[--ind] = extra_c;
			return (write(1, &letter[ind], length) + write(1, &letter[3], i - 3));
		}
		else if (!(flags & PRINTF_MINUS) && space == ' ')
		{
			letter[--ind] = 'x';
			letter[--ind] = '0';
			if (extra_c)
				letter[--ind] = extra_c;
			return (write(1, &letter[3], i - 3) + write(1, &letter[ind], length));
		}
		else if (!(flags & PRINTF_MINUS) && space == '0')
		{
			if (extra_c)
				letter[--space_start] = extra_c;
			letter[1] = '0';
			letter[2] = 'x';
			return (write(1, &letter[space_start], i - space_start) +
				write(1, &letter[ind], length - (1 - space_start) - 2));
		}
	}
	letter[--ind] = 'x';
	letter[--ind] = '0';
	if (extra_c)
		letter[--ind] = extra_c;
	return (write(1, &letter[ind], BUFFER_SIZE - ind - 1));
}
