# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquincho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 09:46:38 by aquincho          #+#    #+#              #
#    Updated: 2022/05/13 09:46:41 by aquincho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

HEAD_PATH	= includes/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
RM			= rm -f
AR			= ar rcs

LIBFT_PATH		= libft/
LIBFT_HEAD_PATH = libft/includes/

MLX_PATH 		= mlx_linux/

SRCS_PATH		= srcs/
SRCS_FUNCTIONS	= so_long ft_init ft_errors ft_free ft_map ft_check_map \
ft_init_mlx ft_game ft_move ft_draw_map
SRCS = $(addprefix $(SRCS_PATH), $(addsuffix .c, $(SRCS_FUNCTIONS)))

HEAD_FLAGS		= -I $(LIBFT_HEAD_PATH) -I $(HEAD_PATH) -I $(MLX_PATH)
LIBS_DIR_FLAGS	= -L $(LIBFT_PATH) -L $(MLX_PATH)
LIBFT_FLAG		= -lft
MLX_FLAGS		= -lmlx_Linux -lXext -lX11 -lm -lz
LIBS_FLAGS		= $(LIBFT_FLAG) $(MLX_FLAGS)


OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEAD_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\033[33;32m=== Compilating libraries \t\t\t\t\e[0m"
	make all -s -C $(LIBFT_PATH)
	make all -s -C $(MLX_PATH)
	@echo "\033[33;32m=== Compilation libraries\t\t\t\tDONE\e[0m"
	$(CC) $(CFLAGS) $(LIBS_DIR_FLAGS) $(OBJS) -o $(NAME) $(LIBS_FLAGS)
	@echo "\033[33;32m=== Compilation so_long \t\t\t\tDONE\e[0m"

all: $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)
	@echo "\033[33;32m=== so_long object files deleted \t\t\t\tDONE\e[0m"

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)
	@echo "\033[33;32m=== so_long bin file deleted \t\t\tDONE\e[0m"

re: fclean all

.PHONY: clean fclean re all
