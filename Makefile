NAME    = cub3D
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
SRCS    = main.c
OBJS    = $(addprefix obj/, $(SRCS:.c=.o))
GREEN   = \033[0;32m
RED     = \033[0;31m
CODE    = \033[m

all: obj $(NAME)

obj:
	@mkdir -p obj

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)[✓]$(CODE)"

obj/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@rm -rf $(OBJS)
	@echo "$(RED)[DELETED]$(CODE)"
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
