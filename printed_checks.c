/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:35:05 by vkatason          #+#    #+#             */
/*   Updated: 2024/06/12 17:43:10 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 			Function to print the content read 
 * 					from `.cub` file.
 *
 * @param data 		Pointer to the main data struct
 * @var i			Counter for the data->content array
 */
void	ft_print_data_content(t_data *data)
{
	int	i;

	i = 0;
	ft_printf(GREEN U "\n\n********** File content **********\n\n" RST);
	while (data->content[i])
	{
		ft_printf("%s\n", data->content[i]);
		i++;
	}
}

/**
 * @brief 			Function to print the extracted map.
 *
 * @param data 		Pointer to the main data struct
 * @var i			Counter for the data->map array
 */
void	ft_print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	ft_printf(GREEN U "\n\n********** Extracted map **********\n\n" RST);
	while (data->map[i])
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
	ft_printf(GREEN U "\nMap height:"RST);
	ft_printf(" %d\n", data->map_height);
	ft_printf(GREEN U "Map width:"RST);
	ft_printf(" %d\n", data->map_width);
	j = 0;
	ft_printf(GREEN U "\n\n********** Map copy **********\n\n" RST);
	while (data->mapcopy[j])
	{
		ft_printf("%s\n", data->mapcopy[j]);
		j++;
	}
}

/**
 * @brief 			Function to print paths to the textures
 * 					received from the `.cub` file.
 *
 * @param data 		Pointer to the main data struct
 */
void	ft_print_fields(t_data *data)
{
	ft_printf(GREEN U "\n\n********** Received paths **********\n\n" RST);
	ft_printf("NO: %s\n", data->no);
	ft_printf("SO: %s\n", data->so);
	ft_printf("WE: %s\n", data->we);
	ft_printf("EA: %s\n", data->ea);
}

/**
 * @brief 			Function to print the colors received
 * 					from the `.cub` file and saved to the
 * 					data->f and to the data->c.
 *
 * @param data 		Pointer to the main data struct
 */
void	ft_print_colors(t_data *data)
{
	ft_printf(GREEN U "\n\n********** Received colors **********\n\n" RST);
	ft_printf("F: %d, %d, %d, %d\n",
		data->f[0],
		data->f[1],
		data->f[2],
		data->f[3]);
	ft_printf("C: %d, %d, %d, %d\n",
		data->c[0],
		data->c[1],
		data->c[2],
		data->c[3]);
}

/**
 * @brief 			Function to print the position 
 * 					of the player on the map and the
 * 					direction of the player (NSWE).
 * 					Depending on the direction we set the
 *					wall image. 
 * 
 * @param data 		Pointer to the main data struct
 */
void	ft_print_position(t_data *data)
{
	ft_printf(GREEN U "\n\n********** Player Position **********\n\n" RST);
	ft_printf(GREEN U "Direction: " RST);
	printf("\n%f, %f\n\n", data->dir[0], data->dir[1]);
	printf(GREEN U "Coordinates px (doubles)\n" RST);
	printf("X: %f, Y: %f\n\n", data->px, data->py);
	printf(GREEN U "Coordinates mpx (ints)\n" RST);
	printf("X: %d, Y: %d\n\n", data->mpx, data->mpy);
}
