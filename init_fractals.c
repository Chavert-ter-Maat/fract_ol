/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_fractals.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 14:14:39 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/03/28 15:31:09 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 	init_fractal(t_fractol	*generate)
{
	if (generate->choice == MANDELBROT)
		init_mandelbrot(generate);
	else if (generate->choice == JULIA)
		{}
	else if (generate->choice == BURNINGSHIP)
		init_burningship(generate);
}