NAME = so_long
CFLAGS = -Wall -Wextra -Werror
SRCS_MANDATORY = so_long.c creating_map.c checking_map.c error_handling.c help.c checking_map2.c
OBJS = $(SRCS_MANDATORY:.c=.o)
LIBFT = lib/Libft
PRINTF = lib/printf
GET_NEXT_LINE = lib/get_next_line
INLIBFT = -L $(LIBFT) -lft
INPRINTF = -L $(PRINTF) -lftprintf
INGET_NEXT_LINE = -L $(GET_NEXT_LINE) -lget_next_line

all: $(NAME)

$(NAME): $(OBJS)
	@cd $(LIBFT) && $(MAKE)
	@cd $(PRINTF) && $(MAKE)
	@cd $(GET_NEXT_LINE) && $(MAKE)
	cc $(OBJS) $(INLIBFT) $(INPRINTF) $(INGET_NEXT_LINE) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@cd $(LIBFT) && $(MAKE) clean
	@cd $(PRINTF) && $(MAKE) clean
	@cd $(GET_NEXT_LINE) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	@cd $(LIBFT) && $(MAKE) fclean
	@cd $(PRINTF) && $(MAKE) fclean
	@cd $(GET_NEXT_LINE) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re