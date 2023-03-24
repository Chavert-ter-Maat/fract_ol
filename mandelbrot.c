/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 13:05:51 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/24 17:55:20 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdio.h>

void mandelbrot(t_mandelbrot *mandelbrot) 
{
    int y = 0;
	int	row_output = 0;
    // loop over each row of the output image
    while (y < mandelbrot->height) 
    {
        int x = 0;
        // loop over each pixel in the current row
        while (x < mandelbrot->width)
        {
            // calculate the real and imaginary parts of the current pixel's position
            double real = ((double)x - mandelbrot->width / 2.0) / (mandelbrot->zoom * mandelbrot->width) + mandelbrot->x_offset;
            double imag = ((double)y - mandelbrot->height / 2.0) / (mandelbrot->zoom * mandelbrot->height) + mandelbrot->y_offset;

            // initialize the variables for the Mandelbrot calculation
            double z_real = 0;
            double z_imag = 0;
            int i = 0;

            // iterate until the maximum number of iterations is reached or the sequence escapes
           
		   
		    while (i < mandelbrot->max_iter) 
            {
                double next_z_real = z_real * z_real - z_imag * z_imag + real;
                double next_z_imag = 2 * z_real * z_imag + imag;

                // if the sequence escapes, break out of the loop
                if (fabs(next_z_real) > 2.0 || fabs(next_z_imag) > 2.0) 
                    break;

                // otherwise update the variables for the next iteration
                z_real = next_z_real;
                z_imag = next_z_imag;
                i++;
            }

            // assign a character to the current pixel based on the number of iterations required
            if (i == mandelbrot->max_iter) 
                row_output[x] = '*';
            else if (i < mandelbrot->max_iter && i > 10)
                row_output[x] = '.';
            else 
                row_output[x] = ' ';
            x++;
        }

        // print the current row of output
        printf("%s\n", row_output);
        y++;
    }
}

