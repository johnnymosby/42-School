/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:24:12 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/14 12:25:19 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#ifdef __APPLE__
# include "../lib/mlx_osx/mlx.h"
#endif

#ifdef __linux__
# include "../lib/mlx_linux/mlx.h"
#endif

# include "../lib/libft/libft.h"
# include "../inc/mlx_keys.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
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
	double	x;
	double	y;
	double	cx;
	double	cy;
	double	x_offset;
	double	y_offset;
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
	double	zoom;
	int		what_image;
}	t_image_fr;

void	check_input(int argc, char *argv[]);
int		choose_colour(int i);
void	draw(t_image_fr *fr);
int		draw_burningship(double x, double y);
int		draw_grid(double x, double y);
int		draw_julia(t_image_fr *fr, double zx, double zy);
int		draw_mandelbrot(double x0, double y0);
int		exit_fractol(t_image_fr *fr);
void	exit_with_message(t_image_fr *fr, char *message);
void	init_t_image_fr(t_image_fr	*fr, char *choice_fr);
int		mouse_hook(int button, int x, int y, t_image_fr *fr);
void	new_mlx_pixel_put(t_image_fr *data, int x, int y, int color);
int		pressed_key(int button, t_image_fr *fr);
int		render_image(t_image_fr *fr);
void	shift_picture(int x, int y, t_image_fr *fr);
int		zoom_image(int keycode, int x, int y, t_image_fr *fr);

#endif