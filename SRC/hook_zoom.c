/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_zoom.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 12:47:00 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/06 14:51:35 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void zoom_in(t_fractol *generate)
{
	if (generate->nav.zoom_out != 1)
		generate->nav.zoom_out = 1;
	generate->nav.zoom_in -= generate->nav.nav_step;
	generate->screen.min_x /= generate->nav.zoom_in;
	generate->screen.max_x /= generate->nav.zoom_in;
	generate->screen.min_y /= generate->nav.zoom_in;
	generate->screen.max_y /= generate->nav.zoom_in;
}

static void zoom_out(t_fractol *generate)
{
	if (generate->nav.zoom_in != 1)
		generate->nav.zoom_in = 1;
	generate->nav.zoom_out += generate->nav.nav_step;
	generate->screen.min_x /= generate->nav.zoom_out;
	generate->screen.max_x /= generate->nav.zoom_out;
	generate->screen.min_y /= generate->nav.zoom_out;
	generate->screen.max_y /= generate->nav.zoom_out;
}

// static void	scroll_mandelbrot(t_fractol *generate, double y_offset)
// {
// 	if (y_offset > 0)
// 	{
// 		zoom_out(generate);
// 		generate->nav.nav_step /= 1.12 * 1.12;
// 		generate->nav.zoom /=2;
// 	}
// 	else if (y_offset < 0)
// 	{
// 		zoom_in(generate);
// 		generate->nav.nav_step *= 1.1 * 1.1;
// 		generate->nav.zoom *=2;
// 	}
// 	init_mandelbrot(generate);
// }

static void	scroll_mandelbrot(t_fractol *generate, double y_offset)
{
	if (y_offset > 0)
	{
		zoom_out(generate);
		generate->nav.nav_step /= 1.33;
		generate->nav.zoom /= 5;
	}
	else if (y_offset < 0)
	{
		zoom_in(generate);
		generate->nav.nav_step *= 1.33;
		generate->nav.zoom *= 5;
	}
	init_mandelbrot(generate);
}

// static void	scroll_julia(t_fractol *generate, double y_offset)
// {
// 	if (y_offset > 0)
// 		zoom_in(generate);
// 	else if (y_offset < 0)
// 		zoom_out(generate);
// 	init_mandelbrot(generate);
// }

static void	scroll_burningship(t_fractol *generate, double y_offset)
{
	if (y_offset > 0)
		zoom_in(generate);
	else if (y_offset < 0)
		zoom_out(generate);
	init_burningship(generate);
}

void	my_scrollhook(double x_offset, double y_offset, void *param)
{
		t_fractol *generate;

		generate = param;
		(void) x_offset;
		if (generate->choice == MANDELBROT)
			scroll_mandelbrot(generate, y_offset);
		// else if (generate->choice == JULIA)
			// scroll_julia(generate, y_offset);
		else if (generate->choice == BURNINGSHIP)
			scroll_burningship(generate, y_offset);
}
