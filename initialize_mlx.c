/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_mlx.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 11:31:11 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/24 17:57:21 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_mlx(t_struct *struc)
{
	open_screen(struc);
	new_image(struc);
	image_to_window(struc);
	hooks(struc);
}

 void open_screen(t_struct *struc)
{
	if (!(struc->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		{
			ft_printf("error");
			exit (EXIT_FAILURE);
		}
	}
}

void new_image(t_struct *struc)
{
	if (!(struc->image = mlx_new_image(struc->mlx, 200, 200)))
	{
		mlx_close_window(struc->mlx);
		puts(mlx_strerror(mlx_errno));
		ft_printf("error");
		exit (EXIT_FAILURE);
	}
}

void image_to_window(t_struct *struc)
{
	if (mlx_image_to_window(struc->mlx, struc->image, 0, 0) == -1)
	{
		mlx_close_window(struc->mlx);
		puts(mlx_strerror(mlx_errno));
		ft_printf("error");
		exit (EXIT_FAILURE);
	}
}

void hooks(t_struct *struc)
{
	mlx_loop_hook(struc->mlx, put_pixel, struc);
	mlx_loop_hook(struc->mlx, ft_hook, struc);
	mlx_loop(struc->mlx);
	mlx_terminate(struc->mlx);
}
