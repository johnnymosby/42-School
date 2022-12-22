/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:03:21 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/22 16:36:03 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_fractal(t_image_fr *fr)
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
				save_iteration(fr, calc_mandelbrot(x, y), i, j);
			else if (ft_strcmp(fr->usr_choice, "julia") == 0)
				save_iteration(fr, calc_julia(fr, x, y), i, j);
			else if (ft_strcmp(fr->usr_choice, "burningship") == 0)
				save_iteration(fr, calc_burningship(x, y), i, j);
			j++;
		}
		i++;
	}
}

void	save_iteration(t_image_fr *fr, int iteration, int i, int j)
{
	if (fr->what_calculation == 0)
	{
		*(fr->calculation + j * FR_WIDTH + i) = iteration;
	}
	else
	{
		*(fr->calculation_alt + j * FR_WIDTH + i) = iteration;
	}
}

int	calc_mandelbrot(double x0, double y0)
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
}

int	calc_julia(t_image_fr *fr, double zx, double zy)
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
	return (i);
}

int	calc_burningship(double x, double y)
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
	return (i);
}


