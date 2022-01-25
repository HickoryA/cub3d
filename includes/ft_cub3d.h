

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# include <stdio.h>
# include <math.h>
# include "struct.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

void				ft_map(t_cub3d *game, int ret, char *line);
int					ft_check_map(t_cub3d *game, char *line);
int					ft_check_is_map_line(t_cub3d *game, char *line);
void				ft_check_map_error(t_cub3d *game, int i, int j);
int					ft_key_input(int key, t_cub3d *game);
void				ft_check_map_arg(t_cub3d *game, char *line, int i);
void				ft_colors(t_cub3d *game, char *line, int i, int j);
void				ft_texture_path_no(t_cub3d *game, char *line, int i);
void				ft_alloc_sprite_order(t_cub3d *game);
void				ft_fov_init_next(t_cub3d *game);
void				ft_check_in_map_space(t_cub3d *game, int i, int j);
void				ft_count_map_args(t_cub3d *game, char *line, int i);
char				*ft_strdup_texture(char *s1);
int					ft_ismap(t_cub3d *game, int i, int n, int o);
void				ft_is_enough_arg(t_cub3d *game);
void				ft_parser_r(t_cub3d *game, char *line, int i);
int					ft_isemptyline(char *line);
size_t				ft_size_t_len(size_t nbr);
void				ft_raycasting(t_cub3d *game);
int					ft_key_move(t_cub3d *game);
int					ft_key_release(int key, t_cub3d *game);
int					ft_exit(t_cub3d *game, int x);
void				ft_texture(t_cub3d *game);
void				ft_draw_floor_ceiling(t_cub3d *game);
void				ft_draw(t_cub3d *game);
void				ft_draw_sprite(t_cub3d *game, int i);
void				ft_calculate_sprite(t_cub3d *game, int x);
void				ft_save_bitmap(char *filename, t_cub3d *game);
void				ft_init_game_struct(t_cub3d *game);
void				ft_fov_init(t_cub3d *game);
void				ft_texture_init(t_cub3d *game);
void				ft_exit_texture(t_cub3d *game);
void				ft_is_out_of_map(t_cub3d *game, int i, int j);
void				ft_check_map_closed_left(t_cub3d *game, int i, int j,
					char c);
void				ft_check_map_closed_right(t_cub3d *game, int i, int j,
					char c);
void				ft_check_0_out(t_cub3d *game, int i, int j);
void				ft_texture_path_so(t_cub3d *game, char *line, int i);
void				ft_closed(t_cub3d *game, int i, int j);
void				ft_read_map_next_2(t_cub3d *game, char **line);
void				ft_raycasting_next(t_cub3d *game);
void				ft_read_map_next(t_cub3d *game, char **line);
void				ft_calculate_sprite_next(t_cub3d *game);
void				ft_check_line(t_cub3d *game, int i, int j);
void				ft_draw_sprite_next(t_cub3d *game);
void				check_map_qwerty_error(t_cub3d *game);

#endif
