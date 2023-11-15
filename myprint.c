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
					else
					{
						const char *null_str = "(null)";
						write(1, null_str, strlen(null_str));
						print_c += strlen(null_str);
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
				case 'd':
				{
					int num = va_arg(args, int);
					char num_str[100];
					int len = 0;
					while (num != 0)
					{
						num_str[len++] = '0' + num % 10;
						num /= 10;
					}

					while (len > 0)
					{
						write(1, &num_str[--len], 1);
						print_c++;
					}
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

		format++;
	}

	va_end(args);

	return print_c;
}
