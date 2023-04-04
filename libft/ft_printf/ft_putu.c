/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putu.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/19 15:44:10 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/02/13 11:00:13 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getlen(unsigned int number)
{
	int	string_lenght;

	string_lenght = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		string_lenght++;
		number = number / 10;
	}
	return (string_lenght);
}

static char	*ft_itoa(unsigned int number)
{
	unsigned int	string_lenght;
	char			*string;

	string_lenght = ft_getlen(number);
	string = malloc((string_lenght + 1) * sizeof(char));
	if (!string)
		return (NULL);
	if (number == 0)
		string[0] = '0';
	string[string_lenght] = '\0';
	if (number < 0)
	{
		string[0] = '-';
		number *= -1;
	}
	while (number > 0)
	{
		string[string_lenght - 1] = (number % 10) + '0';
		number /= 10;
		string_lenght--;
	}
	return (string);
}

int	ft_putu(unsigned int u)
{
	char	*string;

	string = ft_itoa(u);
	if (!string)
		return (-1);
	if (ft_printstr(string) == -1)
		return (free(string), -1);
	free (string);
	return (ft_getlen(u));
}
