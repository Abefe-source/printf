#include "main.h"
#include <stdlib.h>
/**
 * print_function - prints strings to stdout
 * @str: input string
 * Return: N/A
 */
void print_function(const char *str)
{
	char *new_str;
	int i = 0;
	int len = 0;

	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	new_str = malloc(sizeof(char) * (len + 1));

	if (new_str == NULL)
		exit(1);
	for (int count = 0; str[count] != '\0'; count++)
	{
		new_str[count] = str[count];
	}

	new_str[len + 1] = '\0';
	write(1, new_str, len);
	free(new_str);
}
