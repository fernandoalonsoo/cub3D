# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fealonso <fealonso@student.42madrid.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 23:20:48 by fealonso          #+#    #+#              #
#    Updated: 2025/08/11 10:20:00 by fealonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -pthread -Iinclude -Ilibft

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

MINIFLG = -L./minilibx -lmlx -framework OpenGL -framework AppKit

SRCS	=	src/utils/borrar.c \
			main.c \
			src/utils/error.c \
			src/utils/free.c \
			src/utils/initialize.c \
			src/parser/parser.c \
			src/parser/read_cub_file.c \
			get_next_line/src/get_next_line.c \

OBJS	= $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) # $(MINIFLG)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
