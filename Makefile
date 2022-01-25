

SRCS =	srcs/ft_cub3d.c\
		srcs/utils/ft_screenshot.c\
		srcs/utils/ft_exit.c\
		srcs/utils/ft_utils.c\
		srcs/utils/ft_utils_plus.c\
		srcs/init/ft_init.c\
		srcs/init/ft_fov_init.c\
		srcs/map/ft_map.c\
		srcs/map/ft_check_map.c\
		srcs/map/ft_check_map_plus.c\
		srcs/map/ft_check_map_arg.c\
		srcs/map/ft_texture_path.c\
		srcs/map/ft_colors.c\
		srcs/raycast/ft_raycasting.c\
		srcs/raycast/ft_key_input.c\
		srcs/raycast/ft_texture.c\
		srcs/raycast/ft_draw.c\
		srcs/raycast/ft_sprite.c\
		srcs/raycast/ft_move_see.c


LIBFT_PATH =	./libft
MLX_PATH =		./minilibx-linux
LIBS = 			./libft/libft.a ./minilibx-linux/libmlx.a
HEADER =		./includes/ft_cub3d.h

OBJS =		$(SRCS:.c=.o)
NAME =		cub3D

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror -g
FLAGS =		-lX11 -lXext -lm
RM =		rm -f

all:		${NAME}

$(OBJS):	$(HEADER)

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIBFT_PATH) all
			$(MAKE) -C $(MLX_PATH) all
			$(CC) $(CFLAGS) -o ${NAME} $(OBJS) ${LIBS} $(FLAGS)

clean:		
			$(MAKE) -C $(LIBFT_PATH) clean
			$(MAKE) -C $(MLX_PATH) clean
			$(RM) $(OBJS) ./screenshot.bmp

fclean:	clean
			$(MAKE) -C $(LIBFT_PATH) fclean
			$(RM) ${NAME}

re:		fclean all



save:	all
			./$(NAME) ./maps/map.cub --save

norm:
			norminette libft/*.c libft/*.h srcs/ includes/*.h

.PHONY:	all clean fclean re save norm
