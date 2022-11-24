/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:12:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/11/24 13:15:52 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(void)
{
	img_mlx	img;

	img.xlen = 1280;
	img.ylen = 720;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.xlen, img.ylen, "Hello world!");
	img.img = mlx_new_image(img.mlx, img.xlen, img.ylen);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	new_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win,  17, 0L, close, &img);
	mlx_loop(img.mlx);
}
