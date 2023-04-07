/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 16:47:23 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/04/07 13:39:00 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int32_t	color_shift(t_colors *colors)
{
	return (colors->r * colors->i << 24 | colors->g * colors->i << 16
		| colors->b * colors->i << 8);
}
