#include "main.h"

/**
 * print_binary - Prints the binary representation of an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array to handle printing
 * @flags: Calculates active flags
 * @width: Get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];

	int countnum;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, countnum = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			countnum++;
		}
	}
	return (countnum);
}
