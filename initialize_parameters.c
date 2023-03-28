/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_parameters.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 10:31:19 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/28 15:28:01 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_param(t_fractol *generate, char *argv)
{
	ft_bzero(generate, sizeof(*generate));
	init_type(generate, argv);
	init_screen_settings(&generate->screen);
	init_mods(&generate->mods);
}

void init_type(t_fractol *generate, char *argv)
{
	if (ft_strncmp(argv, "mandelbrot", 10) == CORRECT)
		generate->choice = MANDELBROT;
	else if (ft_strncmp(argv, "julia", 5) == CORRECT)
		generate->choice = JULIA;
	else if (ft_strncmp(argv, "burningship", 11) == CORRECT)
		generate->choice = BURNINGSHIP;
	else
	{
		ft_printf("input error");
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

void	init_mods(t_mods *mods)
{
	ft_bzero(mods, sizeof(*mods));
	mods->width = 500;
	mods->height = 500;
	mods->zoom = 0.3;
	mods->max_iter = 5;
}