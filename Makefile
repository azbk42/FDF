NAME = fdf

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm

LIBFT = ./Libft/libft.a
SRC_DIR = ./src
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)
	@printf "\e[32mFDF OK\e[0m\n"
	
$(NAME): $(OBJ)
	@$(MAKE) -C ./Libft 1>/dev/null 
	@$(MAKE) -C ./minilibx-linux 1>/dev/null 
	@$(CC) $(CFLAGS) -lm $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ 


bonus: fclean
	@$(MAKE) all CFLAGS="$(CFLAGS) -D COULEUR=1" 1>/dev/null
	@printf "\e[32mBONUS FDF OK\e[0m\n"

norminette:
	norminette $(SRC_DIR)
	norminette ./includes/

clean:
	@$(MAKE) -C ./Libft clean 1>/dev/null
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C ./Libft fclean 1>/dev/null
	@rm -f $(NAME)
	@echo "All executable files and object files have been removed. (fclean)"

re: fclean all