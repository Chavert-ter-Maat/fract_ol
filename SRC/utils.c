/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 14:14:39 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/12 11:29:05 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void 	init_fractal(t_fractol	*generate)
{
	if (generate->fractal_type == MANDELBROT)
		init_mandelbrot(generate);
	else if (generate->fractal_type == JULIA)
		init_julia(generate);
	else if (generate->fractal_type == BURNINGSHIP)
		init_burningship(generate);
}

void	put_inscription(t_fractol *generate)
{
	// mlx_put_string(generate->mlx, "-------------------------------", 5, 0);
	mlx_put_string(generate->mlx, "FRACT-OL by Chavert", 10, 10);
	mlx_put_string(generate->mlx, "arrow keys for navigate", 10, 40);
		mlx_put_string(generate->mlx, "'w' = zoom in", 10, 60);
	mlx_put_string(generate->mlx, "'s' = zoom out", 10, 80);
	mlx_put_string(generate->mlx, "'a' = smaller navigation steps", 10, 100);
	mlx_put_string(generate->mlx, "'d' = bigger navigation steps", 10, 120);
	mlx_put_string(generate->mlx, "'r' = reset fractal", 10, 140);
	// mlx_put_string(generate->mlx, "-------------------------------", 5, 140);
}

void	error_message(void)
{
	ft_printf("---------------------------------------------------------\n");
	ft_printf("| AVAILABLE PARAMETERS FRACT-OL	                        |\n");
	ft_printf("| There are 3 inputs:                                   |\n");
	ft_printf("| 1) Executable name: 'fractol'                         |\n");
	ft_printf("| 2) Fractal type: 'mandelbrot' 'julia' 'burningship'   |\n");
	ft_printf("| 3) Color type: 'red' 'blue' 'green'          	       |\n");
	ft_printf("---------------------------------------------------------\n");
}
