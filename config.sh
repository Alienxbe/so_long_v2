# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/12 04:39:40 by mykman            #+#    #+#              #
#    Updated: 2022/08/12 04:41:52 by mykman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

# Libft installation or update
if [ ! -d "libs/libft" ]
then
	git clone https://github.com/Alienxbe/libft libs/libft
else
	git -C libs/libft pull
fi

# Libft_mlx installation or update
if [ ! -d "libs/libft_mlx" ]
then
	git clone https://github.com/Alienxbe/libft_mlx libs/libft_mlx
else
	git -C libs/libft_mlx pull
fi
