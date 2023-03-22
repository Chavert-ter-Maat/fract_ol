/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 11:32:08 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/22 13:40:32 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_hook(void* param)
{
	t_struct *struc;

	struc = param;
	if (mlx_is_key_down(struc->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(struc->mlx);
	if (mlx_is_key_down(struc->mlx, MLX_KEY_UP))
		struc->image->instances[0].y -= 10;
	if (mlx_is_key_down(struc->mlx, MLX_KEY_DOWN))
		struc->image->instances[0].y += 10;
	if (mlx_is_key_down(struc->mlx, MLX_KEY_LEFT))
		struc->image->instances[0].x -= 10;
	if (mlx_is_key_down(struc->mlx, MLX_KEY_RIGHT))
		struc->image->instances[0].x += 10;
}