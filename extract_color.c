/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:10:21 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/09 17:58:19 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
					RED "Error\nDuplicated color data: %s\n", tmp));
		i++;
	}
	ft_color_not_found(data);
}

void	ft_color_errors(t_data *data)
{
	if (data->f[0] == 0)
		exit(ft_printf_fd(STDERR_FILENO,
				RED "Error\nF color data not found\n"));
	if (data->c[0] == 0)
		exit(ft_printf_fd(STDERR_FILENO,
				RED "Error\nC color data not found\n"));
}
