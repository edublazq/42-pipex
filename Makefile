NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIBFT_DIR = ./inc/Libft
LIBFT = $(LIBFT_DIR)/libft.a
GNL_DIR = ./inc/get_next_line
GNL = $(GNL_DIR)/get_next_line.c
SRCS = ./srcs/pipex.c ./srcs/error_manager.c ./srcs/childs.c
BONUS_SRCS = ./bonus_srcs/pipex_bonus.c ./bonus_srcs/error_manager_bonus.c \
./bonus_srcs/pipex_utils_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o} 

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Compiling pipex..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

relink:
	touch .bonus

bonus: $(LIBFT) $(BONUS_OBJS) relink
	@echo "Compiling bonus pipex..."
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(GNL) $(LIBFT) -o $(NAME)

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

.PHONY: all clean fclean re relink bonus
