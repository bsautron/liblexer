NAME = utest
DEPENDENCIES = libft \
								liblist
SOURCES_PROG = init_lexer.c \
	  create_group_syntax.c \
	  create_syntax.c \
	  insert_group_syntax.c \
	  find_group_syntax.c \
	  find_syntax.c \
	  add_syntax.c \
	  show_config.c \
	  get_next_token.c \
	  get_token.c \

SOURCES_TEST = test/test1.c \
								test/test2.c \
								test/test3.c \

SOURCES = $(SOURCES_PROG) $(SOURCES_TEST)

SOURCES_FOLDER = ..

CC = gcc
CFLAGS = -Wextra -Wall -Werror
TEST_FORDER = test
INCLUDES_FOLDER = ../includes
OBJECTS_FOLDER = .objects
MAIN = main.c
MAIN_OBJECT = $(OBJECTS_FOLDER)/$(MAIN:.c=.o)
INCLUDES = liblexer.h

SOURCES_DEPENDENCIES = $(foreach dep, $(DEPENDENCIES), ../libraries/$(dep)/$(dep).a)
INCLUDES_LIBRARIES = $(foreach dep,$(DEPENDENCIES),-I ../libraries/$(dep)/includes)
HEADERS_LIBRARIES = $(foreach dep,$(DEPENDENCIES),../libraries/$(dep)/includes/$(dep).h)
MAKE_LIBRARIES = $(foreach dep,$(DEPENDENCIES),make -C ../libraries/$(dep);)
REBUILD_LIBRARIES = $(foreach dep,$(DEPENDENCIES),make re -C ../libraries/$(dep);)

OBJECTS = $(SOURCES:%.c=%.o)

all: init makelib $(NAME)

rebuild: fclean init rebuildlib $(NAME)

makelib:
	$(MAKE_LIBRARIES)

rebuildlib:
	$(REBUILD_LIBRARIES)

init:
	mkdir -p $(OBJECTS_FOLDER)/test

$(NAME): $(MAIN_OBJECT) $(addprefix $(OBJECTS_FOLDER)/, $(OBJECTS))
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJECT) $(addprefix $(OBJECTS_FOLDER)/, $(OBJECTS)) $(SOURCES_DEPENDENCIES)

$(MAIN_OBJECT): $(MAIN)
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -o $(MAIN_OBJECT) -c $(MAIN) $(INCLUDES_LIBRARIES)

$(addprefix $(OBJECTS_FOLDER)/, %.o): $(SOURCES_FOLDER)/%.c $(addprefix $(INCLUDES_FOLDER)/, $(INCLUDES)) $(HEADERS_LIBRARIES)
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -o $@ -c $< $(INCLUDES_LIBRARIES)

clean:
	rm -f $(addprefix $(OBJECTS_FOLDER)/, $(OBJECTS))
	rm -f $(MAIN_OBJECT)
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all
