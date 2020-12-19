##
## EPITECH PROJECT, 2020
## Sample Makefile
## File description:
## A sample of a Makefile to start Epitech
##

CC			=	gcc

AR 			= 	ar rc

CFLAGS 		=	-W -Wall -Wextra -pedantic -Werror -I./include

SRC 		=   my_math/my_pow.c \
				my_math/my_putnbr_base.c \
				my_math/my_putnbr_base_unsigned.c \
				my_math/get_nb_size.c \
				my_math/get_nb_size_unsigned.c \
				my_math/my_putnbr.c \
				my_math/my_putnbr_unsigned.c \
				\
				my_stdlib/my_bzero.c \
				my_stdlib/my_calloc.c \
				my_stdlib/my_getnbr.c \
				my_stdlib/my_itoa.c \
				my_stdlib/my_memset.c \
				my_stdlib/my_pointer_swap.c \
				my_stdlib/my_sort_int_array.c \
				my_stdlib/my_strdup.c \
				my_stdlib/my_str_to_word_array.c \
				my_stdlib/my_swap.c \
				my_stdlib/my_put_pointer.c \
				my_stdlib/my_memcpy.c \
				\
				my_stdio/my_putchar.c \
				my_stdio/my_putstr.c \
				\
				my_str/is_capital_letter.c \
				my_str/is_lowercase_letter.c \
				my_str/is_an_alpha_letter.c \
				my_str/is_num_letter.c \
				my_str/is_printable.c \
				my_str/is_char_alphanum.c \
				my_str/my_len_array.c \
				my_str/my_put_in_str.c \
				my_str/my_revstr.c \
				my_str/my_showstr.c \
				my_str/my_strcat.c \
				my_str/my_strcmp.c \
				my_str/my_strcpy.c \
				my_str/my_strlen.c \
				my_str/my_strncat.c \
				my_str/my_strncmp.c \
				my_str/my_strncpy.c \
				my_str/my_strstr.c \
				my_str/my_word_count.c \
				my_str/print_char_in_hex.c \
				my_str/print_char_in_oct.c \
				my_str/print_char_in_loop.c \
				my_str/my_str_realocat.c \
				\
				my_stdio/my_printf.c \
				print_formatter/my_printf_parser.c \
				print_formatter/get_modificater_flag.c \
				\
				print_formatter/vn_redirect/my_vn_putchar.c \
				print_formatter/vn_redirect/my_vn_putstr.c \
				print_formatter/vn_redirect/my_vn_putnbr.c \
				print_formatter/vn_redirect/my_vn_puthex.c \
				print_formatter/vn_redirect/my_vn_putoct.c \
				print_formatter/vn_redirect/my_vn_putbin.c \
				print_formatter/vn_redirect/my_vn_putpointer.c \
				print_formatter/vn_redirect/my_vn_putunsigned.c

OBJ 		=	$(SRC:.c=.o)

NAME 		=	libmy.a

all:		$(NAME) copy

$(NAME): build_lib

build_lib: 	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	cp $(NAME) ../
	cp $(NAME) ../../

copy:
	mkdir -p ../../include
	cp include/*.h ../../include

clean: ## Clean every temporay well knowed files
	@find . -type f \( -name "\#*\#" -o -name "*.swp" \) -delete
	@find . -type f \( -name "*.gc*" -o -name "a.out" \) -delete
	@find . -type f \( -name "*.o" -o -name "*~" -o -name "*.a" \) -delete
	@echo "Cleaned project !"

fclean:		clean ## Call clean rule nothing more

re:			fclean all ## Call fclean then all rule

test: tests_run ## An alias to tests_run

tests_run: clean ## Cleans the project and run the unit tests
	make copy -C ./lib/my
	$(CC) $(SRC_TEST) $(CFLAGS) $(TEST_FLAGS) -o $(UNIT_TEST_EXEC)
	./$(UNIT_TEST_EXEC)

usage: ## Print the usage
	@grep -h "##" Makefile | sed -e 's/\(\:.*\#\#\)/\:\ /' | grep -v grep | sed -e 's/\\$$//' | sed -e 's/##//'
	@echo "\nEnjoy the project ! :D"

.PHONY:		all build_lib copy clean fclean re
