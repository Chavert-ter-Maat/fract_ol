# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: chaverttermaat <chaverttermaat@student.      +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/07 10:49:31 by chavertterm   #+#    #+#                  #
#    Updated: 2023/03/24 18:07:33 by cter-maa      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME 	= fractol
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
RM 		= rm -f
SANITIZE = -fsanitize=address
LDFLAGS	?= -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -o3 -march=native

# INCLUDES
INCLUDES	= -I ./libft -I ./libft/ft_printf -I ./MLX42

# LIBRARIES
PRINTF = ./libft/ft_printf/libftprintf.a
LIBFT = ./libft/libft.a
MLX = ./MLX42/build/libmlx42.a

# SOURCES
SRC =	coloring.c \
		hooks.c \
		initialize_mlx.c \
		initialize_parameters.c \
		main.c \
		
		
# OBJECTS
OBJ			= $(SRC:.c=.o)

# COLORS
DEF_COLOR 	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN 		= \033[0;96m
WHITE 		= \033[0;97m

# RULES
all: $(NAME)

make comp: all clean
	@echo "$(GREEN) Run that shit! $(DEF_COLOR)"
	 
$(NAME): $(OBJ)
	$(MAKE) -C ./MLX42/build
	$(CC) $(LDFLAGS) $(OBJ) $(INCLUDES) $(MLX) $(LIBFT) $(PRINTF) $(CFLAGS) $(SANITIZE) -o $(NAME) 
	@echo "$(GREEN) Fract-ol compiled $(DEF_COLOR)"
	 
clean:
	$(RM) $(OBJ)
	@echo "$(YELLOW) Fract-ol object files cleaned $(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(BLUE) Fract-ol object files & executable cleaned $(DEF_COLOR)"

re: fclean all
	$(RM) $(OBJ)
