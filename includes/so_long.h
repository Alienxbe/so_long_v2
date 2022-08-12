/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:30:05 by mykman            #+#    #+#             */
/*   Updated: 2022/08/12 04:21:31 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "libft_mlx.h"
# include "ft_printf.h"
# include "ft_memory.h"
# include "ft_math.h"

# include "ft_scene.h"
# include "ft_scene_waiting.h"

# define WIN_WIDTH	600
# define WIN_HEIGHT	450
# define WIN_NAME	"ft_mlx test"
 #define FPS_MAX	120

// => Should go in libft_mlx
typedef union u_trgb
{
	t_color	color;
	struct
	{
		t_byte	b;
		t_byte	g;
		t_byte	r;
		t_byte	t;
	};
}	t_trgb;

enum e_scene_list
{
	sc_waiting,
	SC_MAX
};

typedef struct s_data
{
	void		*mlx;
	t_window	win;
	t_scene		*active_scene;
	t_scene		*scene_collection[SC_MAX];
}	t_data;

// Exit functions

void	ft_exit(const char *msg, int value);
void	ft_error(const char *msg);
int		ft_endexec(void);

#endif
