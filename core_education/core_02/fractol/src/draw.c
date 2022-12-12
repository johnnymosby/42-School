/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:03:21 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/12 11:16:55 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_image_fr *fr)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	while (i < fr->width)
	{
		j = 0;
		while (j < fr->height)
		{
			x = (i - fr->x - fr->x_zoom) * fr->zoom;
			y = (j - fr->y - fr->y_zoom) * fr->zoom;
			if ((fabs(fmod(x, 100.0)) < 50.0 && fabs(fmod(y, 100.0)) < 50.0)
				|| (fabs(fmod(x, 100.0)) >= 50.0 && fabs(fmod(y, 100.0)) >= 50.0))
			{
				new_mlx_pixel_put(fr, i, j, 0x00FAFA6E);
			}
			else
			{
				new_mlx_pixel_put(fr, i, j, 0x00089F8F);
			}
			j++;
		}
		i++;
	}
}

void	new_mlx_pixel_put(t_image_fr *data, int x, int y, int color)
{
	char	*dst;

	if (data->what_image == 0)
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	else
		dst = data->addr2 + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}