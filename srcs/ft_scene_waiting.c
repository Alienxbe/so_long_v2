/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_waiting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:41:23 by mykman            #+#    #+#             */
/*   Updated: 2022/08/12 16:14:53 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scene_waiting.h"
#include "ft_memory.h"
#include "ft_printf.h"
#include <stdlib.h>

static void	check_collisions(t_scene scene, t_square *square)
{
	if (square->pos.p2.x > scene.img.size.x)
		square->move.x = -square->move.x;
	if (square->pos.p2.y > scene.img.size.y)
		square->move.y = -square->move.y;
	if (square->pos.p1.x < 0)
		square->move.x = -square->move.x;
	if (square->pos.p1.y < 0)
		square->move.y = -square->move.y;
}

static int	update(t_scene_waiting	*scene)
{
	t_square	*square;

	if (!scene)
		return (0);
	square = &scene->square;
	ft_pixel_fill(scene->scene.img, square->pos, 0x00FFFFFF);
	square->pos = (t_area) {
		add_point(square->pos.p1, square->move),
		add_point(square->pos.p2, square->move)
	};
	check_collisions(scene->scene, square);
	ft_pixel_fill(scene->scene.img, square->pos, 0x00FF0000);
	return (1);
}

t_scene	*new_scene_waiting(void *mlx, t_point size)
{
	t_scene_waiting	*scene;

	scene = ft_calloc(1, sizeof(*scene));
	scene->scene = new_scene(mlx, size, &update, scene);
	if (!scene || !scene->scene.img.img)
	{
		free(scene);
		return (NULL);
	}
	scene->square = (t_square){{{0, 0}, {50, 50}}, {5, 5}};
	ft_scene_setbg(scene->scene, 0x00FFFFFF);
	return (&scene->scene);
}
