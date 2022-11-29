/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:12:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/11/29 10:51:22 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	check_input(int argc, char *argv[])
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
		&& ft_strcmp(argv[1], "julia") != 0)
	{
		ft_putstr_fd("Wrong argument [mandelbrot, julia]", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	init_t_image_fr(t_image_fr	*fr, char *choice_fr)
{
	fr->mlx = mlx_init();
	if (fr->mlx == NULL)
	{
		ft_putstr_fd("A problem with mlx intialisation", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fr->img = mlx_new_image(fr->mlx, FR_WIDTH, FR_HEIGHT);
	if (fr->img == NULL)
	{
		ft_putstr_fd("A problem with mlx_new_image", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fr->usr_choice = choice_fr;
}

void	render_image(t_image_fr *fr)
{
	if (ft_strcmp(fr->usr_choice, "mandelbrot") == 0)
		draw_mandelbrot(fr);
}

void	draw_mandelbrot(t_image_fr *fr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
}

int	main(int argc, char *argv[])
{
	t_image_fr	fr;

	check_input(argc, argv);
	init_t_image_fr(&fr, argv[1]);


	mlx_loop_hook(fr.mlx, render_image, &fr);
	mlx_loop(fr.mlx);
}