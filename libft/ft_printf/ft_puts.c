/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puts.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/24 14:30:41 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/03 10:01:07 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puts(char *string)
{
	int	index;

	index = 0;
	if (string == 0)
	{
		index = ft_printstr("(null)");
		if (index != 6)
			return (-1);
		return (6);
	}
	while (string[index])
	{	
		if (ft_putc(string[index]) == -1)
			return (-1);
		index++;
	}
	return (index);
}
