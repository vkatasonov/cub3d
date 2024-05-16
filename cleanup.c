/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:22:28 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/16 13:53:32 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_data(t_data *data)
{
	if (data->content)
		ft_charpp_free(data->content);
	if (data->map)
		ft_charpp_free(data->map);
	if (data->mapcopy)
		ft_charpp_free(data->mapcopy);
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	ft_clean_scr(data);
}


void	ft_clean_scr(t_data *data)
{
	if (data->scr)
	{
		if (data->scr->mlx)
			mlx_terminate(data->scr->mlx);
		if (data->scr->win)
			mlx_close_window(data->scr->win);
		ft_destroy_textures(data);
		ft_destroy_images(data);
		free(data->scr);
	}
}

void	ft_destroy_images(t_data *data)
{
	int	i;

	if (!data->scr)
		return ;
	if (data->scr)
	{
		i = -1;
		while (++i < 4)
		{
			if (data->scr->img[i])
				mlx_delete_image(data->scr->mlx, data->scr->img[i]);
		}
	}
}

void	ft_destroy_textures(t_data *data)
{
	int	i;

	if (!data->scr)
		return ;
	if (data->scr)
	{
		i = -1;
		while (++i < 4)
		{
			if (data->scr->texture[i])
				mlx_delete_texture(data->scr->texture[i]);
		}
	}
}
