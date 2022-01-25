

#include "../../includes/ft_cub3d.h"

void		ft_parser_r(t_cub3d *game, char *line, int i)
{
	while (!ft_isdigit(line[i]) && line[i] != '\0')
		i++;
	if (line[i] != 32)
		game->width = ft_atoi(&line[i]);
	i += ft_size_t_len(game->width);
	while (!ft_isdigit(line[i]) && line[i] != '\0')
		i++;
	if (line[i] != 32 && line[i] != '\0')
		game->height = ft_atoi(&line[i]);
	i += ft_size_t_len(game->height);
	while (line[i])
	{
		if (line[i] != ' ')
			game->height = -1;
		i++;
	}
	if (game->width == -1 || game->height == -1 ||
	game->width > __INT_MAX__ || game->height > __INT_MAX__)
	{
		ft_putstr_fd("Error\nEmpty or bad resolution on arg R", 1);
		ft_putstr_fd(" (need to be less than int max)", 1);
		ft_exit(game, 0);
	}
}

int			ft_ismap(t_cub3d *game, int i, int n, int o)
{
	int		t;

	t = 0;
	while (game->tmp_map[i])
	{
		if (game->tmp_map[i] == '\n')
			n++;
		if (game->tmp_map[i] == '1')
			o++;
		if (game->tmp_map[i] == '0')
			game->z++;
		if (game->tmp_map[i] == '\t')
			t++;
		i++;
	}
	if ((n < 2 || o < 4) && game->z == 0)
	{
		ft_putstr_fd("Error\nMissings arg or empty / new line.\n", 1);
		ft_exit(game, 0);
	}
	return (t);
}

size_t		ft_size_t_len(size_t nbr)
{
	size_t		len;

	len = 0;
	while (nbr / 10 >= 1)
	{
		nbr /= 10;
		len += 1;
	}
	len++;
	return (len);
}

char		*ft_strdup_texture(char *s1)
{
	size_t	i;
	size_t	len;
	char	*dup;

	len = 0;
	while (s1[len] && s1[len] != ' ')
		len++;
	if (!(dup = ft_calloc(sizeof(char), (len + 1))))
		return (dup);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
