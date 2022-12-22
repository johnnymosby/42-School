/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:15:37 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/22 01:01:18 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_image(t_image_fr *fr)
{
	if (fr->if_to_render == 0)
	{
		if (fr->to_calculate == 0)
		{
			fr->what_calculation = (fr->what_calculation + 1) % 2;
			calculate(fr);
			fr->to_calculate = 1;
			fr->to_paint = 0;
		}
		if (fr->to_paint == 0)
		{
			paint(fr);
			fr->to_paint = 1;
		}
		if (fr->what_image == 0)
			mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, 0, 0);
		else
			mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img2, 0, 0);
		fr->what_image = (fr->what_image + 1) % 2;
		fr->if_to_render = 1;
	}
	return (fr->if_to_render);
}

void	paint(t_image_fr *fr)
{
	int i;
	int j;

	i = fr->width;
	j = fr->height;
	while (i > 0)
	{
		j = fr->height;
		while (j > 0)
		{
			new_mlx_pixel_put(fr, i, j, choose_colour(fr, i, j));
			j--;
		}
		i--;
	}
}
