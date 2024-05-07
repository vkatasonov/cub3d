/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:35:05 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/03 19:24:37 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_data_content(t_data *data)
{
	int	i;

	i = 0;
	ft_printf(GREEN U "\n\n********** File content **********\n\n" RST);
	while (data->content[i])
	{
		ft_printf("%s\n", data->content[i]);
		i++;
	}
}

void	ft_print_fields(t_data *data)
{
	ft_printf(GREEN U "\n\n********** Received paths **********\n\n" RST);
	ft_printf("NO: %s\n", data->no);
	ft_printf("SO: %s\n", data->so);
	ft_printf("WE: %s\n", data->we);
	ft_printf("EA: %s\n", data->ea);
	ft_printf("F: %d, %d, %d, %d\n",
		data->f[0],
		data->f[1],
		data->f[2],
		data->f[3]);
	ft_printf("C: %d, %d, %d, %d\n",
		data->c[0],
		data->c[1],
		data->c[2],
		data->c[3]);
}
