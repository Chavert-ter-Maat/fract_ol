/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_navigation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 11:32:08 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/06 13:10:49 by cter-maa      ########   odam.nl         */
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
	// if (mlx_is_key_down(generate->mlx, MLX_KEY_PAGE_UP))
	// 	generate->nav.zoom_factor /= calculate_mulitplier(&generate->nav);
	// if (mlx_is_key_down(generate->mlx, MLX_KEY_PAGE_DOWN))
	// 	generate->nav.zoom_factor *= calculate_mulitplier(&generate->nav);
	if (mlx_is_key_down(generate->mlx, MLX_KEY_R))
		reset_fractol_settings(generate);
	init_fractal(generate);
}




