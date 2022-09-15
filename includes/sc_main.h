/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:23:17 by mykman            #+#    #+#             */
/*   Updated: 2022/09/13 23:34:07 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SC_MAIN_H
# define SC_MAIN_H

# include "t_scene.h"

typedef struct s_sc_main
{
	t_sfe			*sfe;
	t_scene			scene;
	t_bool			running;
}	t_sc_main;

int	main_init(t_sc_main *sc);
int	main_update(t_sc_main *sc);

#endif
