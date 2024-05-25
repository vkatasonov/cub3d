/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 11:48:07 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/11 12:41:44 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief			Function to check if the textures are valid
 * 					and load them to the data struct.
 * 					Textures are saved to the data->scr->texture array.
 * 
 * @param data		Pointer to the data struct
 * @warning			DON'T FORGET TO FREE THE TEXTURES (mlx_destroy_texture)
 */
void	ft_check_textures(t_data *data)
{
	int	i;

	data->scr = ft_calloc(1, sizeof(t_scr));
	data->scr->texture[0] = mlx_load_png(data->no);
	data->scr->texture[1] = mlx_load_png(data->so);
	data->scr->texture[2] = mlx_load_png(data->we);
	data->scr->texture[3] = mlx_load_png(data->ea);
	i = -1;
	while (++i < 4)
	{
		if (!data->scr->texture[i])
			exit (ft_printf_fd(STDERR_FILENO,
					RED "Error\nInvalid texture path: %s\n" RST,
					data->scr->texture[i]));
	}
}
