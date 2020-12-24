##
## EPITECH PROJECT, 2020
## Sample Makefile
## File description:
## A sample of a Makefile to start Epitech
##

CC			=	gcc

CFLAGS 		=	-W -Wall -Wextra -Werror -I./include -lm

LAZYCFLAGS 	=	-W -Wall -Wextra -I./include -g3 -ggdb -lm

LFLAGS 		=	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -L./lib -lmy

MAIN 		= 	src/main.c

CSFML_LIB 	= 	./lib/my/my_csfml/animate_sprite.c

SRC 		=	./src/init/init_manager.c \
				./src/init/init_scene.c \
				./src/init/map_loader.c \
				./src/init/get_parralax_textures.c \
				./src/init/get_background.c \
				./src/init/load_enemy_textures.c \
				./src/init/get_player.c \
				./src/init/load_text_textures.c \
				./src/init/getoneline.c \
				./src/init/load_music.c \
				./src/init/enemy_getter/get_mushroom.c \
				./src/init/enemy_getter/get_slime.c \
				./src/init/get_empty_enemy.c \
				\
				./src/menu/menu_loop.c \
				./src/menu/draw_menu_cursor.c \
				./src/menu/animate_menu.c \
				\
				./src/end/end_loop.c \
				./src/end/animate_end.c \
				\
				./src/game/game_loop.c \
				./src/game/draw_parralax.c \
				./src/game/draw_player.c \
				./src/game/draw_background.c \
				./src/game/draw_all_game.c \
				./src/game/animate_slime.c \
				./src/game/animate_mushroom.c \
				./src/game/handle_gravity.c \
				./src/game/draw_score.c \
				./src/game/map_setter.c \
				./src/game/check_if_overlap.c \
				./src/game/set_as_lose.c \
				\
				./src/free/free_all.c \
				./src/free/destroy_background.c \
				./src/free/destroy_enemy_array.c \
				./src/free/destroy_enemy_textures.c \
				./src/free/destroy_manager.c \
				./src/free/destroy_music.c \
				./src/free/destroy_player.c \
				./src/free/destroy_menu.c \
				./src/free/destroy_end.c \
				\
				./src/split.c \
				./src/fake_waiter.c

EXEC 	 	=	my_runner

all:  build_lib build ## Calls build_lib and build

build_lib: ## Builds the lib
	make -C ./lib/my

build: ## build the project
	$(CC) $(MAIN) $(SRC) $(CSFML_LIB) $(CFLAGS) $(LFLAGS) -o $(EXEC)

lazy: ## build the project without Error
	$(CC) $(MAIN) $(SRC) $(CSFML_LIB) $(LAZYCFLAGS) $(LFLAGS) -o $(EXEC)

run: build
	./$(EXEC) map/map1.txt

rerun: re run

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
