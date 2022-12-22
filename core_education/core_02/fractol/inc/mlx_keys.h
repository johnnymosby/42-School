/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:42:42 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/21 22:52:26 by rbasyrov         ###   ########.fr       */
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
#endif

#ifdef __linux__
# define KEY_ESC 65307
# define KEY_ZOOM_IN 4
# define KEY_ZOOM_OUT 5
#endif

#endif