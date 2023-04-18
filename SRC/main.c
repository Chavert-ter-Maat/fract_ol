/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 09:54:07 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/18 10:59:04 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int32_t	main(int32_t argc, char **argv)
{
	t_fractol	generate;

	if (argc != 3)
	{
		error_message();
		exit (EXIT_FAILURE);
	}
	init_fractal_settings(&generate, argv);
	init_mlx(&generate);
	return (EXIT_SUCCESS);
}
