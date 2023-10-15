#include "main.h"

/**
 * pf_character - prints a char.
 * @val: arguments.
 * Return: 1.
 */
int pf_character(va_list val)
{
	char s;

	s = va_arg(val, int);
	_putchar(s);
	return (1);
}
