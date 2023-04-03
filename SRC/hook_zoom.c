/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom_hook.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 12:47:00 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/03 13:48:53 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void zoom_in(t_fractol *generate)
{
	if (generate->mods.zoom_out != 1)
		generate->mods.zoom_out = 1;
	generate->mods.zoom_in -= generate->mods.zoom_factor;
	generate->screen.max_x /= generate->mods.zoom_in;
	generate->screen.max_y /= generate->mods.zoom_in;
	generate->screen.min_x /= generate->mods.zoom_in;
	generate->screen.max_x /= generate->mods.zoom_in;
}

static void zoom_out(t_fractol *generate)
{
	if (generate->mods.zoom_in != 1)
		generate->mods.zoom_in = 1;
	generate->mods.zoom_in -= generate->mods.zoom_factor;
	generate->screen.max_x /= generate->mods.zoom_out;
	generate->screen.max_y /= generate->mods.zoom_out;
	generate->screen.min_x /= generate->mods.zoom_out;
	generate->screen.max_x /= generate->mods.zoom_out;
}

static void	scroll_mandelbrot(t_fractol *generate, double y_offset)
{
	if (y_offset > 0)
		zoom_in(generate);
	else if (y_offset < 0)
		zoom_out(generate);
	init_mandelbrot(generate);
}

// static void	scroll_julia(t_fractol *generate, double y_offset)
// {
	
// }

// static void	scroll_burningship(t_fractol *generate, double y_offset)
// {
	
// }

void	scroll_hook(double x_offset, double y_offset, void *param)
{
		t_fractol *generate;

		generate = param;
		(void) x_offset;
		
		// if (generate->choice == MANDELBROT)
		scroll_mandelbrot(generate, y_offset);
		// else if (generate->choice == JULIA)
		// else if (generate->choice == BURNINGSHIP)
}