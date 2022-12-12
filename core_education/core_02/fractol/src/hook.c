/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:15:12 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/12 11:16:31 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int button, int x, int y, t_image_fr *fr)
{
	printf("x: %i\n", x);
	printf("y: %i\n", y);
	if (button == 1)
	{
		fr->x += fr->width - x;
		fr->y += fr->height - y;
		fr->if_to_render = 0;
		render_image(fr);
	}
	else if (button == KEY_ZOOM_IN)
	{
		fr->x += x / 2;
		fr->y += y / 2;
		fr->prev_x = x;
		fr->prev_y = y;
		fr->if_to_render = 0;
		zoom_image(button, fr);
		render_image(fr);
	}
	else if (button == KEY_ZOOM_OUT)
	{
		fr->x -= x / 2;
		fr->y -= y / 2;
		fr->prev_x = x;
		fr->prev_y = y;
		fr->if_to_render = 0;
		zoom_image(button, fr);
		render_image(fr);
	}
	printf("x: %i\n", fr->x);
	printf("y: %i\n\n", fr->y);
	return (0);
}

int	zoom_image(int keycode, t_image_fr *fr)
{
	if (keycode == KEY_ZOOM_IN)
	{
		fr->zoom /= 1.1;
	}
	else if (keycode == KEY_ZOOM_OUT)
	{
		fr->zoom *= 1.1;
	}
	return (0);
}

int	pressed_key(int button, t_image_fr *fr)
{
	if (button == KEY_ESC)
		exit_fractol(fr);
	return (0);
}