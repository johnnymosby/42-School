/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:03:21 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/14 12:22:31 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_image_fr *fr)
{
	int		i;
	int		j;
	double	x;
	double	y;
	int		color;

	i = 0;
	while (i < fr->width)
	{
		j = 0;
		while (j < fr->height)
		{
			x = 2 * (((double)i - fr->width / 2) / fr->width)
				* fr->zoom + fr->x_offset;
			y = 2 * (((double)j - fr->height / 2) / fr->width)
				* fr->zoom + fr->y_offset;
			if (ft_strcmp(fr->usr_choice, "mandelbrot") == 0)
				color = draw_mandelbrot(x, y);
			else if (ft_strcmp(fr->usr_choice, "julia") == 0)
				color = draw_julia(fr, x, y);
			else if (ft_strcmp(fr->usr_choice, "grid") == 0)
				color = draw_grid(x, y);
			else if (ft_strcmp(fr->usr_choice, "burningship") == 0)
				color = draw_burningship(x, y);
			new_mlx_pixel_put(fr, i, j, color);
			j++;
		}
		i++;
	}
}

int	draw_grid(double x, double y)
{
	if ((fabs(fmod(x, 0.1)) < 0.05 && fabs(fmod(y, 0.1)) < 0.05)
		|| (fabs(fmod(x, 0.1)) >= 0.05 && fabs(fmod(y, 0.1)) >= 0.05))
	{
		return (0x00089F8F);
	}
	else
	{
		return (0x00FAFA6E);
	}
}

int	draw_mandelbrot(double x0, double y0)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	int		i;

	x2 = 0;
	y2 = 0;
	i = 0;
	while (x2 + y2 <= 4 && i < MAX_N_ITERATION)
	{
		y = 2 * x * y + y0;
		x = x2 - y2 + x0;
		x2 = x * x;
		y2 = y * y;
		i += 1;
	}
	return (choose_colour(i));
/* 	if (i == MAX_N_ITERATION)
		return (0x00000000);
	else
		return (0x00089F8F); */
}

int	draw_julia(t_image_fr *fr, double zx, double zy)
{
	double	xtemp;
	int		i;

	i = 0;
	while (zx * zx + zy * zy < 2 && i < MAX_N_ITERATION)
	{
		xtemp = zx * zx - zy * zy;
		zy = 2 * zx * zy + fr->cy;
		zx = xtemp + fr->cx;
		i += 1;
	}
	if (i == MAX_N_ITERATION)
		return (0x00000000);
	else
		return (choose_colour(i));
}

int	draw_burningship(double x, double y)
{
	double	xtemp;
	double	zx;
	double	zy;
	int		i;

	i = 0;
	zx = x;
	zy = y;
	while (zx * zx + zy * zy < 4 && i < 100)
	{
		xtemp = zx * zx - zy * zy + x;
		zy = fabs(2 * zx * zy) + y;
		zx = xtemp;
		i += 1;
	}
	if (i == 100)
		return (0x00000000);
	else
		return (choose_colour(i));
}

int	choose_colour(int i)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)i / MAX_N_ITERATION;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
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
