/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_from_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:25:49 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/03 00:14:33 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_fields(t_data *data, char *tmp)
{
	if (!ft_strncmp("NO ", tmp, 3))
		//TODO
	
	
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
		line = data->content[i++];
		if (line == 0)
			break ;
		tmp = line;
		tmp = ft_skip_spaces(tmp);
		if (ft_strchr("NSWEFC\n", *tmp) && ft_check_fields(data, tmp))
			exit (1);
		else if (!ft_strchr("NSWEFC\n", *tmp))
			exit (ft_print_fd(STDERR_FILENO,
					RED "Invalid or missing field in map file\n" RST));
		free(line);
	}
}
