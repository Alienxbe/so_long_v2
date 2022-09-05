/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:23:09 by mykman            #+#    #+#             */
/*   Updated: 2022/09/05 19:52:42 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sc_main.h"
#include "sfe_scene.h"
#include "ft_printf.h"

int	main_init(t_sc_main *sc)
{
	ft_printf("Init scene main\n");
	sc->color = 0x5a32a8;
	return (1);
}

int	main_update(t_sc_main *sc)
{
	sfe_scene_setbg(sc->scene, sc->color);
	sc->color += 0xFFFFFF;
	return (1);
}
