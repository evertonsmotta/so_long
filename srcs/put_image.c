/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:07:59 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/08/30 17:40:16 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_xpm_file_to_image(t_data *data)
{
	data->textures.w_img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_W,
			&data->textures.width, &data->textures.height);
	data->textures.f_img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_F,
			&data->textures.width, &data->textures.height);
	data->textures.c_img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_C,
			&data->textures.width, &data->textures.height);
	data->textures.p_f_img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_P_F,
			&data->textures.width, &data->textures.height);
	data->textures.p_b_img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_P_B,
			&data->textures.width, &data->textures.height);
	data->textures.p_r_img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_P_R,
			&data->textures.width, &data->textures.height);
	data->textures.p_l_img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_P_L,
			&data->textures.width, &data->textures.height);
	data->textures.e_img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_E,
			&data->textures.width, &data->textures.height);
	data->textures.e_f_img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_E_F,
			&data->textures.width, &data->textures.height);
	data->textures.e_b_img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_E_B,
			&data->textures.width, &data->textures.height);
	data->textures.e_r_img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_E_R,
			&data->textures.width, &data->textures.height);
	data->textures.e_l_img = mlx_xpm_file_to_image(data->mlx.mlx, PATH_E_L,
			&data->textures.width, &data->textures.height);
}

void	ft_put_image_to_window(t_data *data)
{
	while (data->i < data->map.n_rows)
	{
		while (data->j < data->map.n_col)
		{
			if (data->map.map[data->i][data->j] == '1')
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
					data->textures.w_img, data->j * SIZE, data->i * SIZE);
			else if (data->map.map[data->i][data->j] == '0')
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
					data->textures.f_img, data->j * SIZE, data->i * SIZE);
			else if (data->map.map[data->i][data->j] == 'P')
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
					data->textures.p_f_img, data->j * SIZE, data->i * SIZE);
			else if (data->map.map[data->i][data->j] == 'E')
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
					data->textures.e_img, data->j * SIZE, data->i * SIZE);
			else if (data->map.map[data->i][data->j] == 'C')
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
					data->textures.c_img, data->j * SIZE, data->i * SIZE);
			data->j++;
		}
		data->j = 0;
		data->i++;
	}
	data->i = 0;
}
