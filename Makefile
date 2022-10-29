# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 00:12:37 by yagnaou           #+#    #+#              #
#    Updated: 2022/10/29 18:06:38 by yagnaou          ###   ########.fr        #
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
BNAME		=	cub3D_bonus
MAN_LIBFT	=	mandatory/libft/
BNS_LIBFT	=	bonus/libft/
SRC			=	mandatory/srcs/
BSRC		=	bonus/srcs/

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

BSRCS		=	${BNS_LIBFT}/ft_atoi.c			\
				${BNS_LIBFT}/free_array.c		\
				${BNS_LIBFT}/ft_bzero.c			\
				${BNS_LIBFT}/ft_calloc.c		\
				${BNS_LIBFT}/ft_isalnum.c		\
				${BNS_LIBFT}/ft_isdigit.c		\
				${BNS_LIBFT}/ft_split.c			\
				${BNS_LIBFT}/ft_strcmp.c		\
				${BNS_LIBFT}/ft_strdup.c		\
				${BNS_LIBFT}/ft_strjoin.c		\
				${BNS_LIBFT}/ft_strlen.c		\
				${BNS_LIBFT}/ft_strtrim.c		\
				${BNS_LIBFT}/ft_substr.c		\
				${BSRC}/main.c					\
				${BSRC}/check_file.c			\
				${BSRC}/check_for.c				\
				${BSRC}/check_map_utils.c		\
				${BSRC}/check_map.c				\
				${BSRC}/check_path_utils.c		\
				${BSRC}/check_path.c			\
				${BSRC}/fill_and_get_colors.c	\
				${BSRC}/game_cords_check.c		\
				${BSRC}/game_data_init.c		\
				${BSRC}/game_data_update.c		\
				${BSRC}/game_drawing.c			\
				${BSRC}/key_hook.c				\
				${BSRC}/rendering.c				\
				${BSRC}/ray_utils.c				\

OBJS		=	${SRCS:.c=.o}

BOBJS		=	${BSRCS:.c=.o}


# =============================================================================
# Rules
# =============================================================================


all			:	${NAME}

bonus		:	${BNAME}

${NAME}		:	${SRCS}
				@echo "---> Compiling Mandatory..."
				@${CC} ${CFLAGS} ${MLX_FLAGS} ${SRCS} -o ${NAME}
				@echo "---> Compilation done."

${BNAME}	:	${BSRCS}
				@make -C minilibx
				@mv minilibx/libmlx.dylib .
				@echo "---> Compiling Bonus..."
				@${CC} ${CFLAGS} ${BSRCS} libmlx.dylib -o ${BNAME}
				@echo "---> Compilation Done."

%.o			:	%.c
				@${CC} ${CFLAGS} -c $< -o $@ 

clean		:
				@rm -f ${OBJS} ${BOBJS}
				@echo "---> Cleaning object files..."
				@echo "---> Cleaned!"

fclean		:
				@rm -f  ${OBJS} ${BOBJS}
				@rm -f  ${NAME} ${BNAME}
				@rm -rf libmlx.dylib
				@echo "---> Cleaning ${NAME} && ${BNAME} with it's object files..."
				@echo "---> All cleaned!"

re			:	fclean all
