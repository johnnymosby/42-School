/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:24:12 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/11/29 16:12:57 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../lib/mlx_osx/mlx.h"
# include "../lib/mlx_osx/mlx.h"
# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# define MAX_N_ITERATION 250
# define FR_WIDTH 1280
# define FR_HEIGHT 720

typedef struct s_image_fr {
	void	*img;
	void	*img2;
	char	*addr;
	char	*addr2;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	char	*usr_choice;
	int		if_to_render;
	int		width;
	int		height;
	int		x;
	int		y;
	int		what_image;
}	t_image_fr;

void	new_mlx_pixel_put(t_image_fr *data, int x, int y, int color)
{
	char	*dst;

	if (data->what_image == 0)
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	else
		dst = data->addr2 + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

#endif