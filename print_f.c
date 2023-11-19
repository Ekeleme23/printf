#include "main.h"
#include <unistd.h>

/**
* _printf - Custom printf function with support for %s, %c, and %% formats.
* @format: The format string.
*
* Return: The number of characters printed (excluding null byte).
*/
int _printf(const char *format, ...)
{
	int print_c = 0;

	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			print_c += print_char(*format);
		}
		else
		{
		format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				print_c += print_char('%');
			}
			else
			{
				switch (*format)
				{
				case 's':
					print_c += print_string(va_arg(args, const char *));
					break;
				case 'c':
					print_c += print_char(va_arg(args, int));
					break;
				default:
					print_c += write(1, format - 1, 2);
					break;
				}
			}
		}
		format++;
	}
	va_end(args);
	return (print_c);
}

