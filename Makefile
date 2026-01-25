CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g
RM      := rm -rf
MAKE    := make --no-print-directory

NAME    := minishell
OBJ_DIR := build

LIBFT_DIR := libft
LIBFT   := $(LIBFT_DIR)/libft.a

SRC_DIR := src
SRC     := test.c

OBJS    := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "\033[1;32m$(NAME) created.\033[0m"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[1;32mObjects cleaned.\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[1;32mEverything cleaned.\033[0m"

re: fclean all

.PHONY: all clean fclean re