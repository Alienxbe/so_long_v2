/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_title_screen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:34:01 by mykman            #+#    #+#             */
/*   Updated: 2022/08/12 16:20:06 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scene_title_screen.h"
#include "ft_memory.h"
#include "ft_math.h"
#include "ft_printf.h"
#include "mlx.h"
#include <stdlib.h>

static void	rand_sf(t_snow_flake *sf, int win_height)
{
	sf->pos.y = ft_rand(win_height);
	sf->size = ft_randint(1, 5);
	sf->speed = ft_randint(1, 10);
}

static int	update(t_scene_title_screen *scene)
{
	t_snow_flake	*sf;

	// ft_scene_setbg(scene->scene, 0x0);
	for (int i = 0; i < SF_COUNT; i++)
	{
		sf = scene->sf_list + i;
		ft_pixel_fill(scene->scene.img, (t_area){sf->pos, {sf->pos.x + sf->size, sf->pos.y + sf->size}}, 0x0);
		if (sf->pos.x > scene->scene.img.size.x)
		{
			sf->pos.x = 0;
			sf->speed = 0;
		}
		if (!sf->speed)
			rand_sf(sf, scene->scene.img.size.y);
		sf->pos.x += sf->speed;
		ft_pixel_fill(scene->scene.img,
			(t_area){sf->pos, {sf->pos.x + sf->size, sf->pos.y + sf->size}},
			0x00FFFFFF);
	}
	return (1);
}

static t_scene_title_screen	*init_scene(void *mlx, t_point size)
{
	t_scene_title_screen	*scene;

	scene = ft_calloc(1, sizeof(*scene));
	scene->scene = new_scene(mlx, size, &update, scene);
	if (!scene || !scene->scene.img.img)
	{
		free(scene);
		return (NULL);
	}
	return (scene);
}

t_scene	*new_scene_title_screen(void *mlx, t_point size)
{
	t_scene_title_screen	*scene;

	scene = init_scene(mlx, size);
	if (!scene)
		return (NULL);
	ft_scene_setbg(scene->scene, 0x00000000);
	for (int i = 0; i < SF_COUNT; i++)
		scene->sf_list[i].pos.x = ft_rand(scene->scene.img.size.x);
	return (&scene->scene);
}
