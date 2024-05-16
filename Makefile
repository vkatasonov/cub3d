# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 15:51:14 by vkatason          #+#    #+#              #
#    Updated: 2024/05/16 17:03:20 by vkatason         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
USER := $(shell whoami)
CUB3DLIB = cub3D.a
CFLAGS = -Wall -Werror -Wextra 
#-fsanitize=address
CC = gcc -g
CLEAN = rm -Rf
LIBFT = libft
MLX42 = MLX42
SRC = 	check_textures.c \
		cleanup.c \
		copy_map.c \
		extract_color.c \
		extract_data_from_context.c \
		extract_map.c \
		extract_path.c \
		extract_position.c \
		init_checks.c \
		main.c \
		printed_checks.c \
		read_file.c
		
OBJS := $(SRC:.c=.o)

#COLORS
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
DEFAULT	:= \033[0m

all: libftmake mlx42make $(NAME)

$(NAME): $(CUB3DLIB)
# --------- Para el campus ----------
	@$(CC) $(CFLAGS) $(CUB3DLIB) $(LIBFT)/libft.a $(MLX42)/libmlx42.a -lm -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
# -------- Para uso en casa --------
#@$(CC) $(CFLAGS) $(CUB3DLIB) $(LIBFT)/libft.a $(MLX42)/libmlx42.a -lm -I include -lglfw -L"/opt/homebrew/Cellar/glfw/3.4/lib/" -o $(NAME)
	@echo "$(GREEN)The app $(NAME) was successfully compiled. $(DEFAULT)"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
	@echo "$(GREEN)Compiling:$(DEFAULT) $(notdir $<)"
	
$(CUB3DLIB): $(OBJS)
	@ar rcs $(CUB3DLIB) $(OBJS)
	@echo "$(GREEN)Library $(CUB3DLIB) was successfully created.$(DEFAULT)"

clean: mlx42clean libftclean
	@$(CLEAN) ./$(OBJS)
	@echo "$(RED)Removing:$(DEFAULT) all objects of $(NAME)."

fclean: mlx42fclean libftfclean
	@$(CLEAN) ./$(OBJS)
	@echo "$(RED)Removing:$(DEFAULT) all objects of $(NAME)."
	@$(CLEAN) ./$(CUB3DLIB) ./$(NAME)
	@echo "$(RED)Removing:$(DEFAULT) $(CUB3DLIB) Library."
	@echo "$(RED)Removing:$(DEFAULT) $(NAME) Program."

re: fclean all

norma:
	@norminette $(SRC) cub3D.h

mlx42make:
	@make -C $(MLX42)
mlx42clean:
	@make clean -C $(MLX42)
mlx42fclean:
	@make fclean -C $(MLX42)
mlx42re: libftclean libftmake

libftmake:
	@make -C $(LIBFT)
libftclean:
	@make clean -C $(LIBFT)
libftfclean:
	@make fclean -C $(LIBFT)
libftre: libftclean libftmake

.PHONY : all clean fclean re \
libftmake libftclean libftfclean libftre