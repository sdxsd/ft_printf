NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
ARCHIVE = ar rcs
CFILES = \
		ft_printf.c \
		ft_printf_utils.c
OFILES = $(CFILES:.c=.o)

all: $(NAME) c_libft

$(NAME): $(OFILES)
	@ar -rcs $(NAME) $?
	@echo "COMPILED FT_PRINTF"
	@echo ""

c_libft:
	@make -C libft/

%.o: %.c
	@$(CC) $(CFLAGS) -c $<
	@echo COMPILED: $<

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f $(OFILES)
	@rm -f a.out
	@make -C libft/ fclean
	@echo "CLEANING FT_PRINTF"

re: fclean all
