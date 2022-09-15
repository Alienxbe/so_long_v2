/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:23:09 by mykman            #+#    #+#             */
/*   Updated: 2022/09/15 23:22:02 by mykman           ###   ########.fr       */
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
	assets = sfe_load_sprite_sheet(sc->sfe, "assets/CelestePico8-v1-32x32.xpm", (t_point){32, 32});
	if (!assets)
		return (0);
	sfe_scene_setbg(sc->scene, 0x4000);

	// Test des sprites
	int i = -1;
	while (assets[++i].img)
		sfe_image_cpy(assets[i], *sc->scene.img, add_point((t_point){0}, (t_point){i % 16 * 32, i / 16 * 32}));
	ft_printf("Il y a %d sprites\n", i);
	return (1);
}

int	main_update(t_sc_main *sc)
{
	return (sc->running);
}
