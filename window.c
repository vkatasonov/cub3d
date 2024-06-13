/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:49:16 by lromero-          #+#    #+#             */
/*   Updated: 2024/06/13 15:36:13 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 			Function to load the walls
 * 					textures.
 * 
 * @param scr 		Pointer to the screen struct.
 * @return int 		1 if the wall img load failed.
 */
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

/**
 * @brief 			Function to launch the window.
 * 					Initializes the mlx, the view and the ray.
 * 					Also loads the wall textures.
 * 					Exits if the wall textures failed to load.
 * @param data 		Pointer to the main data struct.
 */
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

/**
 * @brief 			Function to draw the hook.
 * 					Loops through the screen width
 * 					and draws the columns.
 * 
 * @param param 	Pointer to the main data struct.
 * @var data 		Pointer to the main data struct.
 * @var angle 		The angle of the ray.
 * @var i 			The index of the column.
 * @var SCREENWIDTH The width of the screen.
 */
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

/**
 * @brief 				Function to hold the key hook.
 * 						Checks if the keys are pressed and
 * 						moves the player accordingly.
 * 						Also checks if the escape key is pressed
 * 						and closes the window.
 * 
 * @var data 			Pointer to the main data struct.
 * @var angle 			The angle to turn.
 * @var x 				The x-coordinate to move.
 * @var y 				The y-coordinate to move.
 * @var TURNSPEED 		The speed to turn.
 */
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
	if (mlx_is_key_down(data->scr->mlx, MLX_KEY_LEFT))
		angle += TURNSPEED * data->scr->mlx->delta_time;
	if (mlx_is_key_down(data->scr->mlx, MLX_KEY_RIGHT))
		angle -= TURNSPEED * data->scr->mlx->delta_time;
	ft_turn_angle(angle, &data->dir[1], &data->dir[0]);
	ft_movement(data, x, y);
}
