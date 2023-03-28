#include "fractol.h"

// Perform Mandelbrot Calculation
// Input: the current pixel's real and imaginary coordinates, 
// the current mandelbrot struct Output: the number of iterations required for
// the pixel to escape or reach the maximum number of iterations
// Description: This function takes in the real and imaginary coordinates
//  of the current pixel, along with the current mandelbrot struct, 
//  and performs the Mandelbrot calculation until either the sequence escapes
//   or the maximum number of iterations is reached.

static int iterations(double real, double imag, t_fractol *generate) 
{
	double z_real;
	double z_imag;
	double	next_z_real;
	double	next_z_imag;
	int iter;

	
	z_real = 0.0;
	z_imag = 0.0;
	iter = 0;
	while (iter < generate->mods.max_iter && (z_real + z_imag) <= 4.0) 
	{
		next_z_imag = 2 * z_real * z_imag + imag;
		next_z_real = z_real - z_imag + real;
		z_real = next_z_real * next_z_real;
		z_imag = next_z_imag * next_z_imag;
		iter++;
	}
	return (iter);
}

// Mandelbrot:
// Zn+1 = Zn^2 + C
// where Z is a complex number, C is a constant complex number, 
// and n is a positive integer.

// Calculate Pixel Coordinates
// Input: the current pixel's x and y coordinates, the current mandelbrot generatet
// Output: the real and imaginary parts of the current pixel's position
// Description: This function takes in the x and y coordinates of the current 
// pixel , along with the current mandelbrot generatet, and calculates 
// the corresponding real and imaginary parts of the position in the complex plane.

static void put_pixel_x(int y, t_fractol *generate) 
{
	double	c_real;
	double	c_imag;
	int iter;
	int x;

	x = 0;
	iter = 0;
	while (x < WIDTH) 
	{
		c_real = generate->screen.min_x + x * generate->mods.x_offset;
		c_imag = generate->screen.min_y + y * generate->mods.y_offset;
		iter = iterations(c_real, c_imag, generate);
		if (iter == generate->mods.max_iter)
			mlx_put_pixel(generate->image, x, y, 0xFFFFFFFF);
		else 
			mlx_put_pixel(generate->image, x, y, 0x00FFFFFF);
		x++;
	}
}

// Generate Row Output
// Input: the current row's y coordinate, the current mandelbrot generatet
// Output: a string representing the row of output characters
// Description: This function takes in the y coordinate of the current row,
// along with the current mandelbrot generatet, and generates a string representing
// the row of output characters based on the number of iterations
// required for each pixel.

void init_burningship(t_fractol *generate) 
{
	int y;
	t_screen screen;
	
	screen = generate->screen;
	generate->mods.x_offset = (screen.max_x - screen.min_x) / WIDTH;
	generate->mods.y_offset = (screen.max_y - screen.min_y) / HEIGHT;

	y = 0;
	while (y < HEIGHT) 
	{
		put_pixel_x(y, generate);
		y++;
	}
}