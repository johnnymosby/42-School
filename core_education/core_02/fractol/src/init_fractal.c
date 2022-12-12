/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:59:12 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/12 11:00:20 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_t_image_fr(t_image_fr	*fr, char *choice_fr)
{
	fr->mlx = mlx_init();
	if (fr->mlx == NULL)
		exit_with_message(fr, "Error: mlx_init() failed");
	fr->mlx_win = mlx_new_window(fr->mlx, FR_WIDTH, FR_HEIGHT, "Fractol");
	if (fr->mlx_win == NULL)
		exit_with_message(fr, "Error: mlx_new_window() failed");
	fr->img = mlx_new_image(fr->mlx, FR_WIDTH, FR_HEIGHT);
	fr->img2 = mlx_new_image(fr->mlx, FR_WIDTH, FR_HEIGHT);
	if (fr->img == NULL || fr->img2 == NULL)
		exit_with_message(fr, "Error: mlx_new_image() failed");
	fr->addr = mlx_get_data_addr(fr->img, &fr->bits_per_pixel,
			&fr->line_length, &fr->endian);
	fr->addr2 = mlx_get_data_addr(fr->img2, &fr->bits_per_pixel,
			&fr->line_length, &fr->endian);
	if (fr->addr == NULL || fr->addr2 == NULL)
		exit_with_message(fr, "Error: mlx_get_data_addr() failed");
	fr->usr_choice = choice_fr;
	fr->if_to_render = 0;
	fr->width = FR_WIDTH;
	fr->height = FR_HEIGHT;
	fr->x = FR_WIDTH / 2;
	fr->y = FR_HEIGHT / 2;
	fr->x_zoom = 0;
	fr->y_zoom = 0;
	fr->what_image = 0;
	fr->zoom = 1;
	fr->prev_x = 0;
	fr->prev_y = 0;
}