

#include "../../includes/ft_cub3d.h"

void		ft_error_colors(t_cub3d *game, int i, int j)
{
	if (game->tab_color[0] == NULL || game->tab_color[1] == NULL ||
		game->tab_color[2] == NULL)
	{
		ft_putstr_fd("Error\nArgument F or C have a bad format\n", 1);
		ft_exit(game, 0);
	}
	if (!ft_iscolor(ft_atoi(game->tab_color[0]))
		|| !ft_iscolor(ft_atoi(game->tab_color[1]))
		|| !ft_iscolor(ft_atoi(game->tab_color[2])))
	{
		ft_putstr_fd("Error\nColor error, 0 to 255 by color.\n", 1);
		ft_exit(game, 0);
	}
	while (++i != 3)
	{
		j = 0;
		while (game->tab_color[i][j] != '\0' && game->tab_color[i][j] != ' ')
			j++;
		if (j > 3)
		{
			ft_putstr_fd("Error\nColor error.\n", 1);
			ft_exit(game, 0);
		}
	}
}

void		ft_init_colors(t_cub3d *game, t_color color, char *line, int x)
{
	color.argb[0] = ft_atoi(game->tab_color[2]);
	color.argb[1] = ft_atoi(game->tab_color[1]);
	color.argb[2] = ft_atoi(game->tab_color[0]);
	if (line[x] == 'F')
	{
		game->color_floor = color.color;
		game->verif_f++;
	}
	if (line[x] == 'C')
	{
		game->color_ceiling = color.color;
		game->verif_c++;
	}
}

void		ft_check_colors(t_cub3d *game, char *line, int i, int j)
{
	if (!(game->tab_color = ft_split(&line[j], ',')))
		ft_exit(game, 1);
	while (i < 3)
	{
		if (ft_isdigit(game->tab_color[i][j]))
		{
			while (ft_isdigit(game->tab_color[i][j]))
				j++;
			game->check_color++;
		}
		if (game->tab_color[i][j] == '\0')
		{
			i++;
			j = 0;
			if (game->check_color > 1)
			{
				ft_putstr_fd("Error\nArgument F or C have a bad format\n", 1);
				ft_exit(game, 0);
			}
			game->check_color = 0;
		}
		j++;
	}
}

void		ft_check_point(t_cub3d *game, char *line, int j, int x)
{
	int point;

	point = 0;
	x++;
	while (line[j] != '\0')
	{
		while (line[x] != '\0')
		{
			if (!ft_isdigit(line[x]) && line[x] != ',' && line[x] != ' ')
			{
				ft_putstr_fd("Error\nArgument F or C have a bad format.\n", 1);
				ft_exit(game, 0);
			}
			x++;
		}
		if (line[j] == ',')
			point++;
		j++;
	}
	if (point != 2)
	{
		ft_putstr_fd("Error\nArgument F or C have a bad format.\n", 1);
		ft_exit(game, 0);
	}
}

void		ft_colors(t_cub3d *game, char *line, int i, int j)
{
	t_color	color;
	int		x;

	x = 0;
	color.argb[2] = 0;
	while (line[x])
	{
		if (line[x] == 'F' || line[x] == 'C')
		{
			ft_check_point(game, line, j, x);
			ft_check_colors(game, line, 0, x + 1);
			ft_error_colors(game, i, j);
			ft_init_colors(game, color, line, x);
			j = -1;
			while (game->tab_color[++j])
				ft_memdel((void*)&game->tab_color[j]);
			ft_memdel((void *)&(game->tab_color));
		}
		x++;
	}
}
