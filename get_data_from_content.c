/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_from_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:25:49 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/03 19:56:22 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_fields(t_data *data, char *tmp)
{
	if (!ft_strncmp("NO ", tmp, 3))
		return (ft_fill_field_path(data, tmp, 1));
	else if (!ft_strncmp("SO ", tmp, 3))
		return (ft_fill_field_path(data, tmp, 2));
	else if (!ft_strncmp("WE ", tmp, 3))
		return (ft_fill_field_path(data, tmp, 3));
	else if (!ft_strncmp("EA ", tmp, 3))
		return (ft_fill_field_path(data, tmp, 4));
	else if (!ft_strncmp("S ", tmp, 2))
		return (ft_fill_field_path(data, tmp, 5));
	else if (!ft_strncmp("F ", tmp, 2))
		return (ft_fill_colors(data, tmp, 6));
	else if (!ft_strncmp("C ", tmp, 2))
		return (ft_fill_colors(data, tmp, 7));
	else if (tmp[0] == '\n')
		return (0);
	return (0);
}

void	ft_get_data(t_data *data)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	line = "";
	while (1 && (!data->no || !data->so || !data->we || !data->ea
			|| data->f[0] == 0 || data->c[0] == 0))
	{
		line = data->content[i];
		if (line == 0)
			break ;
		tmp = line;
		tmp = ft_skip_spaces(tmp);
		if (ft_strchr("NSWEFC\n", *tmp) && ft_check_fields(data, tmp))
			exit(1);
		else if (!ft_strchr("NSWEFC\n", *tmp))
			exit(ft_printf_fd(STDERR_FILENO,
					RED "Invalid or missing field in map file\n" RST));
		free(line);
		i++;
	}
}
