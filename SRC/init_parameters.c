/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_parameters.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 10:31:19 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/12 14:01:20 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_fractal_settings(t_fractol *generate, char **argv)
{
	ft_bzero(generate, sizeof(*generate));
	init_fractal_type(generate, argv[1]);
	init_screen_settings(&generate->screen);
	if (generate->fractal_type == MANDELBROT)
	{
		init_navigation_mandelbrot(generate);
		init_screen_settings(&generate->screen);
	}
	else if (generate->fractal_type == JULIA)
	{
		init_navigation_julia(generate);
		init_screen_settings_julia(&generate->screen);
	}	
	else if (generate->fractal_type == BURNINGSHIP)
	{
		init_navigation_burningship(generate);
		init_screen_settings(&generate->screen);
	}
	init_colors(&generate->colors, argv[2]);
}

void	reset_fractol_settings(t_fractol *generate)
{
	if (generate->fractal_type == MANDELBROT)
	{
		init_navigation_mandelbrot(generate);
		init_screen_settings(&generate->screen);
	}
	else if (generate->fractal_type == JULIA)
	{
		init_navigation_julia(generate);
		init_screen_settings_julia(&generate->screen);
	}	
	else if (generate->fractal_type == BURNINGSHIP)
	{
		init_navigation_burningship(generate);
		init_screen_settings(&generate->screen);
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
		ft_printf("input error!");
		exit (EXIT_FAILURE);
	}
}

void	init_screen_settings(t_screen *screen)
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

static void init_red(t_colors *colors)
{
colors->color_set1 = 0xFF6969FF; // pastel red
colors->color_set2 = 0xFFB6C1FF; // light pink/red
colors->color_set3 = 0xCD5C5CFF; // dark red
colors->color_set4 = 0xDC143CFF; // crimson red
}

static void init_blue(t_colors *colors)
{
colors->color_set1 = 0x6495EDFF; // cornflower blue
colors->color_set2 = 0xADD8E6FF; // light blue
colors->color_set3 = 0x4169E1FF; // royal blue
colors->color_set4 = 0x0000CDFF; // medium blue
}

static void init_green(t_colors *colors)
{
colors->color_set1 = 0x228B22FF; // forest green
colors->color_set2 = 0x32CD32FF; // lime green
colors->color_set3 = 0x7FFF00FF; // chartreuse
colors->color_set4 = 0x006400FF; // dark green
}

static void init_rainbow(t_colors *colors)
{
colors->color_set1 = 0xFFC300FF; // yellow
colors->color_set2 = 0xFF5733FF; // orange
colors->color_set3 = 0xFFC300FF; // yellow
colors->color_set4 = 0xC70039FF; // red
colors->color_set5 = 0x900C3FFF; // purple
colors->color_set6 = 0x00A8C6FF; // blue
colors->color_set7 = 0x1E8449FF; // green
}

void	init_colors(t_colors *colors, char *argv)
{
	ft_bzero(colors, sizeof(colors));
	colors->black = 0x8888800;
	colors->white = 0xFFFFFFF;
	if (ft_strncmp(argv, "red", 3) == CORRECT)
		init_red(colors);
	else if (ft_strncmp(argv, "green", 6) == CORRECT)
		init_green(colors);
	else if (ft_strncmp(argv, "blue", 5) == CORRECT)
		init_blue(colors);
	else if (ft_strncmp(argv, "rainbow", 8) == CORRECT)
		init_rainbow(colors);
}