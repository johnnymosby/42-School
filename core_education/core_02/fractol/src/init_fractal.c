/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:59:12 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/22 00:22:03 by rbasyrov         ###   ########.fr       */
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
	fr->calculation = malloc(sizeof(int) * FR_WIDTH * FR_HEIGHT);
	fr->calculation_alt = malloc(sizeof(int) * FR_WIDTH * FR_HEIGHT);
	if (fr->calculation == NULL || fr->calculation_alt == NULL)
		exit_with_message(fr, "Error: malloc() failed");
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
	fr->x = 2.0;
	fr->y = 1.0;
	fr->x = 0.0;
	fr->y = 0.0;
	fr->x_offset = 0.0;
	fr->y_offset = 0.0;
	fr->max_x = 2.0;
	fr->max_y = 1.0;
	fr->min_x = -2.0;
	fr->min_y = -1.0;
	fr->what_image = 0;
	fr->zoom = 1.0;
	fr->what_palette = 0;
	fr->what_calculation = 0;
	fr->to_calculate = 0;
	fr->to_paint = 0;
}
