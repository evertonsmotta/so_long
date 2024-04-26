/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:04:14 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/08/16 13:14:06 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_valid_format(t_data *data)
{
	if (!ft_check_around(data))
		ft_error("Error\nThe map must be surrounded by walls.\n", data);
	if (data->map.n_rows < 3 || data->map.n_col < 3)
		ft_error("Error\nThe map must be at least \
3 columns and 3 rows.\n", data);
	if (data->map.n_rows == data->map.n_col)
		ft_error("Error\nThe map must be rectangular.\n", data);
	while (data->i < data->map.n_rows)
	{
		if (ft_strlen(data->map.map[data->i]) != data->map.n_col)
			return (0);
		data->i++;
	}
	data->i = 0;
	return (1);
}

int	ft_check_around(t_data *data)
{
	while (data->i < data->map.n_rows)
	{
		if (data->map.map[data->i][data->j] != '1'
			|| data->map.map[data->i][data->map.n_col - 1] != '1')
			return (0);
		data->i++;
	}
	data->i = 0;
	while (data->map.map[data->i][data->j])
	{
		if (data->map.map[data->i][data->j] != '1'
			|| data->map.map[data->map.n_rows - 1][data->j] != '1')
			return (0);
		data->j++;
	}
	data->j = 0;
	return (1);
}

int	ft_check_chr(t_data *data)
{
	while (data->i < data->map.n_rows)
	{
		while (data->j < data->map.n_col)
		{
			if (data->map.map[data->i][data->j] == 'P')
			{
				data->map.n_players++;
				data->player.p_r = data->i;
				data->player.p_c = data->j;
			}
			else if (data->map.map[data->i][data->j] == 'C')
				data->map.n_collectibles++;
			else if (data->map.map[data->i][data->j] == 'E')
				data->map.n_exits++;
			else if (!ft_strchr("10PCE", data->map.map[data->i][data->j]))
				ft_error("Error\nInvalid character in map.\n", data);
			data->j++;
		}
		data->j = 0;
		data->i++;
	}
	data->i = 0;
	return (data->map.n_players == 1 && data->map.n_collectibles >= 1
		&& data->map.n_exits == 1);
}

int	ft_is_valid_map(t_data *data)
{
	char	**mapc;
	int		val;

	mapc = (char **)malloc(sizeof(char *) * (data->map.n_rows + 1));
	if (!mapc)
		ft_error("Error\nMalloc failed\n", data);
	while (data->i < data->map.n_rows)
	{
		mapc[data->i] = (char *)malloc((data->map.n_col + 1) * sizeof(char));
		if (!mapc[data->i])
		{
			ft_free_copy(mapc);
			ft_error("Error\nMalloc failed\n", data);
		}
		ft_strlcpy(mapc[data->i], data->map.map[data->i], data->map.n_col + 1);
		data->i++;
	}
	mapc[data->i] = NULL;
	data->i = 0;
	val = ft_flood_fill(data, mapc, data->player.p_r, data->player.p_c);
	ft_free_copy(mapc);
	return (val);
}

void	ft_map_check(t_data *data)
{
	if (!ft_is_valid_format(data))
		ft_error("Error\nThe map must be rectangular.\n", data);
	if (!ft_check_around(data))
		ft_error("Error\nThe map must be surrounded by walls.\n", data);
	if (!ft_check_chr(data))
		ft_error("Error\nThe map must have one player, \
one exit and at least one collectible.\n", data);
	if (!ft_is_valid_map(data))
		ft_error("Error\nThe player needs to be able to \
collect all collectibles and leave.\n", data);
}
