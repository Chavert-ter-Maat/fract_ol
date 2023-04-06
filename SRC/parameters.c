/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parameters.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 10:31:19 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/06 14:02:43 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_fractal_settings(t_fractol *generate, char **argv)
{
	ft_bzero(generate, sizeof(*generate));
	init_fractal_type(generate, argv[1]);
	init_color_type(generate, argv[2]);
	init_screen_settings(&generate->screen);
	init_navigation(&generate->nav);
}

void	reset_fractol_settings(t_fractol *generate)
{
	init_screen_settings(&generate->screen);
	init_navigation(&generate->nav);
}

void	init_color_type(t_fractol *generate, char *argv)
{
	if (ft_strncmp(argv, "1", 1) == CORRECT)
		generate->color = RAINBOW;
	else if (ft_strncmp(argv, "1", 1) == CORRECT)
		generate->color = RAINBOW;
}

void	init_fractal_type(t_fractol *generate, char *argv)
{
	printf("%s = argv\n", argv);
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

void	init_navigation(t_nav *nav)
{
	ft_bzero(nav, sizeof(*nav));
	nav->width = 500;
	nav->height = 500;
	nav->zoom = 1.0;
	nav->zoom_in = 1.0;
	nav->zoom_out = 1.0;
	nav->nav_step = 0.1;
	// nav->zoom_multiplier = calculate_mulitplier(nav);
	nav->x_nav = 0.0;
	nav->y_nav = 0.0;
}
