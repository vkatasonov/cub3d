/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:38:16 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/11 21:29:41 by vkatason         ###   ########.fr       */
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
	ft_not_tab(data);
	ft_not_valid_char(data);
}

/**
 * @brief 					Function to check if the map contains
 * 							invalid characters. If the character is
 * 							not '0', '1', 'N', 'S', 'W', 'E', ' ' or '\n'
 * 							it exits the program with an error message.
 * 	
 * @param data 				Pointer to the main data struct
 * @var i					Counter for the data->map array
 * @var j					Counter for the current line
 * @var data->map[i][j]		Current character	
 */
void	ft_not_valid_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (!(data->map[i][j] == '0' || data->map[i][j] == '1'
				|| data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E'
				|| data->map[i][j] == ' ' || data->map[i][j] == '\n'))
			{
				ft_printf_fd(2,
					RED "Error\nInvalid character in the map: %c\n" RST,
					data->map[i][j]);
				ft_free_data(data);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief 					Function to check if the map contains tabs
 * 							(that is invalid in terms of raycasting). 
 * 							If the map contains tabs it exits the program
 * 							with an error message.
 * 	
 * @param data 				Pointer to the main data struct
 * @var i					Counter for the data->map array
 * @var j					Counter for the current line
 * @var data->map[i][j]		Current character
 */
void	ft_not_tab(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i] && data->map[i][j])
		{
			if (data->map[i][j] == '\t')
			{
				ft_printf_fd(2, RED "Error\nMap contains tabs\n"RST);
				ft_free_data(data);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
