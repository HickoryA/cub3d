

#include "../../includes/ft_cub3d.h"

void		ft_move_f_b(t_cub3d *game)
{
	if (game->press_w == 1)
	{
		game->posy += game->diry * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posy -= game->diry * game->movespeed;
		game->posx += game->dirx * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posx -= game->dirx * game->movespeed;
	}
	if (game->press_s == 1)
	{
		game->posy -= game->diry * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posy += game->diry * game->movespeed;
		game->posx -= game->dirx * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posx += game->dirx * game->movespeed;
	}
}

void		ft_move_r_l(t_cub3d *game)
{
	if (game->press_a == 1)
	{
		game->posy -= game->planey * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posy += game->planey * game->movespeed;
		game->posx -= game->planex * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posx += game->planex * game->movespeed;
	}
	if (game->press_d == 1)
	{
		game->posy += game->planey * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posy -= game->planey * game->movespeed;
		game->posx += game->planex * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posx -= game->planex * game->movespeed;
	}
}

void		ft_see_r(t_cub3d *game)
{
	if (game->right_arrow == 1)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(game->rotspeed) - game->diry
			* sin(game->rotspeed);
		game->diry = game->olddirx * sin(game->rotspeed) +
			game->diry * cos(game->rotspeed);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(game->rotspeed) -
			game->planey * sin(game->rotspeed);
		game->planey = game->oldplanex * sin(game->rotspeed) +
			game->planey * cos(game->rotspeed);
	}
}

void		ft_see_l(t_cub3d *game)
{
	if (game->left_arrow == 1)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(-game->rotspeed) -
			game->diry * sin(-game->rotspeed);
		game->diry = game->olddirx * sin(-game->rotspeed) +
			game->diry * cos(-game->rotspeed);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(-game->rotspeed) -
			game->planey * sin(-game->rotspeed);
		game->planey = game->oldplanex * sin(-game->rotspeed) +
			game->planey * cos(-game->rotspeed);
	}
}

int			ft_key_move(t_cub3d *game)
{
	game->movespeed = 0.018;
	game->rotspeed = 0.012;
	ft_move_f_b(game);
	ft_move_r_l(game);
	ft_see_r(game);
	ft_see_l(game);
	ft_raycasting(game);
	return (1);
}
