/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 09:54:07 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/03 10:49:27 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
	
int32_t main(int32_t argc, char **argv)
{
	t_fractol	generate;
	
	if (argc != 2)
	{
		ft_printf(argv[0]);
		ft_printf("input error");
		exit (EXIT_FAILURE);
	}
	init_param(&generate, argv[1]);
	init_mlx(&generate);
	return (EXIT_SUCCESS);
}
