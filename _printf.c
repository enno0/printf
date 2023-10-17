#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", pf_string}, {"%c", pf_character},
		{"%%", pf_per_cent_sign_37},
		{"%i", pf_integer}, {"%d", pf_decimal}, {"%r", pf_string_reverse},
		{"%R", pf_rot_13}, {"%b", pf_binary}, {"%u", pf_unsigned},
		{"%o", pf_octal}, {"%x", pf_hex_decimal}, {"%X", pf_HEX_decimal},
		{"%S", pf_exclusive_string}, {"%p", pf_pointer}
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
