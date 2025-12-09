*This project has been created as part of the 42 curriculum by yanlu.*

# Description
This project recreates (a simpler version of) the `printf()` function from `libc (<stdio.h>)`.
It prints a formated string to the standard output.

- Language: C
- Prototype: `int ft_printf(const char *format, ...);`
- Param1: format: The formated string to be printed out.
- Variable arguments: The variables to replace the placeholders in the formated string. They need to be in the corresponsing order of the placeholders and separated by `,`.
- Return: The number of characters printed. -1 if output error.
- Possible placeholders in the formated string:
  - %c Prints a single character.
  - %s Prints a string (as defined by the common C convention).
  - %p The void * pointer argument has to be printed in hexadecimal format.
  - %d Prints a decimal (base 10) number.
  - %i Prints an integer in base 10.
  - %u Prints an unsigned decimal (base 10) number.
  - %x Prints an unsigned decimal number in hexadecimal (base 16) lowercase format.
  - %X Prints an unsigned decimal number in hexadecimal (base 16) uppercase format.
  - %% Prints a percent sign.

# Instructions
## Compile the library
Go to the library path and run:

    make

The library `libftprintf.a` will be created.

## Use the function
Include the files in this repo in your working path and include its header in your code:

    #include "ft_printf.h"

Example usage:

    ft_printf("Hello world%c%i", '!', 1);

prints out:

    Hello world!1

# Resources
- [Manual of `printf()`](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Manual of `stdarg.h`](https://man7.org/linux/man-pages/man3/stdarg.3.html)

AI was not used for this project.