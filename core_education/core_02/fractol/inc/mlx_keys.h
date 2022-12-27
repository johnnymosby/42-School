/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:42:42 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/27 16:58:39 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEYS_H
# define MLX_KEYS_H

#ifdef __APPLE__
# define KEY_ESC 53
# define KEY_ZOOM_IN 4
# define KEY_ZOOM_OUT 5
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
#endif

#ifdef __linux__
# define KEY_ESC 65307
# define KEY_ZOOM_IN 4
# define KEY_ZOOM_OUT 5
# define KEY_ONE 49
# define KEY_TWO 50
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
#endif

#endif