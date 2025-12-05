# 42-ft_printf
42 project ft_printf. Recreates the funtion printf() from stdio.h.

Main skills: variadic functions

## Description
- int	ft_printf(const char *format, ...);
- Prints a formated string to the standard output.
- param1: format: The formated string to be printed out.
- variable arguments: The variables to replace the placeholders in the formated string. Need to be in the corresponsing order of the placeholders.
- return: The number of characters printed. -1 if output error.
- Placeholders in the formated string:
  - %c Prints a single character.
  - %s Prints a string (as defined by the common C convention).
  - %p The void * pointer argument has to be printed in hexadecimal format.
  - %d Prints a decimal (base 10) number.
  - %i Prints an integer in base 10.
  - %u Prints an unsigned decimal (base 10) number.
  - %x Prints a number in hexadecimal (base 16) lowercase format.
  - %X Prints a number in hexadecimal (base 16) uppercase format.
  - %% Prints a percent sign.
