NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = ft_atoi.c \
ft_calloc.c \
ft_isalpha.c \
ft_isascii.c \
ft_memset.c \
ft_strchr.c \
ft_strlen.c \
ft_strrchr.c \
ft_tolower.c \
ft_toupper.c \
ft_bzero.c \
ft_strdup.c \
ft_putnbr_fd.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_strjoin.c \
ft_itoa.c \
ft_putendl_fd.c \
ft_isdigit.c \
ft_isalnum.c \
ft_memmove.c \
ft_memchr.c \
ft_isprint.c \
ft_memcpy.c \
ft_split.c \
ft_strlcpy.c \
ft_strmapi.c \
ft_memcmp.c \
ft_strtrim.c \
ft_strlcat.c \
ft_strnstr.c \
ft_substr.c \
ft_strncmp.c \
ft_striteri.c \
ft_printf_utils_2.c \
ft_printf_utils.c \
ft_printf.c \
ft_strcat.c \
ft_strcmp.c \
ft_strjoin_free.c
BONUS_SRCS = ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
$(NAME): $(OBJS)
	@echo "Compiling libft 📚..."
	@ar rcs $(NAME) $(OBJS)
all: $(NAME)
bonus: $(BONUS_OBJS)
	@echo "🌟 Compiling bonus libft 🌟"
	@ar rcs $(NAME) $(BONUS_OBJS)
clean:
	@echo "🗑️ Removing objs "
	@$(RM) $(OBJS) $(BONUS_OBJS)
fclean: clean
	@echo "🗑️ Removing $(NAME)"
	@$(RM) $(NAME)
so: $(OBJS)
	$(CC) -shared -o libft.so $(OBJS) $(BONUS_OBJS)
re: fclean all
.PHONY: all clean fclean re so bonus
