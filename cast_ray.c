/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <lromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:09:44 by lromero-          #+#    #+#             */
/*   Updated: 2024/06/08 18:07:34 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_calc_ray(t_data *data, double angle)
{
	data->scr->ray->x = data->px;
	data->scr->ray->y = data->py;
	data->scr->ray->dx = data->dir[1];
	data->scr->ray->dy = data->dir[0];
	ft_turn_angle(angle, &data->scr->ray->dx, &data->scr->ray->dy);
	data->scr->ray->dx *= -1;
}

static void	ft_draw_wall(t_data *data, int x, int y, double h)
{
	uint8_t		*pixel;
	uint32_t	i;
	uint32_t	tx;
	uint32_t	ty;
	double		impact;
	int			color;
	int			n;

	n = data->scr->ray->hitside;
	if (n == 2)
		impact = fmod(data->scr->ray->y, 1.0);
	else if (n == 3)
		impact = 1 - fmod(data->scr->ray->y, 1.0);
	else if (n == 0)
		impact = 1 - fmod(data->scr->ray->x, 1.0);
	else
		impact = fmod(data->scr->ray->x, 1.0);
	tx = floor((data->scr->img[n]->width - 1) * impact);
	ty = floor((data->scr->img[n]->height - 1) * h);
	i = tx + (ty * data->scr->img[n]->width);
	pixel = data->scr->img[n]->pixels + i * sizeof(int32_t);
	color = ft_get_rgba(*pixel, *(pixel + 1), *(pixel + 2), *(pixel + 3));
	mlx_put_pixel(data->scr->view, x, y, color);
}

void	ft_draw_column(t_data *data, int x, double angle)
{
	double	tdist;
	double	xdist;
	double	ydist;
	double	wallh;
	int	start;
	int	i;

	xdist = fabs(data->px - data->scr->ray->x);
	ydist = fabs(data->py - data->scr->ray->y);
	tdist = sqrt(xdist * xdist + ydist * ydist);
	wallh = round(SCREENWIDTH / (tdist * cos(angle)));
	start = SCREENHEIGHT / 2 - wallh / 2;
	i = 0;
	while (i < SCREENHEIGHT)
	{
		if (i < start && i < SCREENHEIGHT / 2)
			mlx_put_pixel(data->scr->view, x, i, 
				ft_get_rgba(data->c[1], data->c[2], data->c[3], 255));
		else if (i >= start && i < SCREENHEIGHT
			&& i < SCREENHEIGHT / 2 + wallh / 2)
			ft_draw_wall(data, x, i, (i - start) / wallh);
		else
			mlx_put_pixel(data->scr->view, x, i, 
				ft_get_rgba(data->f[1], data->f[2], data->f[3], 255));
		i++;
	}
}
