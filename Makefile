NAME := libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror 

SRCS := ft_printf.c ft_printf_utils.c itoa_base.c printer_utils1.c ptr_printers.c tokenizer.c ft_printf.h int_printers.c parser.c printer_utils2.c

SRCS_LIBFT := libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstclear_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstlast_bonus.c libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstsize_bonus.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/is_in.c

INCS := ft_printf.h

OBJ_DIR := .bin/
OBJS := $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
OBJS_LIBFT := $(patsubst libft/%.c, $(OBJ_DIR)%.o, $(SRCS_LIBFT))

###############################################################################

all: $(NAME)

bonus: all

$(NAME): $(OBJS) $(OBJS_LIBFT)
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

.PHONY: all bonus clean fclean re rfclean
