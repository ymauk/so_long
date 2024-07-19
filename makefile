NAME = so_long
NAME_B = so_long_bonus
CFLAGS = -Wall -Wextra -Werror -I ./include -I $(MLX)/include
SRC = src/so_long.c src/creating_map.c src/checking_map.c src/error_handling.c src/help.c src/checking_map2.c src/checking_map3.c src/free_all.c\
				src/image_handling.c src/start.c src/movement_handling.c src/help2.c
SRCBNS = srcbns/so_long_bonus.c srcbns/creating_map_bonus.c srcbns/checking_map_bonus.c srcbns/error_handling_bonus.c srcbns/help_bonus.c srcbns/checking_map2_bonus.c srcbns/checking_map3_bonus.c srcbns/free_all_bonus.c\
				srcbns/image_handling_bonus.c srcbns/start_bonus.c srcbns/movement_handling_bonus.c srcbns/help2_bonus.c
OBJS = $(SRC:.c=.o)
OBJSB = $(SRCBNS:.c=.o)
LIBFT = lib/Libft
PRINTF = lib/printf
GET_NEXT_LINE = lib/get_next_line
MLX = lib/libmlx
INLIBFT = -L $(LIBFT) -lft
INPRINTF = -L $(PRINTF) -lftprintf
INGET_NEXT_LINE = -L $(GET_NEXT_LINE) -lget_next_line
INMLX = -L $(MLX)/build -lmlx42 -ldl -lglfw -pthread -lm

$(NAME): $(OBJS)
	@cd $(LIBFT) && $(MAKE)
	@cd $(PRINTF) && $(MAKE)
	@cd $(GET_NEXT_LINE) && $(MAKE)
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
	cc $(OBJS) $(INLIBFT) $(INPRINTF) $(INGET_NEXT_LINE) $(INMLX) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
$(NAME_B): $(OBJSB)
	@cd $(LIBFT) && $(MAKE)
	@cd $(PRINTF) && $(MAKE)
	@cd $(GET_NEXT_LINE) && $(MAKE)
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
	cc $(OBJSB) $(INLIBFT) $(INPRINTF) $(INGET_NEXT_LINE) $(INMLX) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME_B)

all: $(NAME)

bonus: $(NAME_B)

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJSB)
	@cd $(LIBFT) && $(MAKE) clean
	@cd $(PRINTF) && $(MAKE) clean
	@cd $(GET_NEXT_LINE) && $(MAKE) clean
	@rm -rf $(MLX)/build

fclean: clean
	rm -f $(NAME) $(NAME_B)
	@cd $(LIBFT) && $(MAKE) fclean
	@cd $(PRINTF) && $(MAKE) fclean
	@cd $(GET_NEXT_LINE) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
