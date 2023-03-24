/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_parameters.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 10:31:19 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/24 18:18:14 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_param(t_struct *struc, char *argv)
{
	init_type(struc, argv);
	init_mandelbrot(&struc->mandelbrot);
}

void init_type(t_struct *struc, char *argv)
{
	if ((ft_strncmp(argv, "mandelbrot", 10)) == 0)
		struc->choice = 0;
	else if ((ft_strncmp(argv, "julia", 5)) == 0)
		struc->choice = 1;
	else
	{
		ft_printf("input error");
		exit (EXIT_FAILURE);
	}
	//struc->argv = argv;
}

void	init_screen_settings(t_screen *screen)
{
	screen->max_x = 1.0;
	screen->min_x = -2.0;
	screen->max_y = 1.5;
	screen->min_y = -1.5;
}

void	init_mandelbrot(t_mandelbrot *mandelbrot)
{
	mandelbrot->width = 80;
	mandelbrot->height = 40;
	mandelbrot->zoom = 0.3;
	mandelbrot->x_offset = -0.5;
	mandelbrot->y_offset = 0;
	mandelbrot->max_iter = 30;
}