/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:47:04 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/16 14:55:30 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_copy_map(t_data *data)
{
	int		i;

	i = 0;
	data->mapcopy = malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->mapcopy)
		return ;
	while (data->map[i])
	{
		data->mapcopy[i] = ft_strdup(data->map[i]);
		i++;
	}
	data->mapcopy[i] = NULL;
}

