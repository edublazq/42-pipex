NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = pipex.c error_manager.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} 

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Compiling pipex..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

clean:
	@echo "🗑️ Removing objs"
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "🗑️ Removing $(NAME)"
	@$(RM) $(NAME) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
