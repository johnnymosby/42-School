/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:24:12 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/11/29 01:36:13 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../lib/mlx_osx/mlx.h"
# include "../lib/mlx_osx/mlx.h"
# include "../lib/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# define MAX_N_ITERATION = 250
# define FR_WIDTH = 1280
# define FR_HEIGHT = 720

typedef struct s_image_fr {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	char	*usr_choice;
}	t_image_fr;

void	new_mlx_pixel_put(t_image_fr *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

#endif