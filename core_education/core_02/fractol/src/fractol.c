/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:12:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/29 16:12:45 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(int argc, char *argv[])
{
	t_image_fr	fr;

	check_input(argc, argv);
	init_fr_memory_win(&fr);
	init_t_image_fr(&fr, argv[1]);
	if (argc == 3)
		if (ft_strcmp(argv[2], "4") == 0)
			fr.what_julia = 4;
	mlx_loop_hook(fr.mlx, render_image, &fr);
	mlx_key_hook(fr.mlx_win, pressed_key, &fr);
	mlx_mouse_hook(fr.mlx_win, mouse_hook, &fr);
	mlx_hook(fr.mlx_win, 17, 0L, exit_fractol, &fr);
	mlx_loop(fr.mlx);
}
