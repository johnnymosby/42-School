/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:15:12 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/13 19:27:46 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int button, int x, int y, t_image_fr *fr)
{
	double w;
	double h;
	double shift_x;
	double shift_y;

	printf("x: %i\n", x);
	printf("y: %i\n", y);
	if (button == 1)
	{
		w = (fr->max_x - fr->min_x) * fr->zoom;
		h = (fr->max_y - fr->min_y) * fr->zoom;
		shift_x = fabs((double)fr->width / 2 - x) / fr->width;
		shift_y = fabs((double)fr->height / 2 - y) / fr->height;
		if (x > (fr->width / 2) && y < (fr->height / 2))
		{
			fr->x_offset += w * 0.25 * shift_x;
			fr->y_offset -= h * 0.25 * shift_y;
		}
		else if (x < (fr->width / 2) && y < (fr->height / 2))
		{
			fr->x_offset -= w * 0.25 * shift_x;
			fr->y_offset -= h * 0.25 * shift_y;
		}
		else if (x > (fr->width / 2) && y > (fr->height / 2))
		{
			fr->x_offset += w * 0.25 * shift_x;
			fr->y_offset += h * 0.25 * shift_y;
		}
		else if (x < (fr->width / 2) && y > (fr->height / 2))
		{
			fr->x_offset -= w * 0.25 * shift_x;
			fr->y_offset += h * 0.25 * shift_y;
		}
		fr->if_to_render = 0;
		render_image(fr);
	}
	else if (button == KEY_ZOOM_IN)
	{
		fr->if_to_render = 0;
		zoom_image(button, x, y, fr);
		render_image(fr);
	}
	else if (button == KEY_ZOOM_OUT)
	{
		fr->if_to_render = 0;
		zoom_image(button, x, y, fr);
		render_image(fr);
	}
	printf("xoff: %f\n", fr->x_offset);
	printf("yoff: %f\n\n", fr->y_offset);
	printf("somex: %f\n", fabs(fmod(((double)x / fr->width - fr->x + fr->x_offset) * fr->zoom, 0.1)));
	printf("somey: %f\n\n", fabs(fmod(((double)y / fr->height - fr->y + fr->y_offset) * fr->zoom, 0.1)));
	return (0);
}

int	zoom_image(int keycode, int x, int y, t_image_fr *fr)
{
	double old_x;
	double old_y;
	double new_x;
	double new_y;
/* 	double w;
	double h;
	w = (fr->max_x - fr->min_x) * fr->zoom;
	h = (fr->max_y - fr->min_y) * fr->zoom; */

	old_x = 2 * (((double)x - fr->width / 2) / fr->width) * fr->zoom;
	old_y = 2 * (((double)y - fr->height / 2) / fr->width) * fr->zoom;
	if (keycode == KEY_ZOOM_IN)
	{
		fr->zoom /= 1.1;
		new_x = 2 * (((double)x - fr->width / 2) / fr->width) * fr->zoom;
		new_y = 2 * (((double)y - fr->height / 2) / fr->width) * fr->zoom;
		fr->x_offset += (old_x - new_x);
		fr->y_offset += (old_y - new_y);
	}
	else if (keycode == KEY_ZOOM_OUT)
	{
		fr->zoom *= 1.1;
		new_x = 2 * (((double)x - fr->width / 2) / fr->width) * fr->zoom;
		new_y = 2 * (((double)y - fr->height / 2) / fr->width) * fr->zoom;
		fr->x_offset += (old_x - new_x);
		fr->y_offset += (old_y - new_y);
	}
	return (0);
}

int	pressed_key(int button, t_image_fr *fr)
{
	if (button == KEY_ESC)
		exit_fractol(fr);
	return (0);
}
