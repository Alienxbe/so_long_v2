/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 04:00:44 by mykman            #+#    #+#             */
/*   Updated: 2022/08/12 08:32:47 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>
#include <stdio.h>

static int	ajust_frame_rate(int animation_time)
{
	if (animation_time < (CLOCKS_PER_SEC / FPS_MAX))
	{
		usleep((CLOCKS_PER_SEC / FPS_MAX) - animation_time);
		animation_time = (CLOCKS_PER_SEC / FPS_MAX);
	}
	return (CLOCKS_PER_SEC / animation_time);
}

int		update(t_data *d)
{
	clock_t	update_time;

	update_time = clock();
	if (!d->active_scene->update)
		ft_error("No update function to active scene");
	if (!d->active_scene->update(d->active_scene->param))
		ft_error("Scene update error");
	ft_put_image_to_window(d->mlx, d->win, d->active_scene->img, (t_point){0});
	ft_printf("FPS: %d\n", ajust_frame_rate(clock() - update_time));
	return (1);
}

void	so_long(int argc, const char **argv)
{
	t_data	d;

	(void)argc;
	(void)argv;
	ft_bzero(&d, sizeof(d));
	d.mlx = mlx_init();
	if (!d.mlx)
		ft_error("Mlx init failed");
	d.win = ft_new_window(d.mlx, new_point(WIN_WIDTH, WIN_HEIGHT), WIN_NAME,
		&ft_endexec);
	if (!d.win.win_ptr)
		ft_error("Window init failed");

	ft_randinit();
	
	d.scene_collection[sc_waiting] = new_scene_waiting(d.mlx, d.win.size);
	d.scene_collection[sc_title_screen] = new_scene_title_screen(d.mlx, d.win.size);
	d.active_scene = d.scene_collection[sc_title_screen];

	mlx_loop_hook(d.mlx, &update, &d);
	mlx_loop(d.mlx);
}

int main(int argc, const char **argv)
{
	if (argc != 2)
		ft_error("Usage: ./so_long [map_path]");
	so_long(argc, argv);
	return (0);
}
