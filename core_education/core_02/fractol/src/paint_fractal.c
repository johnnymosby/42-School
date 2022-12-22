/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:17:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/22 16:37:02 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	choose_colour(t_image_fr *fr, int i, int j)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		iteration;

	if (fr->what_calculation == 0)
		iteration = (*(fr->calculation + j * FR_WIDTH + i));
	else
		iteration = (*(fr->calculation_alt + j * FR_WIDTH + i));
	if (fr->what_palette == 0)
	{
		t = (double)iteration / MAX_N_ITERATION;
		r = (int)(9 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	if (fr->what_palette == 1)
	{
		t = (double)iteration / MAX_N_ITERATION;
		r = (int)(255 - 9 * (1 - t) * t * t * t * 255);
		g = (int)(255 - 15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(255 - 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	return (r << 16 | g << 8 | b);
}

void	new_mlx_pixel_put(t_image_fr *data, int x, int y, int color)
{
	char	*dst;

	if (data->what_image == 0)
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
	else
		dst = data->addr2 + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}
