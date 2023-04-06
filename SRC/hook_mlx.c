/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 11:31:11 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/04 14:57:04 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void init_mlx(t_fractol *generate)
{
	open_screen(generate);
	new_image(generate);
	image_to_window(generate);
	hooks(generate);
}

 void open_screen(t_fractol *generate)
{
	if (!(generate->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		{
			ft_printf("error");
			exit (EXIT_FAILURE);
		}
	}
}

void new_image(t_fractol *generate)
{
	if (!(generate->image = mlx_new_image(generate->mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(generate->mlx);
		puts(mlx_strerror(mlx_errno));
		ft_printf("error");
		exit (EXIT_FAILURE);
	}
}

void image_to_window(t_fractol *generate)
{
	if (mlx_image_to_window(generate->mlx, generate->image, 0, 0) == FAILURE)
	{
		mlx_close_window(generate->mlx);
		puts(mlx_strerror(mlx_errno));
		ft_printf("error");
		exit (EXIT_FAILURE);
	}
}

void hooks(t_fractol *generate)
{
	mlx_scroll_hook(generate->mlx, &my_scrollhook, generate);
	mlx_loop_hook(generate->mlx, hook, generate);
	mlx_loop(generate->mlx);
	mlx_terminate(generate->mlx);
}
