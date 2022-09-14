/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:23:09 by mykman            #+#    #+#             */
/*   Updated: 2022/09/14 22:32:19 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sc_main.h"
#include "sfe_scene.h"
#include "sfe_image.h"
#include "ft_printf.h"

int	main_init(t_sc_main *sc)
{
	t_img	*assets;

	ft_printf("Init scene main\n");
	sc->running = true;
	assets = sfe_load_sprite_sheet(sc->sfe, "assets/CelestePico8V0.1.xpm", (t_point){32, 32});
	if (assets)
		sfe_image_cpy(assets[0], *sc->scene.img, (t_point){0, 0});
	return (1);
}

int	main_update(t_sc_main *sc)
{
	return (sc->running);
}
