/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:15:12 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/13 21:51:55 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int keycode, int x, int y, t_image_fr *fr)
{
	if (keycode == 1)
	{
		shift_picture(x, y, fr);
		fr->if_to_render = 0;
		render_image(fr);
	}
	else if (keycode == KEY_ZOOM_IN)
	{
		fr->if_to_render = 0;
		zoom_image(keycode, x, y, fr);
		render_image(fr);
	}
	else if (keycode == KEY_ZOOM_OUT)
	{
		fr->if_to_render = 0;
		zoom_image(keycode, x, y, fr);
		render_image(fr);
	}
	return (0);
}

void	shift_picture(int x, int y, t_image_fr *fr)
{
	double	w;
	double	h;
	double	shift_x;
	double	shift_y;

	w = (fr->max_x - fr->min_x) * fr->zoom;
	h = (fr->max_y - fr->min_y) * fr->zoom;
	shift_x = w * 0.25 * fabs((double)fr->width / 2 - x) / fr->width;
	shift_y = h * 0.25 * fabs((double)fr->height / 2 - y) / fr->height;
	fr->x_offset += shift_x * (x > (fr->width / 2) - x < (fr->width / 2));
	fr->y_offset += shift_y * (y > (fr->height / 2) - y < (fr->height / 2));
}

int	zoom_image(int keycode, int x, int y, t_image_fr *fr)
{
	double	old_x;
	double	old_y;
	double	new_x;
	double	new_y;

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
