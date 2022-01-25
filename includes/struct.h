

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_bpm
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_bpm;

typedef struct		s_bpm2
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bpm2;

typedef union
{
	int				color;
	char			argb[3];
}					t_color;

typedef struct		s_sprites
{
	double		x;
	double		y;
}					t_sprites;

typedef	struct		s_cub3d
{
	int				arg_r;
	int				arg_count;
	int				tracked;
	void			*mlx_ptr;
	void			*win_ptr;
	int				height;
	int				width;
	char			*north;
	int				hit;
	int				skip;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			olddirx;
	double			olddiry;
	double			planex;
	double			planey;
	double			oldplanex;
	double			oldplaney;
	double			camerax;
	double			raydiry;
	double			raydirx;
	int				stepy;
	int				stepx;
	int				verif_no;
	char			*south;
	int				verif_so;
	char			*east;
	int				verif_ea;
	char			*west;
	int				verif_we;
	char			*sprite;
	int				verif_sp;
	int				key;
	char			**tab_color;
	int				color_floor;
	int				color_ceiling;
	char			**map;
	char			*tmp_map;
	int				map_spawn;
	int				color;
	int				fd;
	char			*map_path;
	char			dir_player;
	int				verif_c;
	int				verif_f;
	double			sidedistx;
	double			sidedisty;
	int				mapx;
	int				mapy;
	double			deltadistx;
	double			deltadisty;
	int				side;
	double			perspwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			movespeed;
	double			rotspeed;
	int				left_arrow;
	int				right_arrow;
	int				press_a;
	int				press_d;
	int				press_s;
	int				press_w;
	int				x;
	int				bits_per_pixel;
	int				endian;
	int				size_line;
	int				tex_num;
	int				tex_x;
	int				tex_y;
	int				tex_pos;
	int				no_width;
	int				no_height;
	int				so_width;
	int				so_height;
	int				we_width;
	int				we_height;
	int				ea_width;
	int				ea_height;
	int				sp_width;
	int				sp_height;
	int				sp_w;
	int				sp_h;
	int				drawstartx;
	int				drawendx;
	int				drawstarty;
	int				drawendy;
	int				sp_screen;
	double			transx;
	double			transy;
	double			inv_det;
	double			sp_x;
	double			sp_y;
	int				sp_nbr;
	int				*sp_order;
	double			*sp_dist;
	int				calc;
	void			*img_ptr;
	void			*img_no_ptr;
	void			*img_so_ptr;
	void			*img_we_ptr;
	void			*img_ea_ptr;
	void			*sprite_ptr;
	int				*img_data;
	int				*data_no;
	int				*data_so;
	int				*data_we;
	int				*data_ea;
	int				*data_sprite;
	double			*no_ghost_sprite;
	double			wallx;
	double			texpos;
	double			step;
	int				screenshot;
	int				map_startx;
	int				map_starty;
	int				width_check;
	int				height_check;
	int				maplinecount;
	int				check_color;
	int				z;
}					t_cub3d;

#endif
