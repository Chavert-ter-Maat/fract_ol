/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putp.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/22 15:20:31 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/03 10:05:27 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (-1);
	while (string[i])
	{
		i++;
	}
	return (i);
}

static int	ft_getlen(uintptr_t number)
{
	int	string_lenght;

	string_lenght = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 16;
		string_lenght++;
	}
	return (string_lenght);
}

static char	*ft_itoah(uintptr_t x)
{
	int		string_lenght;
	char	*string;
	char	*hex_string;	

	hex_string = "0123456789abcdef";
	string_lenght = ft_getlen(x);
	string = malloc((string_lenght + 3) * sizeof(char));
	if (!string)
		return (0);
	string[0] = '0';
	string[1] = 'x';
	string[string_lenght + 2] = '\0';
	while (string_lenght > 0)
	{
		string[string_lenght + 1] = hex_string[x % 16];
		x /= 16;
		string_lenght--;
	}
	return (string);
}

int	ft_putp(uintptr_t pointer)
{
	char	*string;
	int		lenght;

	string = ft_itoah(pointer);
	if (!string)
		return (-1);
	lenght = ft_strlen(string);
	if (ft_printstr(string) == -1)
		return (free(string), -1);
	free (string);
	return (lenght);
}
