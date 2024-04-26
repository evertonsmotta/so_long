/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:53:45 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/08/30 17:35:30 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_args(int ac, char	**av, t_data	*data)
{
	int	len;

	if (ft_strlen(av[1]) > 4)
		len = ft_strlen(av[1]) - 4;
	if (ac == 2 && ft_strlen(av[1]))
	{
		if (ft_strncmp(av[1] + len - 1, "/.ber", 5) == 0)
			ft_error("Error\nUse: ./so_long <map.ber>\n", data);
		if (ft_strncmp(av[1] + len, ".ber", 4) != 0)
			ft_error("Error\nUse: ./so_long <map.ber>\n", data);
	}
}

void	ft_check_argv(int ac, char	**av, t_data	*data)
{
	if (ft_strlen(av[1]) <= 4 && ac == 2 && data)
	{
		ft_printf("Error\nUse: ./so_long <map.ber>\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		ft_check_argv(argc, argv, &data);
		ft_memset(&data, 0, sizeof(t_data));
		ft_memset(&data.player, 0, sizeof(t_plr));
		ft_check_args(argc, argv, &data);
		ft_map_init(&data, argv[1]);
		ft_map_check(&data);
		ft_game_init(&data);
		ft_xpm_file_to_image(&data);
		ft_put_image_to_window(&data);
		mlx_hook(data.mlx.win, 2, 1L << 0, ft_keypress, &data);
		mlx_hook(data.mlx.win, 17, 1L << 17, ft_close_window, &data);
		mlx_loop(data.mlx.mlx);
	}
	else
		ft_printf("Error\nUse: ./so_long <map.ber>\n");
}
