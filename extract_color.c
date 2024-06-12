/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:10:21 by vkatason          #+#    #+#             */
/*   Updated: 2024/06/12 15:37:25 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 				Function to get the color values
 * 						from the color array. It checks if
 * 						the color data is already set and if
 * 						it's not it sets the color data.
 * 						Also it checks if the color data is valid
 * 						(0 <= color <= 255) and if it's not it exits
 * 						the program with an error message.
 * 						color && color[3] != 0 checks if there are
 * 						more than 3 values in the color array (that
 * 						means that the color data is invalid).	
 * 
 * @param value			Value of the color
 * @param color			Array of color values saved as strings
 * 						from the line read from the file to the
 * 						data->content array.
 * @param tmp 			Pointer to the line read from the file
 * 						to the data->content array.
 * @return int 			0 if the color data is set, 1 otherwise.
 */
int	ft_get_color_values(int *value, char **color, char *tmp)
{
	if (value[0] == 0)
	{
		value[0] = 1;
		value[1] = ft_atoi(color[0]);
		value[2] = ft_atoi(color[1]);
		value[3] = ft_atoi(color[2]);
		if ((color && color[3] != 0) || (value[1] > 255 || value[2] > 255
				|| value[3] > 255 || value[1] < 0 || value[2] < 0
				|| value[3] < 0))
		{
			ft_charpp_free(color);
			exit(ft_printf_fd(STDERR_FILENO,
					RED "Error\nInvalid color data: %s\n"RST, tmp));
		}
	}
	else
		return (1);
	ft_charpp_free(color);
	return (0);
}

/**
 * @brief 				Function to set the color data 
 * 						to the data struct.	It checks if 
 * 						the color data is already set 
 * 						(data->f[0] and data->c[0] is not set to 1)
 * 						and, if it's not, it sets the color data.
 * 						Helper function for ft_find_color.
 * 	
 * @param data			Pointer to the data struct
 * @param tmp			Pointer to the line read from the
 * 						file to the data->content array
 * @param i 			1 for F color, 2 for C color
 * @return int 			1 if the color data was set before, 0 otherwise
 */
int	ft_set_color(t_data *data, char *tmp, int i)
{
	char	**color;
	int		*value;

	value = NULL;
	if (i == 1)
		value = data->f;
	if (i == 2)
		value = data->c;
	tmp++;
	tmp = ft_skip_spaces(tmp);
	color = ft_split(tmp, ',');
	if (ft_skip_spaces(color[0]) == NULL || *ft_skip_spaces(color[0]) == '\0'
		|| ft_skip_spaces(color[1]) == NULL || *ft_skip_spaces(color[1]) == '\0'
		|| ft_skip_spaces(color[2]) == NULL || *ft_skip_spaces(color[2]) == '\0')
	{
		ft_charpp_free(color);
		exit(ft_printf_fd(STDERR_FILENO,
				RED "Error\nInvalid color data: %s\n"RST, tmp));
	}
	ft_get_color_values(value, color, tmp);
	return (0);
}

/**
 * @brief 				Function to find color data 
 * 						in the data->content array.
 *						It checks if the color data 
 						is already set (data->f[0]
						and data->c[0] is not set to 1)
						and, if it's not, it sets the color data.
						Helper function for ft_extract_color.
 * 	
 * @param data			Pointer to the main data struct.
 * @param tmp			Pointer to the line read from the
 * 						file to the data->content array.	
 * @return int			0 if the color data is set in this iteration,
 * 						1 if the color data was set before.
 */
int	ft_find_color(t_data *data, char *tmp)
{
	if (!ft_strncmp(tmp, "F ", 2) && data->f[0] == 0)
		return (ft_set_color(data, tmp, 1));
	else if (!ft_strncmp(tmp, "C ", 2) && data->c[0] == 0)
		return (ft_set_color(data, tmp, 2));
	else if (tmp[0] == '\n')
		return (0);
	return (1);
}

/**
 * @brief 				Function to extract color data 
 * 						from the data->content array.
 * 						It checks if the color data
 * 						(f and c members) is already 
 * 						set and if it's not it sets 
 * 						the color data. If the color
 * 						data is already set it exits 
 * 						the program with an error message.
 *		
 * @param data			Pointer to the main data struct. 			
 */
void	ft_extract_color(t_data *data)
{
	char	*tmp;
	int		i;

	i = 0;
	while (data->content[i])
	{
		tmp = data->content[i];
		if (tmp == 0)
			break ;
		tmp = ft_skip_spaces(tmp);
		if (!ft_strchr("FC\n", *tmp))
		{
			i++;
			continue ;
		}
		if (ft_strchr("FC\n", *tmp) && ft_find_color(data, tmp))
			exit(ft_printf_fd(STDERR_FILENO,
					RED "Error\nEmpty line or wrong color data\n"RST));
		i++;
	}
	ft_color_not_found(data);
}

/**
 * @brief 				Function checks if data->f[0] and data->c[0] flags
 * 						are set to 1. If not, it exits the program with an error
 * 						message.
 * 						Helper function for ft_extract_color.
 * 	
 * @param data			Pointer to the main data struct.
 */
void	ft_color_not_found(t_data *data)
{
	if (data->f[0] == 0)
		exit(ft_printf_fd(STDERR_FILENO,
				RED "Error\nF color data not found\n"RST));
	if (data->c[0] == 0)
		exit(ft_printf_fd(STDERR_FILENO,
				RED "Error\nC color data not found\n"RST));
}
