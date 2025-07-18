# ==================== cub3D Makefile ====================
NAME		= cube3D

# Dossiers
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes
LIB_DIR		= lib
MLX_DIR		= minilibx-linux

# Libs
LIBFT		= $(LIB_DIR)/libcub.a

# Compilation
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I$(INC_DIR) -I$(LIB_DIR)/libft -I$(LIB_DIR)/ft_printf -I$(LIB_DIR)/get_next_line -I$(MLX_DIR)
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Sources / objets
SRCS		= $(shell find $(SRC_DIR) -name "*.c")
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Couleurs
GREEN		= \033[0;32m
RESET		= \033[0m

# Règles
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $@ $(MLX_FLAGS)
	@echo "$(GREEN)[OK]$(RESET) Compilation terminée."

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR) clean
	@echo "$(GREEN)[OK]$(RESET) Clean."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
