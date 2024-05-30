/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:47:04 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/29 14:03:15 by vkatason         ###   ########.fr       */
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

/**
 * @brief 				The function to get the width of the map. 
 * 						It's necessary to have it in the future 
 * 						for flood_fill and other proposals. 
 * 
 * @param data			Pointer to the main data struct 
 */
void	ft_map_width(t_data *data)
{
	int		i;
	int		max_width;
	int		current_width;
	char	*tmp;

	i = 0;
	max_width = 0;
	while (data->content[i])
	{
		tmp = data->content[i];
		if (tmp == 0)
			break ;
		current_width = 0;
		while (*tmp && *tmp != '\n')
		{
			current_width++;
			tmp++;
		}
		if (current_width > max_width)
			max_width = current_width;
		i++;
	}
	data->map_width = max_width;
}
