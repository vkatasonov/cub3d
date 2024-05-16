/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:47:04 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/16 18:14:44 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 				Function to copy the map to the mapcopy
 * 						which is used for floodfill that checks
 * 						if the map is closed.
 * 
 * @param data 			Pointer to the main data struct
 */
void	ft_copy_map(t_data *data)
{
	int		i;

	i = 0;
	data->mapcopy = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->mapcopy)
		return ;
	while (data->map[i])
	{
		data->mapcopy[i] = ft_strdup(data->map[i]);
		i++;
	}
	data->mapcopy[i] = NULL;
}

