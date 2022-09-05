# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/12 04:39:40 by mykman            #+#    #+#              #
#    Updated: 2022/09/05 16:17:38 by mykman           ###   ########.fr        #
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

# SnowFlakeEngine installation or update
if [ ! -d "libs/SnowFlakeEngine" ]
then
	git clone https://github.com/Alienxbe/SnowFlakeEngine libs/SnowFlakeEngine
else
	git -C libs/SnowFlakeEngine pull
fi
