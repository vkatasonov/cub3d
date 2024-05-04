/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 01:44:06 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/04 05:04:32 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 				Function to set path of N, S, W, or E
 * 						to data->no, data->so, data->we, or data->ea
 * 						according to the value.
 * @note 				It also prints an error message if there 
 * 						a duplicate path of N, S, W, or E is found.
 * 	
 * @param path 			The path to set (data->no, data->so, data->we, 
 * 						or data->ea)
 * @param value 		The value to set to path
 * @param error_msg 	The error message to print if there is a duplicate path
 * 						of N, S, W, or E
 * @return int 			1 if there is a duplicate path, 0 otherwise
 */
int	ft_set_path(char **path, char *value, char *error_msg)
{
	char	*start;
	char	*end;
	int		length;

	if (*path)
	{
		ft_printf_fd(STDERR_FILENO,
			RED "Error\nDuplicate %s path\n", error_msg);
		return (1);
	}
	start = ft_strchr(value, ' ');
	if (start)
	{
		start++;
		end = ft_strchr(start, ' ');
		if (end)
			length = end - start;
		else
			length = ft_strlen(start);
		*path = ft_calloc(length + 1, sizeof(char));
		ft_strncpy(*path, start, length);
	}
	else
		*path = ft_strdup(value);
	return (0);
}

/**
 * @brief 			Function to find a path of N, S, W, or E
 * 					in data->content[i] and set it to data->no,
 * 					data->so, data->we, or data->ea
 * 
 * @param data 		The structure that contains main data
 * @param tmp  		The string that contains data->content[i]
 * @return int 		1 if there is a duplicate path, 0 otherwise
 */
int	ft_check_path(t_data *data, char *tmp)
{
	if (ft_strncmp(tmp, "NO", 2) == 0)
		return (ft_set_path(&data->no, tmp + 2, "NO"));
	else if (ft_strncmp(tmp, "SO", 2) == 0)
		return (ft_set_path(&data->so, tmp + 2, "SO"));
	else if (ft_strncmp(tmp, "WE", 2) == 0)
		return (ft_set_path(&data->we, tmp + 2, "WE"));
	else if (ft_strncmp(tmp, "EA", 2) == 0)
		return (ft_set_path(&data->ea, tmp + 2, "EA"));
	return (0);
}

/**
 * @brief           Function to extract path of N, S, W, or E
 *                  from data->content (saved copy of file content)   
 * 
 * @param data      The structure that contains main data
 * @var i           Index of data->content
 * @var tmp         Temporary string to store data->content[i]
 */
void	ft_extract_path(t_data *data)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (data->content[i]
		&& (!data->no || !data->so
			|| !data->we || !data->ea))
	{
		if (data->content[i] == 0)
			break ;
		tmp = ft_strdup(data->content[i]);
		tmp = ft_skip_spaces(tmp);
		if (ft_strchr("NSWE\n", *tmp) && ft_check_path(data, tmp))
			exit(1);
		else if (!ft_strchr("NSWE\n", *tmp))
			exit(ft_printf_fd(STDERR_FILENO,
					RED "Error\nInvalid or missing field (NSWE) in map\n"));
		i++;
		free(tmp);
	}
}
