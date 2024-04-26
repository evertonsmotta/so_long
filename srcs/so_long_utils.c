/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:13:34 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/08/16 13:14:04 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_flood_fill(t_data *data, char **mapc, int x, int y)
{
	static int	n_exits;
	static int	n_collectibles;

	if (mapc[x][y] == '1')
		return (0);
	if (mapc[x][y] == 'C')
		n_collectibles++;
	if (mapc[x][y] == 'E')
		n_exits++;
	mapc[x][y] = '1';
	ft_flood_fill(data, mapc, x + 1, y);
	ft_flood_fill(data, mapc, x - 1, y);
	ft_flood_fill(data, mapc, x, y + 1);
	ft_flood_fill(data, mapc, x, y - 1);
	if (n_collectibles != (int)data->map.n_collectibles || n_exits != 1)
		return (0);
	return (1);
}

void	ft_free_copy(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		free(map[i]);
		map[i] = NULL;
	}
	free(map);
}

void	ft_game_init(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		ft_error("Error\nmlx_init() failed", data);
	data->mlx.win = mlx_new_window(data->mlx.mlx,
			SIZE * data->map.n_col, SIZE * data->map.n_rows, "so_long");
	if (!data->mlx.win)
	{
		mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
		ft_error("Error\nmlx_new_window() failed", data);
	}
}
