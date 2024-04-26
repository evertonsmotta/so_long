/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:45:44 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/08/30 17:39:35 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* -------------------------------------------------------------------------- */
/*                                  Libraries                                 */
/* -------------------------------------------------------------------------- */

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>

/* -------------------------------------------------------------------------- */
/*                                Paths to imagens                            */
/* -------------------------------------------------------------------------- */

# define SIZE		50

# define PATH_W		"./textures/wall.xpm"
# define PATH_P_F	"./textures/player_f.xpm"
# define PATH_P_B	"./textures/player_b.xpm"
# define PATH_P_R	"./textures/player_r.xpm"
# define PATH_P_L	"./textures/player_l.xpm"
# define PATH_C		"./textures/collectible.xpm"
# define PATH_E		"./textures/exit.xpm"
# define PATH_E_F	"./textures/exit_f.xpm"
# define PATH_E_B	"./textures/exit_b.xpm"
# define PATH_E_R	"./textures/exit_r.xpm"
# define PATH_E_L	"./textures/exit_l.xpm"
# define PATH_F		"./textures/floor.xpm"

/* -------------------------------------------------------------------------- */
/*                                    Keypress                                */
/* -------------------------------------------------------------------------- */

# define ESC		XK_Escape
# define UP			XK_Up
# define DOWN		XK_Down
# define LEFT		XK_Left
# define RIGHT		XK_Right
# define W			XK_w
# define S			XK_s
# define A			XK_a
# define D			XK_d

/* -------------------------------------------------------------------------- */
/*                                   Structures                               */
/* -------------------------------------------------------------------------- */

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_map
{
	int				fd;
	char			**map;
	unsigned int	n_col;
	unsigned int	n_rows;
	unsigned int	n_collectibles;
	unsigned int	n_exits;
	unsigned int	n_players;
}				t_map;

typedef struct s_player
{
	int		p_c;
	int		p_r;
	int		n_moves;
	int		collectibles;
}				t_plr;

typedef struct s_spr
{
	void	*w_img;
	void	*p_f_img;
	void	*p_b_img;
	void	*p_r_img;
	void	*p_l_img;
	void	*c_img;
	void	*e_img;
	void	*e_f_img;
	void	*e_b_img;
	void	*e_r_img;
	void	*e_l_img;
	void	*f_img;
	int		width;
	int		height;
}				t_txtur;

typedef struct s_data
{
	t_mlx			mlx;
	t_map			map;
	t_txtur			textures;
	t_plr			player;
	unsigned int	i;
	unsigned int	j;
}				t_data;

/* -------------------------------------------------------------------------- */
/*                                   Functions                                */
/* -------------------------------------------------------------------------- */

void	ft_check_args(int ac, char **av, t_data *data);
void	ft_check_argv(int ac, char **av, t_data *data);
void	ft_map_init(t_data *data, char *map_file);
void	ft_game_init(t_data *data);
void	ft_check_len_line(int fd, t_data *data);
int		ft_count_rows(int fd, t_data *data);
int		ft_count_col(int fd, t_data *data);
char	**ft_create_map(t_data *data, char *map_file);
void	ft_error(char *str, t_data *data);
int		ft_close_window(t_data *data);
void	ft_destroy_display(t_data *data);
void	ft_destroy_textures(t_data *data);
void	ft_destroy_map(char **map);
void	ft_map_check(t_data *data);
int		ft_is_valid_map(t_data *data);
int		ft_check_chr(t_data *data);
int		ft_check_around(t_data *data);
int		ft_is_valid_format(t_data *data);
void	ft_put_image_to_window(t_data *data);
void	ft_xpm_file_to_image(t_data *data);
int		ft_keypress(int keysym_num, t_data *d);
int		ft_move(t_data *d, int x, int y, int keysym_num);
void	ft_move_sides(t_data *d, int x, int y, int keysym_num);
void	ft_move_in_exit(t_data *d, int x, int y, int keysym_num);
int		ft_flood_fill(t_data *data, char **map, int x, int y);
void	ft_free_copy(char **map);

#endif