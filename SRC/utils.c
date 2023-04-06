/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 14:14:39 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/06 14:21:11 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void 	init_fractal(t_fractol	*generate)
{
	if (generate->choice == MANDELBROT)
		init_mandelbrot(generate);
	else if (generate->choice == JULIA)
		{}
	else if (generate->choice == BURNINGSHIP)
		init_burningship(generate);
}

void	error_message(void)
{
	ft_printf("---------------------------------------------------------\n");
	ft_printf("| AVAILABLE PARAMETERS FRACT-OL	                        |\n");
	ft_printf("| There are 3 inputs:                                   |\n");
	ft_printf("| 1) Executable name: 'fractol'                         |\n");
	ft_printf("| 2) Fractal type: 'mandelbrot' 'julia' 'burningship'   |\n");
	ft_printf("| 3) Color type: a number between 0 and 3               |\n");
	ft_printf("---------------------------------------------------------\n");
}
