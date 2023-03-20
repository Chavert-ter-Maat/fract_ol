/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 13:05:51 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/20 13:56:42 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdio.h>


void mandelbrot(int width, int height, double zoom, double x_offset, double y_offset, int max_iter) 
{
	int y = 0;
	while (y < height) {
		int x = 0;
		char row_output[width+1];
		row_output[width] = '\0';
		while (x < width) {
			double real = ((double)x - (double)width / 2.0) / (zoom * (double)width) + x_offset;
			double imag = ((double)y - (double)height / 2.0) / (zoom * (double)height) + y_offset;
			double z_real = 0;
			double z_imag = 0;
			int i = 0;
			while (i < max_iter) {
				double next_z_real = z_real * z_real - z_imag * z_imag + real;
				double next_z_imag = 2 * z_real * z_imag + imag;
				if (fabs(next_z_real) > 2.0 || fabs(next_z_imag) > 2.0) {
					break;
				}
				z_real = next_z_real;
				z_imag = next_z_imag;
				i++;
			}
			if (i == max_iter) {
				row_output[x] = '*';
			} else {
				row_output[x] = ' ';
			}
			x++;
		}
		printf("%s\n", row_output);
		y++;
	}
}

// int main(void) {
// 	int width = 80;
// 	int height = 40;
// 	double zoom = 0.3;
// 	double x_offset = -0.5;
// 	double y_offset = 0;
// 	int max_iter = 30;
// 	mandelbrot(width, height, zoom, x_offset, y_offset, max_iter);
// 	return 0;
// }