NAME := libftprintf.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror 

SRCS := $(wildcard *.c) 

INCS := libftprintf.h libft/libft.h
LIBFT := libft/libft.a

OBJ_DIR := .bin/
OBJS := $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

###############################################################################

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	ar rcs $@ $?

$(OBJ_DIR)%.o: %.c
	@ mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

print-%  : ; @echo $* = $($*)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
