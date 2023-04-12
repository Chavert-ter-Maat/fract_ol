# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: chaverttermaat <chaverttermaat@student.      +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/07 10:49:31 by chavertterm   #+#    #+#                  #
#    Updated: 2023/04/12 13:19:10 by cter-maa      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME 	= fractol
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
ifdef DEBUG
	CFLAGS += -g
endif

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
SRC =	SRC/colors.c \
		SRC/fractal_burning_ship.c \
		SRC/fractal_mandelbrot.c \
		SRC/fractal_julia.c \
		SRC/hook_mlx.c \
		SRC/hook_keys.c \
		SRC/hook_scroll.c \
		SRC/init_parameters.c \
		SRC/main.c \
		SRC/utils.c \
		
		
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
$(NAME): $(OBJ)
	$(MAKE) -C ./MLX42/build
	# $(MAKE) -C ./libft
	# $(MAKE) -C ./libft/ft_printf
	$(CC) $(LDFLAGS) $(OBJ) $(INCLUDES) $(MLX) $(LIBFT) $(PRINTF) $(CFLAGS) $(SANITIZE) -o $(NAME) 
	@echo "$(GREEN) Fract-ol compiled $(DEF_COLOR)"

# RECIPES
all: $(NAME)

make comp: re all clean
	@echo "$(GREEN) Run that shit! $(DEF_COLOR)"
	 
debug:
	$(MAKE) DEBUG=1

rebug: fclean
	$(MAKE) debug
	
clean:
	$(RM) $(OBJ)
	# $(MAKE) clean -C ./libft
	# $(MAKE) clean -C ./libft/ft_printf
	@echo "$(YELLOW) Fract-ol object files cleaned $(DEF_COLOR)"

fclean: 
	$(RM) $(OBJ)
	@echo "$(YELLOW) Fract-ol object files cleaned $(DEF_COLOR)"
	$(RM) $(NAME)
	@echo "$(RED) Fract-ol object files and executable are cleaned $(DEF_COLOR)"
	# $(MAKE) fclean -C ./libft
	# $(MAKE) fclean -C ./libft/ft_printf
	

re: fclean all
	$(RM) $(OBJ)
