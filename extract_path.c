/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 01:44:06 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/11 21:27:56 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 			Function to get value of NSWE path
 * 					from the line read from the file
 * 					to the data->content array.
 * 					Example: NO /path_to_texture - 256x256.png
 * 					Will return "/path_to_texture - 256x256.png"
 * 
 * @param tmp 		pointer to the line read from the file
 * @return char*	returns the path value
 */
char	*ft_get_path_value(char *tmp)
{
	char	*path;

	tmp += 2;
	tmp = ft_skip_spaces(tmp);
	path = ft_strtrim(tmp, "\t \n");
	return (path);
}

/**
 * @brief 			Function to set the path value to 
 * 					the data struct. It checks if the path 
 * 					is already set and is it's a case
 * 					it returns 1, otherwise it sets the path
 * 					value to the data struct.
 * 
 * @param data		pointer to the data struct
 * @param tmp		pointer to the line read from the 
 * 					file to the data->content array
 * @param i			1 for NO, 2 for SO, 3 for WE, 4 for EA
 * @return int		0 if the path is set, 1 if the path is already set
 */
int	ft_set_path(t_data *data, char *tmp, int i)
{
	if (i == 1 && !data->no)
		return (data->no = ft_get_path_value(tmp), 0);
	else if (i == 2 && !data->so)
		return (data->so = ft_get_path_value(tmp), 0);
	else if (i == 3 && !data->we)
		return (data->we = ft_get_path_value(tmp), 0);
	else if (i == 4 && !data->ea)
		return (data->ea = ft_get_path_value(tmp), 0);
	return (1);
}

/**
 * @brief 			Check existense of the path in content
 * 					read from the file. It compares first symbols
 * 					of the line with NO, SO, WE, EA and if it's
 * 					true it calls ft_set_path function to set the path.
 * 
 * @param data 		pointer to the main data struct
 * @param tmp 		pointer to the line read from the file
 * @return int 		1 if the path is already set, 0 otherwise or in case if
 * 					the line is empty (first symbol is '\n')
 */
int	ft_check_path(t_data *data, char *tmp)
{
	if (!ft_strncmp(tmp, "NO ", 3))
		return (ft_set_path(data, tmp, 1));
	else if (!ft_strncmp(tmp, "SO ", 3))
		return (ft_set_path(data, tmp, 2));
	else if (!ft_strncmp(tmp, "WE ", 3))
		return (ft_set_path(data, tmp, 3));
	else if (!ft_strncmp(tmp, "EA ", 3))
		return (ft_set_path(data, tmp, 4));
	else if (tmp[0] == '\n')
		return (0);
	return (0);
}

/**
 * @brief 			Function to extract path of textures 
 * 					from the content stored in the data struct
 * 					and read from the file. It iterates over the
 * 					content array and checks if the line starts with
 * 					NO, SO, WE, EA. If it's true it calls ft_check_path
 * 					function to check if the path is already set.
 * 					If the path is already set it exits the program with
 * 					the error message.
 * 
 * @param data 		pointer to the main data struct
 */
void	ft_extract_path(t_data *data)
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
		if (!ft_strchr("NSWE\n", *tmp))
		{
			i++;
			continue ;
		}
		if (ft_strchr("NSWE\n", *tmp) && ft_check_path(data, tmp))
			exit(ft_printf_fd(STDERR_FILENO,
					RED "Error\nDuplicated texture path: %s\n"RST, tmp));
		i++;
	}
	ft_path_not_found(data);
}

/**
 * @brief 			Function to check if the path is not found
 * 					in the content read from the file. If the path
 * 					is not found it exits the program with the error
 * 					message.
 * 
 * @param data		pointer to the main data struct
 */
void	ft_path_not_found(t_data *data)
{
	if (!data->no)
		exit(ft_printf_fd(STDERR_FILENO, RED "Error\nNO path not found\n"));
	if (!data->so)
		exit(ft_printf_fd(STDERR_FILENO, RED "Error\nSO path not found\n"));
	if (!data->we)
		exit(ft_printf_fd(STDERR_FILENO, RED "Error\nWE path not found\n"));
	if (!data->ea)
		exit(ft_printf_fd(STDERR_FILENO, RED "Error\nEA path not found\n"));
}
