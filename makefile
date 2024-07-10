NAME = so_long
CFLAGS = -Wall -Wextra -Werror -I ./include -I $(MLX)/include
SRCS_MANDATORY = so_long.c creating_map.c checking_map.c error_handling.c help.c checking_map2.c checking_map3.c free_map.c\
				image_handling.c start.c movement_handling.c
OBJS = $(SRCS_MANDATORY:.c=.o)
LIBFT = lib/Libft
PRINTF = lib/printf
GET_NEXT_LINE = lib/get_next_line
MLX = lib/libmlx
INLIBFT = -L $(LIBFT) -lft
INPRINTF = -L $(PRINTF) -lftprintf
INGET_NEXT_LINE = -L $(GET_NEXT_LINE) -lget_next_line
INMLX = -L $(MLX)/build -lmlx42 -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(OBJS)
	@cd $(LIBFT) && $(MAKE)
	@cd $(PRINTF) && $(MAKE)
	@cd $(GET_NEXT_LINE) && $(MAKE)
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
	cc $(OBJS) $(INLIBFT) $(INPRINTF) $(INGET_NEXT_LINE) $(INMLX) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME) -fsanitize=address

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@cd $(LIBFT) && $(MAKE) clean
	@cd $(PRINTF) && $(MAKE) clean
	@cd $(GET_NEXT_LINE) && $(MAKE) clean
	@rm -rf $(MLX)/build

fclean: clean
	rm -f $(NAME)
	@cd $(LIBFT) && $(MAKE) fclean
	@cd $(PRINTF) && $(MAKE) fclean
	@cd $(GET_NEXT_LINE) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re