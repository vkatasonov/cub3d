/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:35:05 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/02 15:32:01 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_data_content(t_data *data)
{
	int	i;

	i = 0;
	ft_printf(GREEN U "\n\n*************** File content ***************\n\n" RST);
	while (data->content[i])
	{
		ft_printf("%s\n", data->content[i]);
		i++;
	}
}
