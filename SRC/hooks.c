/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 11:32:08 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/03 10:49:55 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void ft_hook(void* param)
{
	t_fractol *generate;

	generate = param;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(generate->mlx);
	if (mlx_is_key_down(generate->mlx, MLX_KEY_UP))
		generate->image->instances[0].y -= 10;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_DOWN))
		generate->image->instances[0].y += 10;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_LEFT))
		generate->image->instances[0].x -= 10;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_RIGHT))
		generate->image->instances[0].x += 10;
}

