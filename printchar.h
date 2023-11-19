#ifndef PRINTCHAR_H
#define PRINTCHAR_H

#include"main.h"

/**
 * print_char - Print a character.
 * @ch: The character to print.
 *
 * Return: Number of characters printed.
 */
int print_char(char ch)
{
	write(1, &ch, 1);
	return (1);
}
#endif /* PRINTCHAR_H */
