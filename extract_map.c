/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:38:16 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/11 17:59:42 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 				Function to get the height of the map
 * 						from the data->content array to use it
 * 						to allocate exact amount of memory
 * 						for the map. Helper function for ft_extract_map.
 * 
 * @param data 			Pointer to the main data struct
 * @return int			The height of the map
 * @var i				Counter for the data->content array
 * @var count			Counter for the height of the map
 * @var tmp				Pointer to the current line
 */
int	ft_map_height(t_data *data)
{
	int		i;
	int		count;
	char	*tmp;

	i = 0;
	count = 0;
	while (data->content[i])
	{
		tmp = data->content[i];
		if (tmp == 0)
			break ;
		tmp = ft_skip_spaces(tmp);
		if (!ft_strchr("NSWEFC\n", *tmp))
			count++;
		i++;
	}
	return (count);
	printf(GREEN"Height of map: %d\n"RST, count);
}

/**
 * @brief 				Function to extract the map 
 * 						from the data->content and save it
 * 						to the data->map array.
 * 
 * @param data 			Pointer to the main data struct
 * @var tmp				Pointer to the current line
 * @var i				Counter for the data->content array
 * @var j				Counter for the data->map array
 */
void	ft_extract_map(t_data *data)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->map = malloc(sizeof(char *) * ft_map_height(data) + 1);
	while (data->content[i])
	{
		tmp = data->content[i];
		if (tmp == 0)
			break ;
		tmp = ft_skip_spaces(tmp);
		if (!ft_strchr("NSWEFC\n", *tmp))
		{
			data->map[j] = ft_strdup(data->content[i]);
			j++;
		}
		data->map[j] = 0;
		i++;
	}
}
