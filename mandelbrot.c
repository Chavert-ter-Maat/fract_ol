/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 13:05:51 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/30 11:45:56 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int iterations(int iter, double real, double imag, t_fractol *generate) 
{
	double z_real;
	double z_imag;
	double next_z_real;
	double next_z_imag;

	z_real = 0.0;
	z_imag = 0.0;
	iter = 0;
	while (iter < generate->mods.max_iter && (z_real * z_real + z_imag * z_imag) <= 4.0)
	{
		next_z_real = z_real * z_real - z_imag * z_imag + real;
		next_z_imag = 2 * z_real * z_imag + imag;
		z_real = next_z_real;
		z_imag = next_z_imag;
		iter++;
	}
	return iter;
}

static void put_pixel_x(int y, t_fractol *generate) 
{
	double	c_real;
	double	c_imag;
	int		x;
	int		iter;

	x = 0;
	while (x < WIDTH) 
	{
		c_real = generate->screen.min_x + x * generate->mods.x_offset;
		c_imag = generate->screen.min_y + y * generate->mods.y_offset;
		iter = iterations(iter, c_real, c_imag, generate);
		if (iter == generate->mods.max_iter)
			mlx_put_pixel(generate->image, x, y, 0xFFFFFFFF);
		else 
			mlx_put_pixel(generate->image, x, y, 0x00FFFFFF);
		x++;
	}
}

void init_mandelbrot(t_fractol *generate) 
{
	t_screen	screen;
	int			y;
	
	y = 0;	
	screen = generate->screen;
	generate->mods.x_offset = (screen.max_x - screen.min_x) / WIDTH;
	generate->mods.y_offset = (screen.max_y - screen.min_y) / HEIGHT;
	while (y < HEIGHT) 
	{
		put_pixel_x(y, generate);
		y++;
	}
}