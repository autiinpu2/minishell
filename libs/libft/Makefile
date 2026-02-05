CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g -MMD -MP
LIBC    := ar rcs
RM      := rm -rf

NAME    := libft.a
OBJ_DIR := ../build

SRC     := ft_atoi.c ft_bzero.c ft_calloc.c ft_dprintf.c \
           ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
           ft_isprint.c ft_isspace.c ft_itoa.c ft_memchr.c \
           ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
           ft_putchar_fd.c ft_putnbr.c ft_putnbr_fd.c \
           ft_putstr_fd.c ft_split.c ft_strchr.c ft_strcmp.c \
           ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
           ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
           ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
           ft_strtol.c ft_strtoll.c \
           get_next_line/get_next_line.c \
           get_next_line/get_next_line_utils.c

OBJS    := $(SRC:%.c=$(OBJ_DIR)/%.o)
DEPS    := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)
	@echo "\033[1;32m$(NAME) created.\033[0m"

# The rule to compile .o files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "\033[1;32mObjects and dependencies cleaned.\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;32m$(NAME) deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re
