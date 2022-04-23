#include "main.h"
/**
 * int_dec_spec - makes provision for i and d specifiers
 * @num: number to be printed out
 * Return: returns an equivalent string
 */
char *int_dec_spec(int num)
{
	char *str;
	int sign = 0, i = 0, place_value = 0;
	int place_value_checker = 1;

	if (num < 0)
	{
		sign = 1;
		place_value += 1;
		num *= -1;
	}
	int copy = num;

	while (copy > 9)
	{
		copy /= 10;
		++place_value;
	}
	for (int m = 1; m < place_value; m++)
	{
		place_value_checker *= 10;
	}
	str = malloc(sizeof(char) * place_value);
	if (str == NULL)
		exit(1);
	else
	{
		if (sign == 1)
		{
			str[i] = '-';
			i++;
		}
		while (i < place_value)
		{
			str[i] = ((num / place_value_checker) % 10) + '0';
			place_value_checker /= 10;
			++i;
		}
	str[i] = '\0';
	}
	return (str);
}
