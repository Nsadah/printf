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
	va_list arg_list;
	int i_fmt, i_struct, flag, ret_val, ret_flag;
	fmt_chars p_fmt[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_int},
		{"b", print_binary},
		{NULL, NULL}
	};

	flag = 0;
	ret_val = 0;
	va_start(arg_list, format);

	for (i_fmt = 0; format != NULL && format[i_fmt] != '\0'; i_fmt++)
	{
		if (format[i_fmt] == '%' && format[i_fmt + 1] != '%')
		{
			for (i_struct = 0; i_struct < 5; i_struct++)
			{
				if (format[i_fmt + 1] == *p_fmt[i_struct].id)
				{
					ret_flag = p_fmt[i_struct].f(arg_list);
					if (ret_flag == -1)
						return (-1);
					ret_val += ret_flag;
					flag = 1;
					i_fmt++;
				}
			}
			if (flag == 0)
			{
				ret_flag = _putchar(format[i_fmt]);
				if (ret_flag == -1)
					return (-1);
				ret_val += ret_flag;
			}
		}
		else if (format[i_fmt] == '%' && format[i_fmt + 1] == '%')
		{
			ret_flag = _putchar('%');
			if (ret_flag == -1)
				return (-1);
			ret_val += ret_flag;
			i_fmt++;
		}
		else
		{
			ret_flag = _putchar(format[i_fmt]);
			if (ret_flag == -1)
				return (-1);
			ret_val += ret_flag;
		}
	}
	va_end(arg_list);
	if (format == NULL)
		return (-1);
	return (ret_val);
}
