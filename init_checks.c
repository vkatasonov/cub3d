/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:20:25 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/01 12:57:32 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_check_argc(int n)
{
	if (n != 2)
	{
		perror(RED "Error\n Invalid number of arguments\n" RST);
		exit(EXIT_FAILURE);
	}
	return ;
}
