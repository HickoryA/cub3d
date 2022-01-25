

#include "../../includes/ft_cub3d.h"

void	ft_read_map_next(t_cub3d *game, char **line)
{
	char *temp;

	temp = game->tmp_map;
	if (!(game->tmp_map = ft_strjoin(game->tmp_map, *line)))
		ft_exit(game, 1);
	free(temp);
	temp = game->tmp_map;
	if (!(game->tmp_map = ft_strjoin(game->tmp_map, "\n")))
		ft_exit(game, 1);
	game->maplinecount++;
	free(temp);
}

void	ft_read_map_next_2(t_cub3d *game, char **line)
{
	char *temp;

	temp = game->tmp_map;
	if (!(game->tmp_map = ft_strjoin(game->tmp_map, *line)))
		ft_exit(game, 1);
	free(temp);
	temp = game->tmp_map;
	if (!(game->tmp_map = ft_strjoin(game->tmp_map, "\n")))
		ft_exit(game, 1);
	free(temp);
}

void	check_map_qwerty_error(t_cub3d *game)
{
	ft_putstr_fd("Error\n", 1);
	ft_exit(game, 0);
}
