/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
#include "main.h"
int print_int(va_list types,
char buffer[],
int flags,
int width,
int precision,
int size)
{
int i = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(types, long int);
unsigned long int num;
n = convert_size_number(n, size);
if (n == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;
if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_negative = 1;
}
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * convert_size_number - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);
return ((int)num);
}

/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size)
{
int length = BUFF_SIZE - ind - 1;
char padd = ' ', extra_ch = 0;
UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (is_negative)
extra_ch = '-';
else if (flags & F_PLUS)
extra_ch = '+';
else if (flags & F_SPACE)
extra_ch = ' ';
return (write_num(ind, buffer, flags, width, precision,
length, padd, extra_ch));
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);
return (0);
}
