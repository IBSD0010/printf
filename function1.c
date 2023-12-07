#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @va_start: variable argument
 * @va_arg: variable arguments 
 * @va_start: variable arguments
 * @args: nbre 
 * @format: Size specifier
 * Return: Number of chars printed.
 */

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format) {
        if (*format == '%') {
            format++; // Move past '%'

            // Check for conversion specifiers
            switch (*format) {
                case 'c':
                    // Character
                    putchar(va_arg(args, int));
                    count++;
                    break;

                case 's':
                    // String
                    {
                        const char *str = va_arg(args, const char*);
                        while (*str) {
                            putchar(*str);
                            str++;
                            count++;
                        }
                    }
                    break;

                case '%':
                    // Percent sign
                    putchar('%');
                    count++;
                    break;

                default:
                    // Unknown specifier, ignore
                    break;
            }
        } else {
            // Regular character, print as is
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}

int main() {
    _printf("This is a simple %s function with %c and %% support.\n", "printf", 'C');
    return 0;
}
