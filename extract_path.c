/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 01:44:06 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/04 01:45:12 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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