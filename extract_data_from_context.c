/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data_from_context.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:31:34 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/16 18:17:56 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 				Function to extract basic data
 * 						from the data->context. It combines
 * 						functions to extract path, color, check
 * 						textures, check map and get player position.
 * 
 * @param data 			Pointer to the main data struct
 */
void	ft_extract_data(t_data *data)
{
	ft_extract_path(data);
	ft_extract_color(data);
	ft_check_textures(data);
	ft_check_map(data);
	ft_get_player_position(data);
}
