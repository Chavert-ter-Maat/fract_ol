/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_screen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/14 11:43:17 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/14 14:02:06 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_screen_settings_mandelbrot(t_screen *screen)
{
	ft_bzero(screen, sizeof(*screen));
	screen->max_x = 1.0;
	screen->min_x = -2.0;
	screen->max_y = 1.5;
	screen->min_y = -1.5;
}

void	init_screen_settings_julia(t_screen *screen)
{
	ft_bzero(screen, sizeof(*screen));
	screen->max_x = 2.0;
	screen->min_x = -2.0;
	screen->max_y = 1.5;
	screen->min_y = -1.5;
}

void	init_screen_settings_burningship(t_screen *screen)
{
	ft_bzero(screen, sizeof(*screen));
	screen->max_x = 1.5;
	screen->min_x = -3.0;
	screen->max_y = 1.5;
	screen->min_y = -2;
}
