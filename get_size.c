#include "main.h"

/**
 * get_size - claculates the size to cast the argument
 * @format: formated string in which to print the arg
 * @i: list of arg to be printed
 *
 * Return: size
 */

int get_size(const char *format, int *i)
{
	int curr_i = *i + 1, size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;
	return (size);
}
