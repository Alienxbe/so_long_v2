/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_waiting.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:39:47 by mykman            #+#    #+#             */
/*   Updated: 2022/08/12 03:52:40 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_WAITING_H
# define FT_SCENE_WAITING_H

# include "ft_scene.h"

typedef struct s_square
{
	t_area	pos;
	t_point	move;
}	t_square;

typedef struct s_scene_waiting
{
	t_scene		scene;
	t_square	square;
}	t_scene_waiting;

t_scene	*new_scene_waiting(void *mlx, t_point size);

#endif
