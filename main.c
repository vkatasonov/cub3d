/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:49:39 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/03 20:23:01 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_leaks(void)
{
	system("leaks -q cub3D");
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	ft_check_argc(argc);
	ft_read_file(argv[1], &data);
	if (data.content)
	{
		ft_print_data_content(&data);
		ft_print_fields(&data);
		ft_charpp_free(data.content);
	}
	atexit(ft_leaks);
	return (0);
}
