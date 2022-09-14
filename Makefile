# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mykman <mykman@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 04:00:41 by mykman            #+#    #+#              #
#    Updated: 2022/09/14 22:26:04 by mykman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------VARS-------------------------------------

CURRENT_FOLDER		:=	$(shell pwd)

ifeq ($(OS),Windows_NT) 
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif

# ---------------------------------Compilation---------------------------------

CC					:=	@gcc
CFLAGS				:=	-Wall -Wextra -Werror

ifeq ($(detected_OS), Linux)
	MLXFLAGS		:=	-lXext -lX11 -lm -lz
else ifeq ($(detected_OS), Darwin)
	MLXFLAGS		:=	-framework OpenGL -framework AppKit
endif

# ---------------------------------Librairies----------------------------------

FT_FOLDER			:=	libs/libft
MLX_FOLDER			:=	libs/libmlx_${detected_OS}
SFE_FOLDER			:=	libs/SnowFlakeEngine

FT					:=	${FT_FOLDER}/libft.a
MLX					:=	${MLX_FOLDER}/libmlx.a
SFE					:=	${SFE_FOLDER}/libsfe.a

MAKE_FT				:=	@make -s -C ${FT_FOLDER}
MAKE_MLX			:=	@make -s -C ${MLX_FOLDER}
MAKE_SFE			:=	@make -s -C ${SFE_FOLDER}

INCLUDES			:=	-I ${FT_FOLDER}/includes \
						-I ${MLX_FOLDER} \
						-I ${SFE_FOLDER}/includes \
						-I ./includes
LIBRARIES			:=	-L./${FT_FOLDER} -lft \
						-L./${MLX_FOLDER} -lmlx \
						-L./${SFE_FOLDER} -lsfe

# --------------------------------Source files---------------------------------

NAME				:=	so_long
FILES				:=	main.c \
						sc_main.c \
						sfe_load_sprite_sheet.c
SRCS				:=	$(addprefix srcs/, ${FILES})
FILES				:=	so_long.h
HEADERS				:=	$(addprefix includes/, ${FILES});

# -----------------------------------Rules-------------------------------------

$(NAME):	${FT} ${MLX} ${SFE} ${SRCS} ${HEADERS}
	${CC} ${CFLAGS} ${SRCS} ${INCLUDES} ${LIBRARIES} ${MLXFLAGS} -o $@

$(FT):
	${MAKE_FT}

$(MLX):
	${MAKE_MLX}

$(SFE):
	${MAKE_SFE} LIBFT_FOLDER=${CURRENT_FOLDER}/${FT_FOLDER} \
				MLX_FOLDER=${CURRENT_FOLDER}/${MLX_FOLDER}

all:	${NAME}

clean:
	${MAKE_FT} clean
	${MAKE_MLX} clean
	${MAKE_SFE} clean

fclean:
	${MAKE_FT} fclean
	${MAKE_MLX} clean
	${MAKE_SFE} fclean
	@rm -f ${NAME}

re:		fclean all

# -----------------------------------.PHONY------------------------------------

.PHONY:	all clean fclean re