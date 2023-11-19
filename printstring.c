#ifndef PRINTSTRING_H
#define PRINTSTRING_H

#include "main.h"
#include <string.h>
#include <unistd.h>

/**
* print_string - Print a string.
* @str: The string to print.
*
* Return: Number of characters printed.
*/
int print_string(const char *str)
{
	int len = 0;

	if (str != NULL)
	{
		write(1, str, strlen(str));
		len = strlen(str);
	}
	return (len);
}

#endif /* PRINTSTRING_H */
