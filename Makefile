NAME := libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror 

SRCS := $(wildcard *.c) 
SRCS_LIBFT := $(wildcard libft/*.c) 

INCS := ft_printf.h

OBJ_DIR := .bin/
OBJS := $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
OBJS_LIBFT := $(patsubst libft/%.c, $(OBJ_DIR)%.o, $(SRCS_LIBFT))

###############################################################################

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_LIBFT) $(INCS)
	ar rcs $@ $?

$(OBJ_DIR)%.o: %.c
	@ mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: libft/%.c
	@ mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

print-%  : ; @echo $* = $($*)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

rfclean : fclean
	make -C libft rfclean
	make -C tester_printf fclean

.PHONY: all clean fclean re rfclean
