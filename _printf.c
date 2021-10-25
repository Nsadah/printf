#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - prints any string with certain flags for modification
 * @format: the string of characters to write to buffer
 * Return: an integer that counts how many writes to the buffer were made
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	int (*function)(va_list) = NULL;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			format++;
			
			if (*(format) == '\0')
				return (-1);
			else if (function == NULL)
			{
				_putchar(*(format - 1));
				_putchar(*format);
				count += 2;
			}
			else
				count += function(args);
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			format++;
			_putchar('%');
			count++;
		}
		else
		{
			_putchar(*format);
			
		}
		return (*format);
		
	}
	va_end(args);
	return (count);
}
