CC		=	cc
FLAGS	=	 -Wall -Wextra -Werror -fsanitize=address
MLXF	=	-framework Cocoa -framework OpenGL -framework IOKit
SRC		=	mandatorypart/cub3D.c libft/libft.a \
			check_map_is_valid/check_file_is_valid.c \
			check_map_is_valid/check_map_utils.c check_map_is_valid/check_map.c \
			check_map_is_valid/get_map.c check_map_is_valid/check_path_is_valid.c \
			check_map_is_valid/check_map_not_first.c \
			check_map_is_valid/check_floor_and_ciel.c setup_textures.c \
			utils.c txtr.c raycast.c raycast_utils.c drawline.c \
			utils2.c utils3.c draw_map.c

BONUS	=	bonuspart/cub3D_bonus.c libft/libft.a \
			check_map_is_valid/check_file_is_valid.c \
			check_map_is_valid/check_map_utils.c check_map_is_valid/check_map.c \
			check_map_is_valid/get_map.c check_map_is_valid/check_path_is_valid.c \
			check_map_is_valid/check_map_not_first.c \
			check_map_is_valid/check_floor_and_ciel.c setup_textures.c \
			utils.c draw_map.c txtr.c raycast.c raycast_utils.c drawline.c \
			utils2.c utils3.c
LIBFT	=	libft
GLW		=	"/Users/bmengouc/.brew/opt/glfw/lib/"
MLX_PATH = ""
NAME	=	cub3D
NAME_B	=	cub3D_bonus
RM		=	rm -rf
FCLN 	=	make fclean -C
CLN		=	make clean -C

.PHONY:	all clean fclean re

all:
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(SRC) $(MLXF) libft/libft.a ./MLX42/build/libmlx42.a -o $(NAME) -Iinclude -lglfw -L$(GLW)
	@echo "Compilation > Done ! mandatory compiled succefully"

bonus:
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(BONUS) $(MLXF)  libft/libft.a ./MLX42/build/libmlx42.a -o $(NAME_B)  -Iinclude -lglfw -L$(GLW)
	@echo "Compilation > Done ! bonus compiled succefully"

clean:
	@$(CLN) $(LIBFT)

fclean: clean
	@$(RM) $(NAME) $(NAME_B)
	@$(FCLN) $(LIBFT)
	@echo "Cleaning!"

re: fclean all