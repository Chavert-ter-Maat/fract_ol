/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 16:47:23 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/13 15:20:16 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_color_set(t_fractol *generate, int iter)
{
	int	layer;

	if (iter == MAX_ITTER)
		return (generate->colors.black);
	layer = iter / LAYER_RANGE;
	switch (layer)
	{
		case 0:
			return (generate->colors.color_set1);
		case 1:
		{
			if (generate->colors.color_type == TRIPPY)
				return (generate->colors.color_set4 = ft_randomize(generate));	
			return (generate->colors.color_set2);
		}
		case 2:
			return (generate->colors.color_set3);
		case 3:
			return (generate->colors.color_set4);
		 case 4:
			return (generate->colors.color_set5);
		case 5:
			return (generate->colors.color_set6);
		default:
			return (generate->colors.black);
	}
}

void	get_color(t_fractol *generate, int x, int y, int iter)
{
	int color;

	color = get_color_set(generate, iter);
	mlx_put_pixel(generate->image, x, y, color);
}


int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	ft_pixel_burning(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 25 | r << 24 | a);
}

uint32_t	ft_randomize(t_fractol *generate)
{
	uint32_t color;
	
	if (generate->fractal_type == BURNINGSHIP)
	{
		color = ft_pixel_burning(
				rand() % 0xFF, // R
				rand() % 0xFF, // R
				rand() % 0xFF, // R
				rand() % 0xFF  // R
			);
	}
	else
	{
		color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
	}
	return (color);
}
