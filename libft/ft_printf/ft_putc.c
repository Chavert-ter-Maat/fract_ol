/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 12:31:26 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/02/13 10:54:06 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putc(int character)
{
	return (write(1, &character, 1));
}
