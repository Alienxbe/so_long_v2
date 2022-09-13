/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 04:00:44 by mykman            #+#    #+#             */
/*   Updated: 2022/09/05 20:02:57 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "sfe_event.h"
#include "ft_printf.h"
#include <stdlib.h>

int	on_key_down(int key, t_sc_main *sc)
{
	if (key == 53)
		sc->running = false;
	ft_printf("Key pressed: %d\n", key);
	return (1);
}

int	main(void)
{
	t_sfe		*sfe;
	t_sc_main	sc;

	sfe = sfe_init(WIN_NAME, new_point(WIN_DIM));
	sfe_set_max_fps(sfe, 120);

	sc.scene = sfe_new_scene(sfe, &main_init, &main_update, &sc);
	sc.sfe = sfe;

	sfe_set_active_scene(sfe, &sc.scene);
	sfe_hook(sfe, ON_KEYDOWN, &on_key_down, &sc);

	sfe_loop(sfe);
	return (0);
}
