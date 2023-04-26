#include "main.h"

/**
 * _printf - printf
 * @format: input
 * Return: integer
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int i, printed = 0, printed_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_char++;
		} else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, ap);
			precision = get_precision(format, &i, ap);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, ap, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_char += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(ap);
	return (printed_char);
}

/**
 * print_buffer - print the content of the buffer if it exist
 * @buffer: array of char
 * @buff_ind: index at wich to add next char, represents the lenght
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
