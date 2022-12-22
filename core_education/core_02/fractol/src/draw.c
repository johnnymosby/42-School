/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:03:21 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/22 01:00:36 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate(t_image_fr *fr)
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
			x = 2 * (((double)i - fr->width / 2) / fr->width)
				* fr->zoom + fr->x_offset;
			y = 2 * (((double)j - fr->height / 2) / fr->width)
				* fr->zoom + fr->y_offset;
			if (ft_strcmp(fr->usr_choice, "mandelbrot") == 0)
				save_iteration(fr, draw_mandelbrot(x, y), i, j);
			else if (ft_strcmp(fr->usr_choice, "julia") == 0)
				save_iteration(fr, draw_julia(fr, x, y), i, j);
			else if (ft_strcmp(fr->usr_choice, "grid") == 0)
				save_iteration(fr, draw_grid(x, y), i, j);
			else if (ft_strcmp(fr->usr_choice, "burningship") == 0)
				save_iteration(fr, draw_burningship(x, y), i, j);
			j++;
		}
		i++;
	}
}

void 	save_iteration(t_image_fr * fr, int iteration, int i, int j)
{
	if (fr->what_calculation == 0)
	{
		*(fr->calculation + j * FR_WIDTH + i) = iteration;
	}
	else
	{
		*(fr->calculation_alt + j * FR_WIDTH + i) = iteration;
	}
	//printf("%i\n", iteration);
}

int	draw_grid(double x, double y)
{
	if ((fabs(fmod(x, 0.1)) < 0.05 && fabs(fmod(y, 0.1)) < 0.05)
		|| (fabs(fmod(x, 0.1)) >= 0.05 && fabs(fmod(y, 0.1)) >= 0.05))
	{
		return (0);
	}
	else
	{
		return (200);
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
	return (i);
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
	//printf("%i\n", i);
	if (i == MAX_N_ITERATION)
		return (0);
	else
		return (i);
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
		return (0);
	else
		return (i);
}

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
	//printf("iteration = %i\n", iteration);
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
