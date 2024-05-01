/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:35:05 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/01 13:33:35 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_data_content(t_data *data)
{
	int	i;

	i = 0;
	while (data->content[i])
	{
		ft_printf(RED "%s\n" RST, data->content[i]);
		i++;
	}
}
