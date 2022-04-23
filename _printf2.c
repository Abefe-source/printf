#include "main.h"


int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, len = 0, k, j, counter = 0;	
	char *dest = NULL;
	char *argStr;
	
	while (format[len] != '\0')
		len++;

	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
		exit(1);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			argStr = malloc(sizeof(char) * 2);
			argStr[0] = (char)va_arg(ap, int);
			argStr[1] = '\0';
			_count(&counter, argStr);
			print_function(argStr);
			free(argStr);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			argStr = malloc(sizeof(char) * 2);
			argStr[0] = '%';
			argStr[1] = '\0';
			_count(&counter, argStr);
			print_function(argStr);
			free(argStr);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			argStr = va_arg(ap, char *);
            		_count(&counter, argStr);
            		print_function(argStr);
            		i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'i')
		{
			argStr = int_dec_spec(va_arg(ap, int));
			_count(&counter, argStr);
			print_function(argStr);
			free(argStr);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == 'd')
		{
			argStr = int_dec_spec(va_arg(ap, int));
			_count(&counter, argStr);
			print_function(argStr);
			free(argStr);
			i += 2;
		}
		else
		{
			for (j = i, k = 0; format[j] != '\0' ; k++, j++, i++)
			{
				if (format[j] == '%')
				{
					i = j;
					break;
				}
				else
				{
					dest[k] = format[j];
				}
			}
			dest[k] = '\0';
			_count(&counter, dest);
			print_function(dest);
		}
	}

	return (counter);
}
