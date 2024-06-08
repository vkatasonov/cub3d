/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <lromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:49:39 by vkatason          #+#    #+#             */
/*   Updated: 2024/06/08 16:14:00 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	ft_check_argc(argc);
	ft_read_file(argv[1], &data);
	ft_print_fields(&data);
	ft_print_colors(&data);
	ft_printf(GREEN"Textures are loaded\n"RST);
	ft_print_map(&data);
	ft_print_position(&data);
	ft_launch_window(&data);
	mlx_loop_hook(data.scr->mlx, ft_draw_hook, &data);
	mlx_loop_hook(data.scr->mlx, ft_key_hook, &data);
	mlx_loop(data.scr->mlx);
	ft_free_data(&data);
	return (0);
}
