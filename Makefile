cc =  cc

FLAGS = -Wall -Wextra -Werror -g3

# MLX_FLAGS

INCLUDES = -I ./includes/
OBJ_DIR = obj/
SRC_DIR = src/

NAME = cub3d

src += main.c init.c utils.c valid.c

SRC_OBJ = $(addprefix $(OBJ_DIR), $(src:.c=.o))

all: libft $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(cc) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(SRC_OBJ)
	@$(cc) $(FLAGS) $(INCLUDES) $(SRC_OBJ) -o $(NAME) ./includes/libft/libft.a

libft: 
	@make -C ./includes/libft

clean:
	@rm -rf $(OBJ_DIR)
	@make -C ./includes/libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./includes/libft fclean

re: fclean all

.PHONY: all clean fclean re libft