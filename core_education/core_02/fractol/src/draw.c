/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:03:21 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/13 18:04:51 by rbasyrov         ###   ########.fr       */
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
			x = (4 * (double)i / fr->width - fr->x) * fr->zoom + fr->x_offset;
			y = (4 * (double)j / fr->width - fr->y) * fr->zoom + fr->y_offset;
			if ((fabs(fmod(x, 0.1)) < 0.05 && fabs(fmod(y, 0.1)) < 0.05)
				|| (fabs(fmod(x, 0.1)) >= 0.05 && fabs(fmod(y, 0.1)) >= 0.05))
			{
				new_mlx_pixel_put(fr, i, j, 0x00089F8F);
			}
			else
			{
				new_mlx_pixel_put(fr, i, j, 0x00FAFA6E);
			}
			j++;
		}
		i++;
	}
	printf("somex: %f\n", fabs(fmod(((double)x / fr->width - fr->x + fr->x_offset) * fr->zoom, 0.1)));
	printf("somey: %f\n\n", fabs(fmod(((double)y / fr->height - fr->y + fr->y_offset) * fr->zoom, 0.1)));
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