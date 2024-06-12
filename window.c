/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <lromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:49:16 by lromero-          #+#    #+#             */
/*   Updated: 2024/06/08 17:50:13 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_load_walls(t_scr *scr)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		scr->img[i] = mlx_texture_to_image(scr->mlx, scr->texture[i]);
		if (!scr->img[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_launch_window(t_data *data)
{
	data->scr->ray = malloc(sizeof(t_ray));
    data->scr->mlx = mlx_init(SCREENWIDTH, SCREENHEIGHT, "cub3D", false);
    data->scr->view = mlx_new_image(data->scr->mlx, SCREENWIDTH, SCREENHEIGHT);
    if (!data->scr->ray || !data->scr->mlx || !data->scr->view)
    {
    	ft_printf_fd(STDERR_FILENO, RED "Error\nView load failed\n" RST);
    	ft_free_data(data);
    	exit(EXIT_FAILURE);
    }
    mlx_image_to_window(data->scr->mlx, data->scr->view, 0, 0);
    data->scr->fovangle = FOV / (double)SCREENWIDTH;
	if (ft_load_walls(data->scr))
	{
		ft_printf_fd(STDERR_FILENO, RED "Error\nWall img load failed\n" RST);
    	ft_free_data(data);
    	exit(EXIT_FAILURE);
	}
}

void	ft_draw_hook(void *param)
{
	t_data	*data;
	double	angle;
	int		i;

	data = (t_data *)param;
	angle = 0;
	i = (SCREENWIDTH / 2) - 1;
	while (i >= 0)
	{
		angle += data->scr->fovangle;
		ft_calc_ray(data, angle);
		ft_ray_collision(data->scr->ray, data->px, data->map);
		ft_draw_column(data, i, angle);
		i--;
	}
	i = (SCREENWIDTH / 2);
	angle = 0;
	while (i < SCREENWIDTH)
	{
		angle -= data->scr->fovangle;
		ft_calc_ray(data, angle);
		ft_ray_collision(data->scr->ray, data->px, data->map);
		ft_draw_column(data, i, angle);
		i++;
	}
}

void	ft_key_hook(void *param)
{
	t_data	*data;
	double	angle;
	double	x;
	double	y;

	data = (t_data *)param;
	angle = 0;
	x = 0;
	y = 0;
	if (mlx_is_key_down(data->scr->mlx, MLX_KEY_ESCAPE))
		return (mlx_close_window(data->scr->mlx));
	if (mlx_is_key_down(data->scr->mlx, MLX_KEY_W))
		y += 1;
	if (mlx_is_key_down(data->scr->mlx, MLX_KEY_A))
		x -= 1;
	if (mlx_is_key_down(data->scr->mlx, MLX_KEY_S))
		y -= 1;
	if (mlx_is_key_down(data->scr->mlx, MLX_KEY_D))
		x += 1;
	if(mlx_is_key_down(data->scr->mlx, MLX_KEY_LEFT))
		angle += TURNSPEED * data->scr->mlx->delta_time;
	if(mlx_is_key_down(data->scr->mlx, MLX_KEY_RIGHT))
		angle -= TURNSPEED * data->scr->mlx->delta_time;
	ft_turn_angle(angle, &data->dir[1], &data->dir[0]);
	ft_movement(data, x, y);
}
