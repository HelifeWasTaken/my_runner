##
## EPITECH PROJECT, 2020
## Sample Makefile
## File description:
## A sample of a Makefile to start Epitech
##

CC			=	gcc

CFLAGS 		=	-W -Wall -Wextra -Werror -I./include -g3 -ggdb

LAZYCFLAGS 		=	-W -Wall -Wextra -I./include -g3 -ggdb

LFLAGS 		=	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -L./lib -lmy

MAIN 		= 	main.c \

SRC 		=	src/init/init_scene.c \
				src/game/draw_parralax.c \
				src/game/draw_player.c \
				src/game/draw_background.c \
				src/game/draw_all_game.c

EXEC 	 	=	my_runner

all:  build_lib build ## Calls build_lib and build

build_lib: ## Builds the lib
	make -C ./lib/my -j8

build: ## build the project
	$(CC) $(MAIN) $(SRC) $(CFLAGS) $(LFLAGS) -o $(EXEC)

lazy: ## build the project without Error
	$(CC) $(MAIN) $(SRC) $(LAZYCFLAGS) $(LFLAGS) -o $(EXEC)

run:
	./$(EXEC)

build_run: build run

rerun: re build run

clean: ## Clean every temporay well knowed files
	@find . -type f \( -name "\#*\#" -o -name "*.swp" \) -delete
	@find . -type f \( -name "*.gc*" -o -name "a.out" \) -delete
	@find . -type f \( -name "*.o" -o -name "*~" -o -name "*.a" \) -delete
	@echo "Cleaned project !"

fclean:	clean ## Call clean rule nothing more

re:	fclean all ## Call fclean then all rule

usage: ## Print the usage
	@grep -h "##" Makefile | sed -e 's/\(\:.*\#\#\)/\:\ /' | grep -v grep | sed -e 's/\\$$//' | sed -e 's/##//'
	@echo "\nEnjoy the project ! :D"
	@echo

.PHONY:		all build_lib clean fclean re
