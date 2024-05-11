/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:49:39 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/11 17:11:25 by vkatason         ###   ########.fr       */
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

	atexit(ft_leaks);
	ft_memset(&data, 0, sizeof(t_data));
	ft_check_argc(argc);
	ft_read_file(argv[1], &data);
	ft_print_fields(&data);
	ft_print_colors(&data);
	ft_printf(GREEN"Textures are loaded\n"RST);
	ft_print_map(&data);
	ft_free_data(&data);
	return (0);
}
