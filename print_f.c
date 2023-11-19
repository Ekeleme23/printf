#include "main.h"

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
			write(1, format, 1);
			print_c++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				print_c++;
			}
			else
			{
				switch (*format)
				{
				case 's':
				{
					const char *str = va_arg(args, const char *);
					if (str != NULL)
					{
						write(1, str, strlen(str));
						print_c += strlen(str);
					}
					break;
				}
				case 'c':
				{
					char ch = va_arg(args, int);
					write(1, &ch, 1);
					print_c++;
					break;
				}
				default:
				{
					write(1, format - 1, 2);
					print_c += 2;
					break;
				}
				}
			}
		}

		format++;
	}

	va_end(args);

	return (print_c);
}

