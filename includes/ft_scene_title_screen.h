/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_title_screen.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:34:25 by mykman            #+#    #+#             */
/*   Updated: 2022/08/14 22:26:09 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_TITLE_SCREEN_H
# define FT_SCENE_TITLE_SCREEN_H

# include "ft_scene.h"
# include "ft_point.h"

# define SF_COUNT	100

typedef struct s_snow_flake
{
	t_point			pos;
	t_point			last_pos;
	unsigned int 	size;
	unsigned int	speed;
	unsigned int	freq;
	unsigned int	power;
}	t_snow_flake;

typedef struct s_player
{
	t_img	img;
	t_point	pos;
	t_point	speed;
}	t_player;

typedef struct s_scene_title_screen
{
	t_snow_flake	sf_list[SF_COUNT];
	t_player		player;
	t_scene			scene;
}	t_scene_title_screen;

t_scene	*new_scene_title_screen(void *mlx, t_point size);

#endif
