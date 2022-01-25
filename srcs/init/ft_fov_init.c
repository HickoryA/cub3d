

#include "../../includes/ft_cub3d.h"

void		ft_fov_init(t_cub3d *game)
{
	if (game->dir_player == 'N')
	{
		game->dirx = 0.0;
		game->diry = -1.0;
		game->planex = 0.5;
		game->planey = 0.0;
	}
	if (game->dir_player == 'S')
	{
		game->dirx = 0.0;
		game->diry = 1.0;
		game->planex = -0.5;
		game->planey = 0.0;
	}
	ft_fov_init_next(game);
	game->posx += 0.5;
	game->posy += 0.5;
	game->map_startx = game->posx;
	game->map_starty = game->posy;
}

void		ft_fov_init_next(t_cub3d *game)
{
	if (game->dir_player == 'E')
	{
		game->dirx = 1.0;
		game->diry = 0.0;
		game->planex = 0.0;
		game->planey = 0.5;
	}
	if (game->dir_player == 'W')
	{
		game->dirx = -1.0;
		game->diry = 0.0;
		game->planex = 0.0;
		game->planey = -0.5;
	}
}
