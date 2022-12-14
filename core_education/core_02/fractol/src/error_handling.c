/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:17:30 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/14 11:23:36 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	check_input(int argc, char *argv[])
{
	if (argc > 2)
	{
		ft_putstr_fd("Too many arguments", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (argc < 2)
	{
		ft_putstr_fd("Too few arguments [mandelbrot, julia]", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (ft_strcmp(argv[1], "mandelbrot") != 0
		&& ft_strcmp(argv[1], "julia") != 0
		&& ft_strcmp(argv[1], "grid") != 0)
	{
		ft_putstr_fd("Wrong argument [mandelbrot, julia]", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	exit_fractol(t_image_fr *fr)
{
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_destroy_image(fr->mlx, fr->img2);
	mlx_destroy_window(fr->mlx, fr->mlx_win);
	exit(EXIT_SUCCESS);
}

void	exit_with_message(t_image_fr *fr, char *message)
{
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_destroy_image(fr->mlx, fr->img2);
	mlx_destroy_window(fr->mlx, fr->mlx_win);
	ft_putstr_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
