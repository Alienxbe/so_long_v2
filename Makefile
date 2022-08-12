# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 04:00:41 by mykman            #+#    #+#              #
#    Updated: 2022/08/12 07:02:01 by mykman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC					:=	@gcc
CFLAGS				:=	-Wall -Wextra -Werror

MLXFLAGS			:= -framework OpenGL -framework AppKit

CURRENT_FOLDER		:=	$(shell pwd)
LIBFT_FOLDER		:=	libs/libft
LIBFT_MLX_FOLDER	:=	libs/libft_mlx
MLX_FOLDER			:=	libs/libmlx

MAKE_LIBFT			:= @make -s -C ${LIBFT_FOLDER}
MAKE_LIBFT_MLX		:= @make -s -C ${LIBFT_MLX_FOLDER}
MAKE_MLX			:= @make -s -C ${MLX_FOLDER}

INCLUDES			:=	-I ${LIBFT_FOLDER}/includes \
						-I ${LIBFT_MLX_FOLDER}/includes \
						-I ${MLX_FOLDER} \
						-I ./includes
LIBRARIES			:=	-L ${LIBFT_FOLDER} -lft \
						-L ${LIBFT_MLX_FOLDER} -lft_mlx \
						-L ${MLX_FOLDER} -lmlx

NAME				:=	so_long
FILES				:=	main.c \
						ft_scene_waiting.c \
						ft_scene_title_screen.c \
						ft_exit.c
SRCS				:=	$(addprefix srcs/, ${FILES})
FILES				:=	so_long.h \
						ft_scene_waiting.h \
						ft_scene_title_screen.h
HEADERS				:=	$(addprefix includes/, ${FILES});

${NAME}:	${SRCS} ${HEADERS}
	${MAKE_LIBFT}
	${MAKE_MLX}
	${MAKE_LIBFT_MLX} LIBFT_FOLDER=${CURRENT_FOLDER}/${LIBFT_FOLDER} \
		MLX_FOLDER=${CURRENT_FOLDER}/${MLX_FOLDER}
	${CC} ${CFLAGS} ${MLXFLAGS} ${SRCS} ${INCLUDES} ${LIBRARIES} -o $@

all:	${NAME}

clean:
	${MAKE_LIBFT} clean
	${MAKE_LIBFT_MLX} clean
	${MAKE_MLX} clean

fclean:
	${MAKE_LIBFT} fclean
	${MAKE_LIBFT_MLX} fclean
	${MAKE_MLX} clean
	@rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re