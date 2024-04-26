/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builders.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:01:50 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/08/30 16:31:49 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_create_map(t_data *data, char *map_file)
{
	char	**map;
	char	*line;
	int		fd;

	data->map.fd = open(map_file, O_RDONLY);
	ft_check_len_line(data->map.fd, data);
	fd = open(map_file, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (data->map.n_rows + 1));
	if (!map)
		ft_error("Error\nMalloc failed\n", data);
	line = NULL;
	while (data->i <= data->map.n_rows)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[data->i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		ft_strlcpy(map[data->i], line, ft_strlen(line));
		data->i++;
		free(line);
	}
	map[data->i] = NULL;
	data->i = 0;
	return (map);
}

void	ft_check_len_line(int fd, t_data *data)
{
	char			col;
	unsigned int	i;
	unsigned int	line;

	i = 0;
	line = 0;
	while (line < data->map.n_rows)
	{
		while (read(fd, &col, 1) > 0 && col != '\n')
			i++;
		if (i < data->map.n_col || i > data->map.n_col)
			ft_error("Error\nThe map must be rectangular.\n", data);
		line++;
		i = 0;
	}
}

int	ft_count_rows(int fd, t_data *data)
{
	unsigned int	i;
	char			rows;

	i = 1;
	while (read(fd, &rows, 1) > 0)
		if (rows == '\n')
			i++;
	if (i < 3)
		ft_error("Error\nThe map must be at least \
3 columns and 3 rows.\n", data);
	return (i);
}

int	ft_count_col(int fd, t_data *data)
{
	unsigned int	i;
	char			col;

	i = 0;
	while (read(fd, &col, 1) > 0 && col != '\n')
		i++;
	if (i < 3)
		ft_error("Error\nThe map must be at least \
3 columns and 3 rows.\n", data);
	return (i);
}

void	ft_map_init(t_data	*data, char	*map_file)
{
	data->map.fd = open(map_file, O_RDONLY);
	if (data->map.fd < 0)
		ft_error("Error\nMap not found\n", data);
	data->map.n_col = ft_count_col(data->map.fd, data);
	data->map.n_rows = ft_count_rows(data->map.fd, data);
	data->map.map = ft_create_map(data, map_file);
	data->map.n_collectibles = 0;
	data->map.n_exits = 0;
	data->map.n_players = 0;
	close(data->map.fd);
}
