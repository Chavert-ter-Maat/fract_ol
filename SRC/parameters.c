/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parameters.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 10:31:19 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/07 18:52:40 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_fractal_settings(t_fractol *generate, char **argv)
{
	ft_bzero(generate, sizeof(*generate));
	init_fractal_type(generate, argv[1]);
	init_screen_settings(&generate->screen);
	init_navigation(generate);
	init_colors(&generate->colors, argv[2]);
}

void	reset_fractol_settings(t_fractol *generate)
{
	init_screen_settings(&generate->screen);
	init_navigation(generate);
}

void	init_fractal_type(t_fractol *generate, char *argv)
{
	if (ft_strncmp(argv, "mandelbrot", 10) == CORRECT)
		generate->choice = MANDELBROT;
	else if (ft_strncmp(argv, "julia", 5) == CORRECT)
		generate->choice = JULIA;
	else if (ft_strncmp(argv, "burningship", 11) == CORRECT)
		generate->choice = BURNINGSHIP;
	else
	{
		ft_printf("input error!!");
		exit (EXIT_FAILURE);
	}
}


void	init_screen_settings(t_screen *screen)
{
	ft_bzero(screen, sizeof(*screen));
	screen->max_x = 1.0;
	screen->min_x = -2.0;
	screen->max_y = 1.5;
	screen->min_y = -1.5;
}

void	init_navigation(t_fractol *generate)
{
	ft_bzero(&generate->nav, sizeof(&generate->nav));
	generate->nav.x_offset = (generate->screen.max_x - generate->screen.min_x) / WIDTH;
	generate->nav.y_offset = (generate->screen.max_y - generate->screen.min_y) / HEIGHT;
	generate->nav.width = 500;
	generate->nav.height = 500;
	generate->nav.zoom_factor = 0.09;
	generate->nav.zoom_in = 1.0;
	generate->nav.zoom_out = 1.0;
	generate->nav.nav_step = 0.1;
	generate->nav.x_nav = 0.0;
	generate->nav.y_nav = 0.0;
}

void	init_colors(t_colors *colors, char *argv)
{
	ft_bzero(colors, sizeof(colors));
	if (ft_strncmp(argv, "1", 1) == CORRECT)
		{
			colors->r = 2;
			colors->g = 2;
			colors->b = 2;
		}
	// else if (ft_strncmp(argv, "1", 1) == CORRECT)
	// 	generate->color = RAINBOW;
}