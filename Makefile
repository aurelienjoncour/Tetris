##
## EPITECH PROJECT, 2019
## makefile
## File description:
## project makefile
##

ECHO    =       /bin/echo -e
DEFAULT =       "\033[00m"

DEFAULT =       "\e[0m"
BOLD    =       "\e[1m"
DIM     =       "\e[2m"
UNDLN   =       "\e[4m"
SHINE   =       "\e[5;37m"
RODE    =       "\e[9;37m"

BLACK   =       "\e[30m"
RED     =       "\e[31m"
GREEN   =       "\e[32m"
YELLOW  =       "\e[33m"
BLUE    =       "\e[34m"
MAGEN   =       "\e[35m"
CYAN    =       "\e[36m"
WHITE   =       "\e[1;37m"

LIGHT_RED       =       "\e[91m"
LIGHT_GREEN     =       "\e[92m"
LIGHT_YELLOW    =       "\e[93m"
LIGHT_BLUE      =       "\e[94m"
LIGHT_MAGEN     =       "\e[95m"
LIGHT_CYAN      =       "\e[96m"

SRC =   src/main.c	\
		src/tetris.c

OBJ =   $(SRC:.c=.o)

NAME    =   tetris

CFLAGS  +=  -I include -Wall -Wextra
LDFLAGS +=  -L lib/my -lmy

all:    $(NAME)

$(NAME):    $(OBJ)
		@$(ECHO)
		@for MAKE_PATH in $(LIB_PATHS) ; do \
			make -C $$MAKE_PATH -s ; \
		done
		@make -s -C lib/my --no-print-directory
		@gcc -o $(NAME) $(OBJ) $(LDFLAGS) \
		&& $(ECHO) $(BOLD) $(GREEN)"► BUILD SUCCESS !"$(DEFAULT) || $(ECHO) $(BOLD) $(RED)"► BUILD FAILED"$(DEFAULT)

clean:
		@make clean -s -C lib/my --no-print-directory
		@rm -f $(OBJ)
		@mr_clean
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" CLEAN "$(DEFAULT))

fclean: clean
		@make fclean -s -C lib/my --no-print-directory
		@rm -f $(OBJ)
		@rm -f $(NAME)
		@mr_clean
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" FCLEAN "$(DEFAULT))

re: fclean all

debug: CFLAGS += -g
debug: re
	valgrind ./$(NAME)

free: CFLAGS += -g
free: re
	valgrind --leak-check=full ./$(NAME)

%.o :		%.c
		@gcc -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) $(BOLD) $< | rev | cut -d'/' -f 1 | rev

.PHONY: all clean fclean