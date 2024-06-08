/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <lromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:22:28 by vkatason          #+#    #+#             */
/*   Updated: 2024/06/06 18:53:17 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 				Function to free the data struct
 * 						and all its members. 
 */
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

/**
 * @brief 				Function to clean the screen
 * 						and free all its members.
 * 						Destroy the images and textures.
 * 
 * @param data 			Pointer to the main data struct
 * @attention 			mlx_terminate is used to close 
 * 						the connection to the server
 * 						and free the memory allocated
 * 						for the `mlx struct`.
 */
void	ft_clean_scr(t_data *data)
{
	if (data->scr)
	{
		if (data->scr->mlx)
			mlx_terminate(data->scr->mlx);
		if (data->scr->ray)
			free(data->scr->ray);
		ft_destroy_textures(data);
		ft_destroy_images(data);
		free(data->scr);
	}
}

/**
 * @brief 				Function to destroy the images
 * 						allocated in the data->scr struct.
 * 
 * @param data 			Pointer to the main data struct
 */
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

/**
 * @brief 				Function to destroy the textures
 * 						allocated in the data->scr struct.
 * 
 * @param data 			Pointer to the main data struct
 */
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
