# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 00:12:37 by yagnaou           #+#    #+#              #
#    Updated: 2022/10/07 12:53:04 by yagnaou          ###   ########.fr        #
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


CC			=	gcc -fsanitize=address -g3
CFLAGS		=	#-Wall -Werror -Wextra
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit


# =============================================================================
# Name & File Names Variables
# =============================================================================


NAME		=	cub
INCLUDE		=	includes/
LIBFT		=	libft/
SRC			=	src/

SRCS		=	${LIBFT}/ft_atoi.c				\
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
				${SRC}/check_file.c				\
				${SRC}/check_for.c				\
				${SRC}/check_map.c				\
				${SRC}/check_path.c				\
				${SRC}/main.c					\
				${SRC}/game_cords_check.c		\
				${SRC}/game_data_init.c			\
				${SRC}/game_data_update.c		\
				${SRC}/game_drawing.c			\
				${SRC}/key_hook.c				\
				${SRC}/map_chekcer.c			\
				${SRC}/rendering.c				\
				${SRC}/ray_utils.c				\


OBJS		=	$(SRCS:.c=.o)


# =============================================================================
# Rules
# =============================================================================


all			:	$(NAME)

$(NAME)		:	$(SRCS)
				@echo "---> Compiling \n$${HEADER}"
				@${CC} $(CFLAGS) ${MLXFLAGS} $(SRCS) -o $(NAME)
				@echo "---> Compilation done."

clean		:
				@rm -rf $(OBJS)
				@echo "---> Cleaning object files..."
				@echo "---> Cleaned!"

fclean		:
				@rm -rf $(OBJS)
				@rm -rf $(NAME)
				@echo "---> Cleaning ${NAME} with it's object files..."
				@echo "---> All cleaned!"

re			:	fclean all
