/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exception_err.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:17:30 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/29 16:29:03 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	check_input(int argc, char *argv[])
{
	if (argc == 3 && (ft_strcmp(argv[1], "julia") != 0
			|| (ft_strcmp(argv[2], "2") != 0 && ft_strcmp(argv[2], "4") != 0)))
	{
		ft_putstr_fd("Too many arguments or wrong arguments", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (argc > 3)
	{
		ft_putstr_fd("Too many arguments", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (argc < 2 || (argc == 2 && (ft_strcmp(argv[1], "julia") == 0)))
	{
		ft_putstr_fd("Too few arguments [mandelbrot, julia [2/4], burningship]",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (ft_strcmp(argv[1], "mandelbrot") != 0
		&& ft_strcmp(argv[1], "julia") != 0
		&& ft_strcmp(argv[1], "burningship") != 0)
	{
		ft_putstr_fd("Wrong argument [mandelbrot, julia [2/4], burningship]",
			STDERR_FILENO);
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
	if (fr->calculation != NULL)
		free(fr->calculation);
	if (fr->calculation_alt != NULL)
		free(fr->calculation);
	ft_putstr_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
