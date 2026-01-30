CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -g -I includes
RM				:= rm -rf
MAKE			:= make --no-print-directory

NAME			:= minishell
OBJ_DIR			:= build

LIBFT_DIR		:= libft
LIBFT   		:= $(LIBFT_DIR)/libft.a

SRC_DIR 		:= src
SRC				:= envp_utils.c main.c init_parsing.c free_utils.c \
					execution/close_fds.c execution/exec.c \
					execution/pids.c execution/run.c \
					built_in/exit.c built_in/env.c built_in/launch.c \
					parse.c

OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -lreadline -o $(NAME)
	@echo "\033[1;32m$(NAME) created.\033[0m"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
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