NAME = libftprintf.a

HEADER = ft_printf.h

SRC = ft_atoi.c ft_isdigit.c ft_itoa.c ft_printf.c ft_putchar.c\
	ft_putnbr.c ft_putstr.c ft_strchr.c ft_strlen.c initialize_struct.c\
	parser.c print_digits.c create_structure.c ft_isalpha.c print_me.c\
	print_chars.c print_strings.c print_pointers.c to_hex.c print_hex.c\
	ft_bzero.c print_unsigned.c print_formated_u.c print_formated_u_p2.c\
	router.c ft_strdup.c flag_check.c print_formated_helpers.c print_formated_helpers_part2.c\
	print_formated_hex_helpers.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
