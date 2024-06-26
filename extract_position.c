/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:41:47 by vkatason          #+#    #+#             */
/*   Updated: 2024/06/12 17:40:24 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 			Function to get the position of the player
 * 					from the map and save it to the data struct.
 * 
 * @param data		Pointer to the main data struct
 * @var i			Counter for the data->map array
 * @var j			Counter for the data->map[i] array
 * @var tmp			Pointer to the current line
 * 
 * @note			In this function we store to parameters 
 * 					in the data struct: 
 * 					- mpx, mpy - the position of the player 
 * 					on the map
 * 					- px, py - the position of the player 
 * 					in the center of the cell of the map.
 * 					The difference between mpx, mpy and px, 
 * 					py is that the first one is integer 
 * 					and the second one is double. 
 * 					The first one is
 * 					used to have reference while 
 * 					checking the map and the second
 * 					one is used for painting purposes.
 */

void	ft_get_player_position(t_data *data)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (data->map[i])
	{
		tmp = data->map[i];
		j = 0;
		while (tmp[j])
		{
			if (ft_strchr("NSWE", tmp[j]))
			{
				data->mpx = j;
				data->mpy = i;
				data->px = j + 0.5;
				data->py = i + 0.5;
				ft_check_player_direction(data, tmp[j]);
				return ;
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief 			Function to check the player's direction.
 * 					Depending on the character it sets the direction
 * 					to the data->dir array.
 * 					N - North (0, -1)
 * 					S - South (0, 1)
 * 					W - West (-1, 0)
 * 					E - East (1, 0) 
 *
 * @param data 		Pointer to the main data struct
 * @param c			Character to check the direction
 */
void	ft_check_player_direction(t_data *data, char c)
{
	if (c == 'N')
	{
		data->dir[0] = -1;
		data->dir[1] = 0;
	}
	else if (c == 'S')
	{
		data->dir[0] = 1;
		data->dir[1] = 0;
	}
	else if (c == 'W')
	{
		data->dir[0] = 0;
		data->dir[1] = -1;
	}
	else if (c == 'E')
	{
		data->dir[0] = 0;
		data->dir[1] = 1;
	}
}
