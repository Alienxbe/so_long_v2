/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:29:47 by mykman            #+#    #+#             */
/*   Updated: 2022/08/10 14:32:14 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(const char *msg, int value)
{
	ft_fprintf(STDERR_FILENO, "%s\n", msg);
	exit(value);
}

void	ft_error(const char *msg)
{
	ft_exit(msg, EXIT_FAILURE);
}

int		ft_endexec(void)
{
	exit(EXIT_SUCCESS);
}
