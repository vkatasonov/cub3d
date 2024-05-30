/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:22:35 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/30 19:13:07 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief			Function to check validity of the map
 * 					by using flood fill algorithm.
 * 					Check starts from the player position and
 * 					goes through the map, and checks if it's closed.
 * 					If it's not closed we exit the program.
 * 					First check is to see if we are within the map.
 * 					Second check is to see if we reached a position
 * 					outside the wall.
 * 
 * @var x			Position on the x-axis
 * @var y			Position on the y-axis
 * @param data		Pointer to the main data struct
 */
void	ft_flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || y >= data->map_height)
		ft_free_and_exit (data, "Holes in the walls");
	if (data->mapcopy[y][x] == 'F' || data->mapcopy[y][x] == '1')
		return ;
	if (data->mapcopy[y][x] == ' ' || data->mapcopy[y][x] == '\0')
		ft_free_and_exit(data, "Holes in the walls");
	data->mapcopy[y][x] = 'F';
	ft_flood_fill(data, x - 1, y);
	ft_flood_fill(data, x + 1, y);
	ft_flood_fill(data, x, y - 1);
	ft_flood_fill(data, x, y + 1);
}

/**
 * @brief 			Function to check if all positions 
 * 					are covered by flood fill.
 * 					The purpose of this function is to check
 * 					if small islinds or other places on the map
 * 					had been fullfilled. It's made by checking
 * 					if there are any '0' left in the mapcopy.
 * 					If there are, we exit the program.
 *
 * @param data 		Pointer to the main data struct
 * @var i			Counter for the data->mapcopy array
 * @var j			Counter for the data->mapcopy[i] array
 *
 * @note			Lines in the mapcopy are delimited by '\0'.
 */
void	ft_check_flood_fill(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (data->mapcopy[i][j] != '\0')
		{
			if (data->mapcopy[i][j] == '0')
			{
				ft_flood_fill(data, j, i);
			}
			j++;
		}
		i++;
	}
}
