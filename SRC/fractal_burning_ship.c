#include "../fractol.h"

static int	iterations(int iter, double real, double imag, t_fractol *generate) 
{
	double	z_real;
	double	z_imag;
	double	next_z_real;
	double	next_z_imag;
	
	z_real = 0.0;
	z_imag = 0.0;
	iter = 0;
	while (iter < MAX_ITTER && (z_real + z_imag) <= 4.0)
	{
		next_z_imag = 2 * z_real * z_imag + imag + generate->nav.y_nav;
		next_z_real = z_real - z_imag + real + generate->nav.x_nav;
		z_real = next_z_real * next_z_real;
		z_imag = next_z_imag * next_z_imag;
		iter++;
	}
	return (iter);
}

static void	put_pixel_x(int y, t_fractol *generate) 
{
	double	c_real;
	double	c_imag;
	int		iter;
	int		x;

	x = 0;
	iter = 0;
	while (x < WIDTH)
	{
		c_real = generate->screen.min_x + x * generate->nav.x_offset;
		c_imag = generate->screen.min_y + y * generate->nav.y_offset;
		iter = iterations(iter, c_real, c_imag, generate);
		get_color(generate, x, y, iter);
		x++;
	}
}

void	init_burningship(t_fractol *generate) 
{
	int			y;	
	t_screen	screen;

	y = 0;
	screen = generate->screen;
	generate->nav.x_offset = (screen.max_x - screen.min_x) / WIDTH;
	generate->nav.y_offset = (screen.max_y - screen.min_y) / HEIGHT;
	while (y < HEIGHT) 
	{
		put_pixel_x(y, generate);
		y++;
	}
}