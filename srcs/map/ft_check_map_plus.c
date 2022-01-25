

#include "../../includes/ft_cub3d.h"

void		ft_closed(t_cub3d *game, int i, int j)
{
	while (game->map[++i])
	{
		while (game->map[i][++j] && i != game->maplinecount)
		{
			if ((game->map[i][j] == 'N' || game->map[i][j] == 'E' ||
			game->map[i][j] == 'W' || game->map[i][j] == 'S')
			&& (ft_strlen(game->map[i - 1]) - 1 < j
			|| ft_strlen(game->map[i + 1]) - 1 < j))
			{
				ft_putstr_fd("Error\nInvalid map or in contact with void.", 1);
				ft_exit(game, 0);
			}
			if ((game->map[i][j] == 'N' || game->map[i][j] == 'E' ||
			game->map[i][j] == 'W' || game->map[i][j] == 'S')
			&& (game->map[i - 1][j] == ' '
			|| game->map[i + 1][j] == ' '))
			{
				ft_putstr_fd("Error\nInvalid map or in contact with space.", 1);
				ft_exit(game, 0);
			}
		}
		j = -1;
	}
}

void		ft_is_out_of_map(t_cub3d *game, int i, int j)
{
	if (game->map[i][j] == 'N' || game->map[i][j] == 'E' ||
		game->map[i][j] == 'W' || game->map[i][j] == 'S'
		|| game->map[i][j] == '2')
	{
		if (game->z != 0 && game->map[i][j + 1] != '1'
		&& game->map[i][j - 1] != '1')
		{
			ft_putstr_fd("Error\nMap error : 0, 2, N, S, E, or W is out", 1);
			ft_putstr_fd(" of the map.\nor new line or space in the map.\n", 1);
			ft_exit(game, 0);
		}
		if (!(game->map[i + 1]))
		{
			ft_putstr_fd("Error\nNew line in the map or something out.", 1);
			ft_exit(game, 0);
		}
		if (game->map[i][j - 1] == '1'
		&& game->map[i][j + 1] == ' ')
		{
			ft_putstr_fd("Error map,\nbad char in out or out of the map\n", 1);
			ft_exit(game, 0);
		}
	}
}

void		ft_check_in_map_space(t_cub3d *game, int i, int j)
{
	if (game->map[i][j] == ' ' && (j - 1) == -1 && ((j + 1) <=
		ft_strlen(game->map[i]) && ((game->map[i][j + 1] == ' ') ||
		(game->map[i][j + 1] == '1'))))
		game->map[i][j] = '1';
	else if (game->map[i][j] == ' ' && ((j - 1) >= 0 &&
		((game->map[i][j - 1] == ' ') || ((game->map[i][j - 1] == '1')))) &&
		((j + 1) <= ft_strlen(game->map[i]) &&
		((game->map[i][j + 1] == ' ') || (game->map[i][j + 1] == '1'))))
	{
		if (((i - 1) >= 0 && game->map[i - 1] && ft_strlen(game->map[i
			- 1]) >= j && game->map[i - 1][j] == '0') || ((j - 1) >= 0 &&
			game->map[i][j - 1] == '0') || ((j + 1) <= ft_strlen(game->map[i])
			&& game->map[i][j + 1] == '0') || (game->map[i + 1] &&
			ft_strlen(game->map[i + 1]) >= j && game->map[i + 1][j] == '0'))
		{
			ft_putstr_fd("Error\nA space and a '0' can't be in contact.", 1);
			ft_exit(game, 0);
		}
		game->map[i][j] = '1';
	}
}
