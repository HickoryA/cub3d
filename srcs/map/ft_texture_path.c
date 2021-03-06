

#include "../../includes/ft_cub3d.h"

void		ft_texture_path_sp(t_cub3d *game, char *line, int i)
{
	if (game->verif_sp == 0)
	{
		while (line[i] != '\0' && game->verif_sp >= 0)
		{
			if (line[i] == 'S' && line[i + 1] == ' ')
			{
				game->verif_sp++;
				i++;
			}
			if (game->verif_sp >= 1)
				if ((line[i] != '.' && line[i] != 32) || game->verif_sp > 1)
				{
					ft_putstr_fd("Err\nMultiple arg S | bad texture path\n", 1);
					ft_exit(game, 0);
				}
			if (line[i] == '.' && game->verif_sp == 1)
			{
				if (!(game->sprite = ft_strdup_texture(ft_strchr(line, '.'))))
					ft_exit(game, 1);
				game->verif_sp = -1;
			}
			i++;
		}
	}
}

void		ft_texture_path_ea(t_cub3d *game, char *line, int i)
{
	if (game->verif_ea == 0)
	{
		while (line[i] != '\0' && game->verif_ea >= 0)
		{
			if (line[i] == 'E' && line[i + 1] == 'A')
			{
				game->verif_ea++;
				i += 2;
			}
			if (game->verif_ea >= 1)
				if ((line[i] != '.' && line[i] != 32) || game->verif_ea > 1)
				{
					ft_putstr_fd("Er\nMultiple arg EA | bad texture path\n", 1);
					ft_exit(game, 0);
				}
			if (line[i] == '.' && game->verif_ea == 1)
			{
				if (!(game->west = ft_strdup_texture(ft_strchr(line, '.'))))
					ft_exit(game, 1);
				game->verif_ea = -1;
			}
			i++;
		}
	}
	ft_texture_path_sp(game, line, 0);
}

void		ft_texture_path_we(t_cub3d *game, char *line, int i)
{
	if (game->verif_we == 0)
	{
		while (line[i] != '\0' && game->verif_we >= 0)
		{
			if (line[i] == 'W' && line[i + 1] == 'E')
			{
				game->verif_we++;
				i += 2;
			}
			if (game->verif_we >= 1)
				if ((line[i] != '.' && line[i] != 32) || game->verif_we > 1)
				{
					ft_putstr_fd("Er\nMultiple arg WE | bad texture path\n", 1);
					ft_exit(game, 0);
				}
			if (line[i] == '.' && game->verif_we == 1)
			{
				if (!(game->east = ft_strdup_texture(ft_strchr(line, '.'))))
					ft_exit(game, 1);
				game->verif_we = -1;
			}
			i++;
		}
	}
	ft_texture_path_ea(game, line, 0);
}

void		ft_texture_path_no(t_cub3d *game, char *line, int i)
{
	if (game->verif_no == 0)
	{
		while (line[i] != '\0' && game->verif_no >= 0)
		{
			if (line[i] == 'N' && line[i + 1] == 'O')
			{
				game->verif_no++;
				i += 2;
			}
			if (game->verif_no >= 1)
				if ((line[i] != '.' && line[i] != 32) || game->verif_no > 1)
				{
					ft_putstr_fd("Er\nMultiple arg NO | bad texture path\n", 1);
					ft_exit(game, 0);
				}
			if (line[i] == '.' && game->verif_no == 1)
			{
				if (!(game->south = ft_strdup_texture(ft_strchr(line, '.'))))
					ft_exit(game, 1);
				game->verif_no = -1;
			}
			i++;
		}
	}
	ft_texture_path_so(game, line, 0);
}

void		ft_texture_path_so(t_cub3d *game, char *line, int i)
{
	if (game->verif_so == 0)
	{
		while (line[i] != '\0' && game->verif_so >= 0)
		{
			if (line[i] == 'S' && line[i + 1] == 'O')
			{
				game->verif_so++;
				i += 2;
			}
			if (game->verif_so >= 1)
				if ((line[i] != '.' && line[i] != 32) || game->verif_so > 1)
				{
					ft_putstr_fd("Er\nMultiple arg SO | bad texture path\n", 1);
					ft_exit(game, 0);
				}
			if (line[i] == '.' && game->verif_so == 1)
			{
				if (!(game->north = ft_strdup_texture(ft_strchr(line, '.'))))
					ft_exit(game, 1);
				game->verif_so = -1;
			}
			i++;
		}
	}
	ft_texture_path_we(game, line, 0);
}
