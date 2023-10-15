#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 *
 */

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

/**
 * struct parameters - Handle the following flag characters for non-custom conversion specifiers
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if _flag specified
 * @hashtag_flag: on if hashtag_flag specified
 *
 * @width: field width specified 
 * @precision: field precision specified
 *
 */


typedef struct parameters
{
	unsigned int plus_flag	:1;
	unsigned int space_flag  :1;
	unsigned int hashtag_flag  :1;
	unsigned int zero_flag  :1;
	unsigned int minus_flag  :1;

	unsigned int width;
	unsigned int precision;

}parms_t;

int pf_pointer(va_list val);
int printf_hex_aux(unsigned long int num);
int printf_HEX_aux(unsigned int num);
int pf_exclusive_string(va_list val);
int pf_HEX_decimal(va_list val);
int pf_hex_decimal(va_list val);
int pf_octal(va_list val);
int pf_unsigned(va_list args);
int pf_binary(va_list val);
int pf_string_reverse(va_list args);
int pf_rot_13(va_list args);
int pf_integer(va_list args);
int pf_decimal(va_list args);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int rev_string(char *s);
int _strlenc(const char *s);
int pf_per_cent_sign_37(void);
int pf_character(va_list val);
int pf_string(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);
#endif
