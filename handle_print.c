#include "main.h"

int print_unknown(const char *fmt, int *ind, char buffer[], int flags);

int is_known_format(char fmt_char);

int print_known_format(char fmt_char, va_list list, char buffer[], int flags,
		int width, int precision, int size);

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: Index.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	char fmt_char = fmt[*ind];

	if (is_known_format(fmt_char))
	{
		return (print_known_format(fmt_char, list, buffer, flags,
				width, precision, size));
	}
	else if (fmt_char != '\0')
	{
		return (print_unknown(fmt, ind, buffer, flags));
	}

	return (-1);
}

/**
 * is_known_format - Checks if a format character is known
 * @fmt_char: Format character to check.
 * Return: 1 if known, 0 otherwise.
 */
int is_known_format(char fmt_char)
{
	const char known_formats[] = "cs%idbuoxXpSrR";

	for (int i = 0; known_formats[i] != '\0'; i++)
	{
		if (fmt_char == known_formats[i])
		{
			return (1);
		}
	}

	return (0);
}

/**
 * print_known_format - Prints a known format character
 * @fmt_char: Format character to print.
 * @list: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */

int print_known_format(char fmt_char, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	for (int i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt_char == fmt_types[i].fmt)
		{
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
		}
	}

	return (-1); This should never be reached.
}

/**
 * print_unknown - Prints an unknown format character
 * @fmt: Formatted string in which to print the arguments.
 * @ind: Index.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * Return: Number of characters printed.
 */
int print_unknown(const char *fmt, int *ind, char buffer[], int flags)
{
	int unknown_len = write(1, "%%", 1);

	if (fmt[*ind - 1] == ' ')
	{
		unknown_len += write(1, " ", 1);
	}
	else if (flags & F_ZERO)
	{
		(*ind)--;
		while (fmt[*ind] != ' ' && fmt[*ind] != '%')
		{
			(*ind)--;
		}
		if (fmt[*ind] == ' ')
		{
			(*ind)--;
		}
		return (1);
	}
	unknown_len += write(1, &fmt[*ind], 1);
	return (unknown_len);
}
