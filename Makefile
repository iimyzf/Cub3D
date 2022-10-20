# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yagnaou <yagnaou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 00:12:37 by yagnaou           #+#    #+#              #
#    Updated: 2022/10/19 10:58:38 by yagnaou          ###   ########.fr        #
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
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g3
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit


# =============================================================================
# Name & File Names Variables
# =============================================================================


NAME		=	Cub3D
INCLUDE		=	srcs/include/
LIBFT		=	libft/
SRC			=	srcs/

SRCS		=	${LIBFT}ft_atoi.c			\
				${LIBFT}ft_bzero.c			\
				${LIBFT}ft_calloc.c			\
				${LIBFT}ft_isalnum.c		\
				${LIBFT}ft_isdigit.c		\
				${LIBFT}ft_split.c			\
				${LIBFT}ft_strcmp.c			\
				${LIBFT}ft_strdup.c			\
				${LIBFT}ft_strjoin.c		\
				${LIBFT}ft_strlen.c			\
				${LIBFT}ft_strtrim.c		\
				${LIBFT}ft_substr.c			\
				${SRC}check_file.c			\
				${SRC}check_for.c			\
				${SRC}check_map.c			\
				${SRC}check_path.c			\
				${SRC}cub.c					\


OBJS		=	$(SRCS:.c=.o)


# =============================================================================
# Rules
# =============================================================================


all			:	$(NAME)

$(NAME)		:	$(SRCS)
				@echo ${YELLOW}"---> Compiling..."
				@${CC} $(CFLAGS) ${MLXFLAGS} $(SRCS) -o $(NAME)
				@echo ${GREEN}"---> Compilation done."

clean		:
				@rm -rf $(OBJS)
				@echo ${PURPLE}"---> Cleaning object files..."
				@echo ${PURPLE}"---> Cleaned!"

fclean		:
				@rm -rf $(OBJS)
				@rm -rf $(NAME)
				@echo ${RED}"---> Cleaning ${NAME} with it's object files..."
				@echo ${RED}"---> All cleaned!"

re			:	fclean all