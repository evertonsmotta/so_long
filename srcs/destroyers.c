/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:56:32 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/08/16 13:32:18 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_map(char **map)
{
	int	i;

	i = -1;
	if (!map)
		return ;
	while (map[++i])
	{
		free(map[i]);
		map[i] = NULL;
	}
	free(map);
	map = NULL;
}

void	ft_destroy_textures(t_data *data)
{
	if (data->textures.f_img && data->textures.w_img && data->textures.c_img)
	{
		mlx_destroy_image(data->mlx.mlx, data->textures.f_img);
		mlx_destroy_image(data->mlx.mlx, data->textures.w_img);
		mlx_destroy_image(data->mlx.mlx, data->textures.c_img);
	}
	if (data->textures.p_f_img && data->textures.p_b_img)
		mlx_destroy_image(data->mlx.mlx, data->textures.p_f_img);
	if (data->textures.p_b_img)
		mlx_destroy_image(data->mlx.mlx, data->textures.p_b_img);
	if (data->textures.p_r_img)
		mlx_destroy_image(data->mlx.mlx, data->textures.p_r_img);
	if (data->textures.p_l_img)
		mlx_destroy_image(data->mlx.mlx, data->textures.p_l_img);
	if (data->textures.e_img)
		mlx_destroy_image(data->mlx.mlx, data->textures.e_img);
	if (data->textures.e_f_img)
		mlx_destroy_image(data->mlx.mlx, data->textures.e_f_img);
	if (data->textures.e_b_img)
		mlx_destroy_image(data->mlx.mlx, data->textures.e_b_img);
	if (data->textures.e_r_img)
		mlx_destroy_image(data->mlx.mlx, data->textures.e_r_img);
	if (data->textures.e_l_img)
		mlx_destroy_image(data->mlx.mlx, data->textures.e_l_img);
}

void	ft_destroy_display(t_data *data)
{
	if (data)
	{
		ft_destroy_textures(data);
		if (data->map.map)
			ft_destroy_map(data->map.map);
		if (data->mlx.win)
			mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		if (data->mlx.mlx)
			mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
	}
}

int	ft_close_window(t_data *data)
{
	if (data)
		ft_destroy_display(data);
	exit(0);
	return (0);
}

void	ft_error(char *str, t_data *data)
{
	ft_printf("%s", str);
	ft_close_window(data);
}
