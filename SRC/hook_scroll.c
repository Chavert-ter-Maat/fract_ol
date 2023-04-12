/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_scroll.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 12:47:00 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/12 13:10:22 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
void zoom_in(t_fractol *generate)
{
	if (generate->nav.zoom_in != 1)
		generate->nav.zoom_in = 1;
	generate->nav.zoom_out += ((generate->nav.zoom_factor));
	generate->screen.min_x /= generate->nav.zoom_out;
	generate->screen.max_x /= generate->nav.zoom_out;
	generate->screen.min_y /= generate->nav.zoom_out;
	generate->screen.max_y /= generate->nav.zoom_out;
}

void zoom_out(t_fractol *generate)
{
	if (generate->nav.zoom_out != 1)
		generate->nav.zoom_out = 1;
	generate->nav.zoom_in -= (generate->nav.zoom_factor);
	generate->screen.min_x /= generate->nav.zoom_in;
	generate->screen.max_x /= generate->nav.zoom_in;
	generate->screen.min_y /= generate->nav.zoom_in;
	generate->screen.max_y /= generate->nav.zoom_in;
}

void	zoom_fractal(t_fractol *generate, double y_offset)
{
	if (y_offset > 0)
	{
		zoom_in(generate);
		generate->nav.nav_step /= 1.35;
	}
	else if (y_offset < 0)
	{
		zoom_out(generate);
		generate->nav.nav_step *= 1.35;
	}
	init_fractal(generate);
}

static void	scroll_julia(t_fractol *generate, double y_offset)
{
	if (y_offset > 0)
		generate->nav.nav_step += 0.01;
	else if (y_offset < 0)
		generate->nav.nav_step -= 0.01;
	init_fractal(generate);
}

void	hook_scroll(double x_offset, double y_offset, void *param)
{
		t_fractol *generate;

		generate = param;
		(void) x_offset;
		if (generate->fractal_type == MANDELBROT)
			zoom_fractal(generate, y_offset);
		else if (generate->fractal_type == JULIA)
			scroll_julia(generate, y_offset);
}
