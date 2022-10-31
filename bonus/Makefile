# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azabir <azabir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 00:12:37 by yagnaou           #+#    #+#              #
#    Updated: 2022/10/31 21:03:08 by azabir           ###   ########.fr        #
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


# =============================================================================
# Name & File Names Variables
# =============================================================================


NAME		=	cub3D_bonus
LIBFT		=	libft/
SRC			=	srcs/

SRCS		=	${LIBFT}/ft_atoi.c				\
				${LIBFT}/free_array.c			\
				${LIBFT}/ft_bzero.c				\
				${LIBFT}/ft_calloc.c			\
				${LIBFT}/ft_isalnum.c			\
				${LIBFT}/ft_isdigit.c			\
				${LIBFT}/ft_split.c				\
				${LIBFT}/ft_strcmp.c			\
				${LIBFT}/ft_strdup.c			\
				${LIBFT}/ft_strjoin.c			\
				${LIBFT}/ft_strlen.c			\
				${LIBFT}/ft_strtrim.c			\
				${LIBFT}/ft_substr.c			\
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

bonus		:	${NAME}

${NAME}		:	${SRCS}
				@make -C minilibx
				@mv minilibx/libmlx.dylib .
				@echo "---> Compiling Bonus..."
				@${CC} ${CFLAGS} ${SRCS} libmlx.dylib -o ${NAME}
				@echo "---> Compilation Done."

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

.PHONY: clean bonus fclean
