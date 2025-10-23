NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = 
OBJS = $(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} -I./Libft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Compiling pipex..."
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)

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
