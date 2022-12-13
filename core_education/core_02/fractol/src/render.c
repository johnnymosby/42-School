/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:15:37 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/13 22:08:24 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_image(t_image_fr *fr)
{
	if (fr->if_to_render == 0)
	{
		if (ft_strcmp(fr->usr_choice, "mandelbrot") == 0)
			draw(fr);
		if (fr->what_image == 0)
			mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, 0, 0);
		else
			mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img2, 0, 0);
		fr->what_image = (fr->what_image + 1) % 2;
		fr->if_to_render = 1;
	}
	return (fr->if_to_render);
}
