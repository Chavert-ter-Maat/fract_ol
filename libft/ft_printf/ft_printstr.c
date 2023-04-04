/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printstr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 14:28:01 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/01 09:34:19 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *string)
{
	int	index;

	index = 0;
	if (!string)
		return (-1);
	while (string[index])
	{	
		if (ft_putc(string[index]) == -1)
			return (-1);
		index++;
	}
	return (index);
}
