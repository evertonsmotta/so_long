/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:09:44 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/08/30 17:34:01 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_in_exit(t_data *d, int x, int y, int keysym_num)
{
	if (keysym_num == UP || keysym_num == W)
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
			d->textures.e_b_img, y * SIZE, x * SIZE);
	else if (keysym_num == DOWN || keysym_num == S)
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
			d->textures.e_f_img, y * SIZE, x * SIZE);
	else if (keysym_num == RIGHT || keysym_num == D)
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
			d->textures.e_r_img, y * SIZE, x * SIZE);
	else if (keysym_num == LEFT || keysym_num == A)
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
			d->textures.e_l_img, y * SIZE, x * SIZE);
}

void	ft_move_sides(t_data *d, int x, int y, int keysym_num)
{
	if (keysym_num == UP || keysym_num == W)
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
			d->textures.p_b_img, y * SIZE, x * SIZE);
	else if (keysym_num == DOWN || keysym_num == S)
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
			d->textures.p_f_img, y * SIZE, x * SIZE);
	else if (keysym_num == RIGHT || keysym_num == D)
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
			d->textures.p_r_img, y * SIZE, x * SIZE);
	else if (keysym_num == LEFT || keysym_num == A)
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
			d->textures.p_l_img, y * SIZE, x * SIZE);
}

int	ft_move(t_data *d, int x, int y, int keysym_num)
{
	if (d->map.map[x][y] == '1')
		return (0);
	if (d->map.map[d->player.p_r][d->player.p_c] == '0'
		|| d->map.map[d->player.p_r][d->player.p_c] == 'P')
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win, d->textures.f_img,
			d->player.p_c * SIZE, d->player.p_r * SIZE);
	if (d->map.map[d->player.p_r][d->player.p_c] == 'E')
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win, d->textures.e_img,
			d->player.p_c * SIZE, d->player.p_r * SIZE);
	if (d->map.map[x][y] == 'C')
	{
		d->player.collectibles++;
		d->map.map[x][y] = '0';
	}
	if (d->map.map[x][y] == 'E')
		ft_move_in_exit(d, x, y, keysym_num);
	else
		ft_move_sides(d, x, y, keysym_num);
	d->player.p_r = x;
	d->player.p_c = y;
	return (1);
}

int	ft_keypress(int keysym_num, t_data *d)
{
	int	count_moves;

	count_moves = 0;
	if (keysym_num == ESC)
		ft_close_window(d);
	else if (keysym_num == UP || keysym_num == W)
		count_moves = ft_move(d, d->player.p_r - 1, d->player.p_c, keysym_num);
	else if (keysym_num == DOWN || keysym_num == S)
		count_moves = ft_move(d, d->player.p_r + 1, d->player.p_c, keysym_num);
	else if (keysym_num == RIGHT || keysym_num == D)
		count_moves = ft_move(d, d->player.p_r, d->player.p_c + 1, keysym_num);
	else if (keysym_num == LEFT || keysym_num == A)
		count_moves = ft_move(d, d->player.p_r, d->player.p_c - 1, keysym_num);
	if (count_moves == 1)
	{
		d->player.n_moves++;
		ft_printf("Number of Moves: %d\n", d->player.n_moves);
	}
	if (d->map.map[d->player.p_r][d->player.p_c] == 'E'
		&& d->player.collectibles == (int)d->map.n_collectibles)
	{
		ft_printf("Congratulations!\n");
		ft_close_window(d);
	}
	return (0);
}
