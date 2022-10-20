#include "main.h"

/**
 * get_print - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Description: the function loops through the structs array
 * func_arr[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', _print_int},
		{'s', _print_string},
		{'c', _print_char},
		{'d', _print_int},
		{'u', print_u},
		{'x', print_x},
		{'X', print_X},
		{'b', _print_binary},
		{'o', print_o},
		{'R', print_R},
		{'r', print_r},
		{'S', print_S},
		{'p', print_p},
		{'%', _print_mod}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
