cc =  cc

FLAGS = -g3 -Wall -Wextra -Werror

MLX_FLAGS = -ldl -lglfw -pthread -lm

INCLUDES = -I ./includes/
OBJ_DIR = obj/
SRC_DIR = src/

NAME = cub3D

src += main.c init.c utils.c parser.c

src += $(addprefix validate/,	valid.c \
								valid_utils.c \
								valid_map.c \
								valid_info.c \
								utils_valid.c)

src += $(addprefix draw_map/,	define_vectors.c \
								)

src += $(addprefix mlx_manager/,	running.c \
									math.c \
									utils.c \
									keys.c \
									key_strafe.c \
									key_utils.c)

src += $(addprefix memory/,	memory_manager.c)

SRC_OBJ = $(addprefix $(OBJ_DIR), $(src:.c=.o))

all: build_mlx libft $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(cc) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(SRC_OBJ)
	@$(cc) $(FLAGS) $(INCLUDES) $(SRC_OBJ) -o $(NAME) ./includes/libft/libft.a ./includes/MLX42/build/libmlx42.a $(MLX_FLAGS)

build_mlx:
ifeq (,$(wildcard ./includes/MLX42/build/libmlx42.a))
	@cd includes && \
	git clone https://github.com/codam-coding-college/MLX42.git && \
	cd MLX42 && \
	sed -i 's/cmake_minimum_required (VERSION 3.18.0)/cmake_minimum_required (VERSION 3.16.0)/g' CMakeLists.txt && \
	if ! cmake -B build; then \
		echo "Failed to configure MLX42"; \
	else \
		cmake --build build -j4; \
	fi
endif

valgrind: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=mlx.sup ./cub3D maps/elevator.cub

delete_mlx:
	@rm -rf includes/MLX42

libft: 
	@make -C ./includes/libft

gdb: all
	@gdb ./cub3D

clean:
	@rm -rf $(OBJ_DIR)
	@make -C ./includes/libft clean

fclean: clean
	@rm -f $(NAME)
	@rm -f ./includes/libft/libft.a
	@rm -rf ./includes/MLX42

re: fclean
	@sleep 0.1
	@make all

.PHONY: all clean fclean re libft build_mlx delete_mlx 