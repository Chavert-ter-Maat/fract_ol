/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_parameters.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 10:31:19 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/13 14:49:00 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_fractal_settings(t_fractol *generate, char **argv)
{
	ft_bzero(generate, sizeof(*generate));
	init_fractal_type(generate, argv[1]);
	init_color_type(&generate->colors, argv[2]);
	if (generate->fractal_type == MANDELBROT)
	{
		init_navigation_mandelbrot(generate);
		init_screen_settings_mandelbrot(&generate->screen);
	}
	else if (generate->fractal_type == JULIA)
	{
		init_navigation_julia(generate);
		init_screen_settings_julia(&generate->screen);
	}	
	else if (generate->fractal_type == BURNINGSHIP)
	{
		init_navigation_burningship(generate);
		init_screen_settings_burningship(&generate->screen);
	}
}

void	reset_fractol_settings(t_fractol *generate)
{
	if (generate->fractal_type == MANDELBROT)
	{
		init_navigation_mandelbrot(generate);
		init_screen_settings_mandelbrot(&generate->screen);
	}
	else if (generate->fractal_type == JULIA)
	{
		init_navigation_julia(generate);
		init_screen_settings_julia(&generate->screen);
	}	
	else if (generate->fractal_type == BURNINGSHIP)
	{
		init_navigation_burningship(generate);
		init_screen_settings_burningship(&generate->screen);
	}
}

void	init_fractal_type(t_fractol *generate, char *argv)
{
	if (ft_strncmp(argv, "mandelbrot", 11) == CORRECT)
		generate->fractal_type = MANDELBROT;
	else if (ft_strncmp(argv, "julia", 6) == CORRECT)
		generate->fractal_type = JULIA;
	else if (ft_strncmp(argv, "burningship", 12) == CORRECT)
		generate->fractal_type = BURNINGSHIP;
	else
	{
		error_message();
		exit (EXIT_FAILURE);
	}
}

void	init_color_type(t_colors *colors, char *argv)
{
	ft_bzero(colors, sizeof(colors));
	colors->black = 0x00000FF;
	if (ft_strncmp(argv, "normal", 7) == CORRECT)
	{
		colors->color_type = NORMAL;
		init_normal(colors);
	}
	else if (ft_strncmp(argv, "rainbow", 8) == CORRECT)
	{
		colors->color_type = RAINBOW;
		init_rainbow(colors);
	}
	else if (ft_strncmp(argv, "trippy", 7) == CORRECT)
	{
		colors->color_type = TRIPPY;
		init_trippy(colors);
	}
	else
	{
		error_message();
		exit (EXIT_FAILURE);
	}
}

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

void	init_navigation_mandelbrot(t_fractol *generate)
{
	ft_bzero(&generate->nav, sizeof(&generate->nav));
	generate->nav.zoom_factor = 0.09;
	generate->nav.zoom_in = 1.0;
	generate->nav.zoom_out = 1.0;
	generate->nav.nav_step = 0.1;
	generate->nav.x_nav = 0.0;
	generate->nav.y_nav = 0.0;
}

void	init_navigation_julia(t_fractol *generate)
{
	ft_bzero(&generate->nav, sizeof(&generate->nav));
	generate->nav.zoom_factor = 0.09;
	generate->nav.zoom_in = 1.0;
	generate->nav.zoom_out = 1.0;
	generate->nav.nav_step = 0.1;
	generate->nav.x_nav = 0.0;
	generate->nav.y_nav = 0.0;
	generate->nav.c_real = -0.8;
    generate->nav.c_imag = 0.156;
}

void	init_navigation_burningship(t_fractol *generate)
{
	ft_bzero(&generate->nav, sizeof(&generate->nav));
	generate->nav.zoom_factor = 0.09;
	generate->nav.zoom_in = 1.0;
	generate->nav.zoom_out = 1.0;
	generate->nav.nav_step = 0.1;
	generate->nav.x_nav = 0.0;
	generate->nav.y_nav = 0.0;
}

void init_normal(t_colors *colors)
{
    colors->color_set1 = 0xF5DEB3FF; // wheat
    colors->color_set2 = 0xE6E6FAFF; // lavender
    colors->color_set3 = 0xD2B48CFF; // tan
    colors->color_set4 = 0xFAEBD7FF; // antique white
    colors->color_set5 = 0xCDCDCDFF; // light gray
    colors->color_set6 = 0xFFF8DCFF; // cornsilk
}


void init_rainbow(t_colors *colors)
{
	colors->color_set1 = 0xFFC300FF; // yellow
	colors->color_set2 = 0xFF5733FF; // orange
	colors->color_set3 = 0xFFC300FF; // yellow
	colors->color_set4 = 0xC70039FF; // red
	colors->color_set5 = 0x900C3FFF; // purple
	colors->color_set6 = 0x00A8C6FF; // blue
}

void	init_trippy(t_colors *colors)
{
	colors->color_set1 = colors->black;
	colors->color_set2 = colors->black;
	colors->color_set3 = colors->black;
	colors->color_set4 = colors->black;
	colors->color_set5 = colors->black;
	colors->color_set6 = colors->black;
}
