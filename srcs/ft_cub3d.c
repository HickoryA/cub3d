

#include "../includes/ft_cub3d.h"

void		ft_check_screen_size(t_cub3d *game)
{
	if (game->width_check < game->width)
	{
		game->width = game->width_check;
		ft_putstr_fd("Error :\nmap width resized because ", 1);
		ft_putstr_fd("width is superior than the limit screen\n", 1);
	}
	if (game->width < 250)
	{
		game->width = 250;
		ft_putstr_fd("Error :\nmap width resized to 250 because ", 1);
		ft_putstr_fd("too small width\n", 1);
	}
	if (game->height_check < game->height)
	{
		game->height = game->height_check;
		ft_putstr_fd("Error :\nmap height resized because ", 1);
		ft_putstr_fd("height is superior than the limit screen\n", 1);
	}
	if (game->height < 150)
	{
		game->height = 150;
		ft_putstr_fd("Error :\nmap height resized to 150 because ", 1);
		ft_putstr_fd("too small height\n", 1);
	}
}

void		ft_del_last_line(t_cub3d *game, int i)
{
	if (game->verif_f != 1 || game->verif_c != 1)
	{
		ft_putstr_fd("Error\nToo many  or missing argument F or C\n", 1);
		ft_exit(game, 0);
	}
	while (game->tmp_map[i] != '1')
	{
		if (game->tmp_map[i] == '\n' && game->tmp_map[i - 1] == '\n')
		{
			game->tmp_map[i - 1] = ' ';
			game->maplinecount--;
		}
		i--;
	}
}

void		ft_check_map_extension(t_cub3d *game)
{
	size_t	i;
	int		j;
	char	*check;

	check = ".cub";
	i = ft_strlen(game->map_path);
	j = 4;
	while (j != 0)
	{
		if (check[j] != game->map_path[i])
		{
			ft_putstr_fd("Error\nMap extension need to be '.cub'\n", 1);
			ft_exit(game, 0);
		}
		i--;
		j--;
	}
}

void		ft_check_args(t_cub3d *game, int ac, char **av)
{
	game->map_path = av[1];
	if (ac > 3)
	{
		ft_putstr_fd("Error\nToo much arguments\n", 1);
		ft_exit(game, 0);
	}
	if (ac < 2)
	{
		ft_putstr_fd("Error\nToo few arguments (you need a map !)\n", 1);
		ft_exit(game, 0);
	}
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 6) == 0 && ft_strlen(av[2]) == 6)
			game->screenshot = 1;
		else
		{
			ft_putstr_fd("Error\nBad argument, only '--save' allowed", 1);
			ft_putstr_fd("after the map path or bad map path (.cub needed)", 1);
			ft_exit(game, 0);
		}
	}
	ft_check_map_extension(game);
}

int			main(int ac, char **av)
{
	t_cub3d		game[1];

	ft_init_game_struct(game);
	ft_check_args(game, ac, av);
	ft_map(game, 0, NULL);
	ft_fov_init(game);
	if (!(game->mlx_ptr = mlx_init()))
		ft_exit(game, 1);
	mlx_get_screen_size(game->mlx_ptr, &game->width_check,
		&game->height_check);
	ft_check_screen_size(game);
	if (game->screenshot == 0)
		if (!(game->win_ptr = mlx_new_window(game->mlx_ptr, game->width,
			game->height, "Cub3D")))
			ft_exit(game, 1);
	game->tracked = 1;
	ft_texture_init(game);
	game->tracked = 8;
	if (!(game->no_ghost_sprite = malloc(sizeof(double) * game->width)))
		ft_exit(game, 1);
	ft_raycasting(game);
	mlx_loop_hook(game->mlx_ptr, ft_key_move, (void *)game);
	mlx_loop(game->mlx_ptr);
	ft_exit(game, 0);
	return (0);
}
