/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 09:54:07 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/22 14:59:35 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_pixel(void* param)
{
	uint32_t x;
	uint32_t y;
	uint32_t red;
	t_struct	*struc;

	struc = param;
	x = 0;
	y = 0;
	red = 0xFF0000FF;
	while (y < 200)
	{
		x = 0;
		while (x < 200)
		{
			mlx_put_pixel(struc->image, x, y, red);
			x++;
		}
		y++;
	}
}
	
int32_t main(int32_t argc, char **argv)
{
	t_struct struc;
	
	if (argc != 2)
	{
		ft_printf("input error");
		exit (EXIT_FAILURE);
	}
	init(&struc, argv[1]);
	initialize(&struc);
	return (EXIT_SUCCESS);
}
