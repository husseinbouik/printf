#include "main.h"

/**
 * get_precision - calculate the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: list of arg to be printed
 * @ap: list of arg
 * Return: precision
 */

int get_precision(const char *format, int *i, va_list ap)
{
	int curr_i = *i + 1, precision = -1;

	if (format[curr_i] != '.')
		return (precision);
	precision = 0;
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(ap, int);
			break;
		}
		else
			break;
	}
	*i = curr_i - 1;
	return (precision);
}
