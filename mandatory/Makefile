# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azabir <azabir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 00:12:37 by yagnaou           #+#    #+#              #
#    Updated: 2022/10/29 20:10:26 by azabir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
# Color Variables
# =============================================================================


BLACK		=	"\033[1;30m"
GRAY		=	"\033[1;30m"
RED			=	"\033[1;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[1;33m"
PURPLE		=	"\033[1;35m"
CYAN		=	"\033[1;36m"


# =============================================================================
# GCC & Flags Variables
# =============================================================================


CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit


# =============================================================================
# Name & File Names Variables
# =============================================================================


NAME		=	cub3D
MAN_LIBFT	=	libft/
SRC			=	srcs/

SRCS		=	${MAN_LIBFT}/ft_atoi.c			\
				${MAN_LIBFT}/free_array.c		\
				${MAN_LIBFT}/ft_bzero.c			\
				${MAN_LIBFT}/ft_calloc.c		\
				${MAN_LIBFT}/ft_isalnum.c		\
				${MAN_LIBFT}/ft_isdigit.c		\
				${MAN_LIBFT}/ft_split.c			\
				${MAN_LIBFT}/ft_strcmp.c		\
				${MAN_LIBFT}/ft_strdup.c		\
				${MAN_LIBFT}/ft_strjoin.c		\
				${MAN_LIBFT}/ft_strlen.c		\
				${MAN_LIBFT}/ft_strtrim.c		\
				${MAN_LIBFT}/ft_substr.c		\
				${SRC}/main.c					\
				${SRC}/check_file.c				\
				${SRC}/check_for.c				\
				${SRC}/check_map_utils.c		\
				${SRC}/check_map.c				\
				${SRC}/check_path_utils.c		\
				${SRC}/check_path.c				\
				${SRC}/fill_and_get_colors.c	\
				${SRC}/game_cords_check.c		\
				${SRC}/game_data_init.c			\
				${SRC}/game_data_update.c		\
				${SRC}/game_drawing.c			\
				${SRC}/key_hook.c				\
				${SRC}/rendering.c				\
				${SRC}/ray_utils.c				\

OBJS		=	${SRCS:.c=.o}



# =============================================================================
# Rules
# =============================================================================


all			:	${NAME}

${NAME}		:	${SRCS}
				@echo "---> Compiling Mandatory..."
				@${CC} ${CFLAGS} ${MLX_FLAGS} ${SRCS} -o ${NAME}
				@echo "---> Compilation done."

%.o			:	%.c
				@${CC} ${CFLAGS} -c $< -o $@ 

clean		:
				@rm -f ${OBJS}
				@echo "---> Cleaning object files..."
				@echo "---> Cleaned!"

fclean		:
				@rm -f  ${OBJS}
				@rm -f  ${NAME}
				@rm -rf libmlx.dylib
				@echo "---> Cleaning ${NAME} with it's object files..."
				@echo "---> All cleaned!"

re			:	fclean all
