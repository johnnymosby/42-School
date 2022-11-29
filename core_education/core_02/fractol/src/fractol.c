/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:12:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/11/29 14:54:54 by rbasyrov         ###   ########.fr       */
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
		&& ft_strcmp(argv[1], "julia") != 0)
	{
		ft_putstr_fd("Wrong argument [mandelbrot, julia]", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	exit_fractol(t_image_fr *fr)
{
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_destroy_window(fr->mlx, fr->mlx_win);
	exit(EXIT_SUCCESS);
}

void	exit_with_message(t_image_fr *fr, char *message)
{
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_destroy_window(fr->mlx, fr->mlx_win);
	ft_putstr_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	init_t_image_fr(t_image_fr	*fr, char *choice_fr)
{
	fr->mlx = mlx_init();
	if (fr->mlx == NULL)
		exit_with_message(fr, "Error: mlx_init() failed");
	fr->mlx_win = mlx_new_window(fr->mlx, FR_WIDTH, FR_HEIGHT, "Fractol");
	if (fr->mlx_win == NULL)
		exit_with_message(fr, "Error: mlx_new_window() failed");
	fr->img = mlx_new_image(fr->mlx, FR_WIDTH, FR_HEIGHT);
	if (fr->img == NULL)
		exit_with_message(fr, "Error: mlx_new_image() failed");
	fr->addr = mlx_get_data_addr(fr->img, &fr->bits_per_pixel,
			&fr->line_length, &fr->endian);
	if (fr->addr == NULL)
		exit_with_message(fr, "Error: mlx_get_data_addr() failed");
	fr->usr_choice = choice_fr;
	fr->if_to_render = 0;
	fr->width = FR_WIDTH;
	fr->height = FR_HEIGHT;
}

void	draw_mandelbrot(t_image_fr *fr)
{
	int	i;
	int	j;

	i = 0;
	while (i < fr->width)
	{
		j = 0;
		while (j < fr->height)
		{
			if ((i % 100 < 50 && j % 100 < 50) || (i % 100 >= 50 && j % 100 >= 50))
				new_mlx_pixel_put(fr, i, j, 0x00FAFA6E);
			else
				new_mlx_pixel_put(fr, i, j, 0x00089F8F);
			j++;
		}
		i++;
	}
}

int	render_image(t_image_fr *fr)
{
	if (fr->if_to_render == 0)
	{
		if (ft_strcmp(fr->usr_choice, "mandelbrot") == 0)
			draw_mandelbrot(fr);
		mlx_put_image_to_window(fr->mlx, fr->mlx_win, fr->img, 0, 0);
		fr->if_to_render = 1;
	}
	return (fr->if_to_render);
}

int	pressed_key(int keycode, t_image_fr *fr)
{
	if (keycode == 27)
		exit_fractol(fr);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_image_fr	fr;

	check_input(argc, argv);
	init_t_image_fr(&fr, argv[1]);
	mlx_loop_hook(fr.mlx, render_image, &fr);
	mlx_key_hook(fr.mlx_win, pressed_key, &fr);
	mlx_hook(fr.mlx_win, 17, 0L, exit_fractol, &fr);
	mlx_loop(fr.mlx);
}
