CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -g -I includes
RM				:= rm -rf
MAKE			:= make --no-print-directory

NAME			:= minishell
OBJ_DIR			:= build

LIBFT_DIR		:= libs/libft
LIBFT   		:= $(LIBFT_DIR)/libft.a

SRC_DIR 		:= src
SRC				:= main.c

UTILS_DIR		:= $(SRC_DIR)/utils
UTILS_SRC		:= envp_utils.c free_utils.c

PARSE_DIR		:= $(SRC_DIR)/parse
PARSE_SRC		:= 

EXEC_DIR		:= $(SRC_DIR)/exec
EXEC_SRC		:= 

OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJS	+= $(addprefix $(UTILS_DIR)/, $(UTILS_SRC:.c=.o))
OBJS	+= $(addprefix $(PARSE_DIR)/, $(PARSE_SRC:.c=.o))
OBJS	+= $(addprefix $(EXEC_DIR)/, $(EXEC_SRC:.c=.o))

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
