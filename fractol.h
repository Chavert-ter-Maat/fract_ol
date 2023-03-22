/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/06 11:23:20 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/22 15:22:19 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// header
#ifndef FRACTOL_H
# define FRACTOL_H

// includes
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include "./libft/ft_printf/ft_printf.h"
# include "./MLX42/include/MLX42/MLX42.h"

// defines
# define WIDTH 		500
# define HEIGHT		500

// structures
typedef struct 	s_struct
{	
	mlx_image_t		*image;
	mlx_t			*mlx;
	t_screen		*screen;
	t_mandelbrot	*mandelbrot;
	int				choice;
	char			**argv;
} 	t_struct;

typedef struct s_screen
{
	int		min_x;
	int		max_x;
	int		min_y;
	int		max_y;
}	t_screen;

typedef struct s_mandelbrot
{
	int		width;
	int		height;
	int		max_iter;
	double	zoom;
	double	x_offset;
	double	y_offset;
}	t_mandelbrot;

// coloring

// hooks
void ft_hook(void* param);

// mandelbrot
void mandelbrot(t_mandelbrot *mandelbrot);

// initialize mlx
void initialize(t_struct *struc);
void open_screen(t_struct *struc);
void new_image(t_struct *struc);
void image_to_window(t_struct *struc);
void hooks(t_struct *struc);

// initialize parameters


// julia

// main
void put_pixel(void* param);
void init(t_struct *struc, char *argv);




#endif
