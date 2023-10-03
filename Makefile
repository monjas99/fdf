# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmonjas- <dmonjas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 10:00:52 by dmonjas-          #+#    #+#              #
#    Updated: 2023/10/03 10:06:21 by dmonjas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
RM = rm -rf
CC = gcc
CFLAGS = -Wextra -Wall -Werror -g3 -fsanitize=address

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a
LIB_INC = ./libft/inc/
INC_DIR = ./inc/

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC_FILES = ft_fdf.c ft_file_read.c ft_error.c ft_error_utils.c ft_init.c ft_draw.c \
                ft_draw_utils.c ft_keys.c ft_utils.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

INCLUDE = -I$(INC_DIR) -I$(LIB_INC)

all: $(OBJ_DIR) $(LIBFT) $(MLX) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(INLUDE) $(LIBFT) -o $(NAME)
	@echo "fdf correcto"

$(LIBFT):
	@make -C $(LIBFT_DIR)
clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR) $(NAME)
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "fdf borrado"
re: fclean all
.PHONY: all re clean fclean
