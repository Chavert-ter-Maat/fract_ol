/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 13:05:51 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/28 15:07:28 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int iterations(double real, double imag, t_fractol *generate) 
{
    double z_real = 0.0;
    double z_imag = 0.0;
    double next_z_real, next_z_imag;
    int iter = 0;
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

void put_pixel_x(int y, t_fractol *generate) 
{
    double c_real, c_imag;
    int iter, x;

    x = 0;
    while (x < WIDTH) 
    {
        c_real = generate->screen.min_x + x * generate->mods.x_offset;
        c_imag = generate->screen.min_y + y * generate->mods.y_offset;
        iter = iterations(c_real, c_imag, generate);
        
        // Map the number of iterations to a color value
        int color = iter % 256;
        color = color * 256 + (255 - color) * 256 * 256;
        
        mlx_put_pixel(generate->image, x, y, color);
        x++;
    }
}

void init_mandelbrot(t_fractol *generate) 
{
    t_screen screen = generate->screen;
    int y = 0;

    generate->mods.x_offset = (screen.max_x - screen.min_x) / WIDTH;
    generate->mods.y_offset = (screen.max_y - screen.min_y) / HEIGHT;

    while (y < HEIGHT) 
    {
        put_pixel_x(y, generate);
        y++;
    }
}