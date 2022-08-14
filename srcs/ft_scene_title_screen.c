/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_title_screen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:34:01 by mykman            #+#    #+#             */
/*   Updated: 2022/08/14 22:28:49 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scene_title_screen.h"
#include "ft_memory.h"
#include "ft_math.h"
#include "ft_printf.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static void	rand_sf(t_snow_flake *sf, int win_height)
{
	sf->pos.y = ft_rand(win_height);
	sf->size = ft_randint(1, 5);
	sf->speed = ft_randint(2, 7);
	if (sf->speed < 3)
		sf->freq = ft_randint(20, 40);
	else
		sf->freq = ft_randint(20, 30);
	sf->power = ft_randint(1, 10);
}

static void	draw_square(t_img img, t_point pos, int size, t_color color)
{
	t_area	area;

	area = point_to_area(pos, new_point(pos.x + size, pos.y + size));
	ft_pixel_fill(img, area, color);
}

static int	update(t_scene_title_screen *scene)
{
	t_snow_flake	*sf;
	int				offset;

	ft_pixel_fill(scene->scene.img,
		point_to_area(scene->player.pos, add_point(scene->player.pos, scene->player.img.size)),
		0x0
	);
	/*
	** SF movement & update
	*/
	for (int i = 0; i < SF_COUNT; i++)
	{
		sf = scene->sf_list + i;
		draw_square(scene->scene.img, sf->last_pos, sf->size, 0x0);
		if (sf->pos.x > scene->scene.img.size.x)
		{
			sf->pos.x = 0;
			sf->speed = 0;
		}
		if (!sf->speed)
			rand_sf(sf, scene->scene.img.size.y);
		sf->pos.x += sf->speed;
		offset = sin(sf->pos.x / sf->freq) * sf->power;
		sf->last_pos = (t_point){sf->pos.x, sf->pos.y + offset};
		draw_square(scene->scene.img, sf->last_pos, sf->size, 0x00FFFFFF);
	}

	/*
	** Player movement & update
	*/
	scene->player.pos = add_point(scene->player.pos, scene->player.speed);
	if (scene->player.pos.x + scene->player.img.size.x + scene->player.speed.x > scene->scene.img.size.x)
		scene->player.speed.x = -scene->player.speed.x / 2;
	if (scene->player.pos.x < 0)
		scene->player.speed.x = -scene->player.speed.x * 2;
	ft_cpy_image(scene->player.img, scene->scene.img, scene->player.pos);
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
	t_img					sprite_sheet;

	scene = init_scene(mlx, size);
	if (!scene)
		return (NULL);

	// SF init
	ft_scene_setbg(scene->scene, 0x00000000);
	for (int i = 0; i < SF_COUNT; i++)
		scene->sf_list[i].pos.x = ft_rand(scene->scene.img.size.x);

	// Player init
	sprite_sheet = ft_xpm_file_to_image(mlx, "assets/beladonis_sprite.xpm");
	if (!sprite_sheet.img)
		return (NULL);
	scene->player.img = ft_new_subimage(mlx, sprite_sheet, (t_area){{65, 65}, {129, 129}});
	if (!scene->player.img.img)
		return (NULL);
	scene->player.pos = new_point(0, 380);
	scene->player.speed = new_point(6, 0);
	return (&scene->scene);
}
