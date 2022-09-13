/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:23:09 by mykman            #+#    #+#             */
/*   Updated: 2022/09/11 18:07:47 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sc_main.h"
#include "sfe_scene.h"
#include "sfe_image.h"
#include "ft_printf.h"

int	main_init(t_sc_main *sc)
{
	ft_printf("Init scene main\n");
	sc->running = true;

	return (1);
}

int	main_update(t_sc_main *sc)
{
	return (sc->running);
}
