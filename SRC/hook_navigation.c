/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_navigation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 11:32:08 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/07 18:46:05 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void hook(void* param)
{
	t_fractol *generate;

	generate = param;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(generate->mlx);
	if (mlx_is_key_down(generate->mlx, MLX_KEY_UP))
		generate->nav.y_nav -= generate->nav.nav_step;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_DOWN))
		generate->nav.y_nav += generate->nav.nav_step;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_LEFT))
		generate->nav.x_nav -= generate->nav.nav_step;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_RIGHT))
		generate->nav.x_nav += generate->nav.nav_step;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_S))
		generate->nav.nav_step *= 4;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_W))
		generate->nav.nav_step /= 4;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_D))
		generate->colors.i += 2;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_A))
		generate->colors.i -= 2;
	if (mlx_is_key_down(generate->mlx, MLX_KEY_R))
		reset_fractol_settings(generate);
	init_fractal(generate);
}





