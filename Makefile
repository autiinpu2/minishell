NAME        := minishell
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g -I includes -D_XOPEN_SOURCE=700
RM          := rm -rf
MAKE        := make --no-print-directory

OBJ_DIR     := build
SRC_DIR     := src
LIBFT_DIR   := libs/libft
LIBFT       := $(LIBFT_DIR)/libft.a

SRC_MAIN_DIR    := $(SRC_DIR)
SRC_MAIN        := main.c

SRC_UTILS_DIR   := $(SRC_DIR)/utils
SRC_UTILS       := envp_utils.c free_utils.c builtin_utils.c free_protected.c fds_utils.c history.c signals.c envp_info.c

SRC_PARSE_DIR   := $(SRC_DIR)/parse
SRC_PARSE       := init_parsing.c parse.c path.c error.c ft_split_quotes.c expand.c expand_utils.c 

SRC_EXEC_DIR    := $(SRC_DIR)/exec
SRC_EXEC        := exec.c builtin.c ft_cd.c ft_unset.c ft_export.c forks.c ft_echo.c

SRCS        := $(addprefix $(SRC_MAIN_DIR)/, $(SRC_MAIN)) \
               $(addprefix $(SRC_UTILS_DIR)/, $(SRC_UTILS)) \
               $(addprefix $(SRC_PARSE_DIR)/, $(SRC_PARSE)) \
               $(addprefix $(SRC_EXEC_DIR)/, $(SRC_EXEC))

OBJS        := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -lreadline -o $(NAME)
	@echo "\033[1;32m$(NAME) created.\033[0m"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

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