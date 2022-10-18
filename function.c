#include "main.h"
#include <stdio.h>
/**
 * _print_char - prints character
 * @args: the va_arg argument
 * Return: count
 */
int _print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}
/**
 * _print_mod - print the % sign
 * @args: the va_arg recieved
 * Return: 1
 */
int _print_mod(va_list args)
{
	char c = '%';

	(void) args;

	write(1, &c, 1);
	return (1);
}
/**
 * _print_string - prints the string char by char
 * @args: arg recieved by the function
 * Return: number of characters printed
 */
int _print_strings(va_list args)
{
	int i, count = 0;
	char *buffer = va_arg(args, char *);

	if (buffer == NULL)
		buffer = "(null)";
	for (i = 0;  buffer[i]; i++)
	{
		write(1, &buffer[i], 1);
		count = count + 1;
	}

	return (count);
}
/**
 * _print_int - prints a decimal integer
 * @args: return the argument
 * Return: the number of printd character
 */
int _print_int(va_list args)
{
	int a, expo = 1, len = 0;
	unsigned int n;
	char pr;

	a = va_arg(args, int);

	if (a < 0)
	{
		pr = '-';
		len = len + write(1, &pr, 1);
		n = a * -1;
	}
	else
		n = a;
	while (n / expo > 9)
		expo *= 10;
	while (expo != 0)
	{
		pr = n / expo + '0';
		len = len + write(1, &pr, 1);
		n = n % expo;
		expo = expo / 10;
	}
	return (len);
}
