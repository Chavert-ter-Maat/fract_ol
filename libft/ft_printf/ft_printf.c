/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: chaverttermaat <chaverttermaat@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 13:58:06 by chavertterm   #+#    #+#                 */
/*   Updated: 2023/02/13 11:12:02 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list argument_list, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putc(va_arg(argument_list, int));
	if (format == 'd' || format == 'i')
		count += ft_putid(va_arg(argument_list, int));
	if (format == 's')
		count += ft_puts(va_arg(argument_list, char *));
	if (format == 'u')
		count += ft_putu(va_arg(argument_list, unsigned int));
	if (format == 'x' || format == 'X')
		count += ft_putx(va_arg(argument_list, unsigned int), format);
	if (format == 'p')
		count += ft_putp(va_arg(argument_list, uintptr_t));
	if (format == '%')
		count += ft_putperc();
	return (count);
}

int	ft_printf(const char *string, ...)
{	
	int		index;
	int		count;
	int		protect;
	va_list	argument_list;

	index = 0;
	count = 0;
	va_start(argument_list, string);
	while (string[index])
	{	
		if (string[index] == '%' && string[index + 1] != '\0')
		{
			protect = ft_format(argument_list, string[index + 1]);
			index++;
		}
		else
			protect = ft_putc(string[index]);
		if (protect == -1)
			return (-1);
		count += protect;
		index++;
	}
	va_end(argument_list);
	return (count);
}
