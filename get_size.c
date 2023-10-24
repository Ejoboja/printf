#include "main.h"

/**
 * get_size - Calculates the size specifier for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to an integer that tracks the position in the format string
 *
 * Return: Size specifier.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'h' || format[curr_i] == 'l')
	{
		if (format[curr_i] == 'h' && format[curr_i + 1] == 'h')
		{
			size = SIZE_HH;
			curr_i++;
		}
		else if (format[curr_i] == 'l' && format[curr_i + 1] == 'l')
		{
			size = SIZE_LL;
			curr_i++;
		}
		else if (format[curr_i] == 'h')
		{
			size = SIZE_H;
		}
		else if (format[curr_i] == 'l')
		{
			size = SIZE_L;
		}
	}
	*i = curr_i;
	return (size);
}
