/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <lromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:18:50 by lromero-          #+#    #+#             */
/*   Updated: 2024/06/07 15:51:15 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static double	ft_limit_move(double pos, double mov)
{
	if (floor(pos) != floor(pos + mov))
	{
		if (mov < 0)
			return ((floor(pos) + 0.1) - pos);
		else if (mov > 0)
			return ((floor(pos) + 0.9) - pos);
	}
	else if ((mov < 0 && pos + mov < floor(pos) + 0.1))
		return ((floor(pos) + 0.1) - pos);
	else if ((mov > 0 && pos + mov > floor(pos) + 0.9))
		return ((floor(pos) + 0.9) - pos);
	return (mov);
}

static void	ft_move_collision(t_data *data, double *xmov, double *ymov)
{
	int	testx;
	int	testy;

	testx = (int)(data->px + *xmov);
	testy = (int)(data->py + *ymov);
	if (data->map[testy][testx] == '1')
	{
		*xmov = ft_limit_move(data->px, *xmov);
		*ymov = ft_limit_move(data->py, *ymov);
	}
	else
	{
		if (data->map[(int)data->py][testx] == '1'
			|| (*xmov < 0 && data->map[(int)data->py][(int)data->px - 1] == '1')
			|| (*xmov > 0 && data->map[(int)data->py][(int)data->px + 1] == '1'))
			*xmov = ft_limit_move(data->px, *xmov);
		if (data->map[testy][(int)data->px] == '1'
			|| (*ymov < 0 && data->map[(int)data->py - 1][(int)data->px] == '1')
			|| (*ymov > 0 && data->map[(int)data->py + 1][(int)data->px] == '1'))
			*ymov = ft_limit_move(data->py, *ymov);
	}
}

double	ft_move_angle(double *dirx, double *diry, double x, double y)
{
	double	angle;

	angle = 0;
	if (x)
	{
		if (y > 0 && x > 0)
			angle -= M_PI / 4;
		else if (y > 0 && x < 0)
			angle += M_PI / 4;
		else if (y < 0 && x > 0)
			angle -= M_PI * 3 / 4;
		else if (y < 0 && x < 0)
			angle += M_PI * 3 / 4;
		else if (x > 0)
			angle -= M_PI / 2;
		else
			angle += M_PI / 2;
	}
	else	
		if (y < 0)
			angle += M_PI;
	if (angle)
		ft_turn_angle(angle, dirx, diry);
	return (angle);
}

void	ft_movement(t_data *data, double xmov, double ymov)
{
	double	length;
	double	mvdist;
	double	mvx;
	double	mvy;
	double	mvangle;

	if (!xmov && !ymov)
		return ;
	length = sqrt(data->dir[1] * data->dir[1] + data->dir[0] * data->dir[0]);
	mvx = data->dir[1];
	mvy = data->dir[0];
	mvangle = ft_move_angle(&mvx, &mvy, xmov, ymov);
	mvdist = MOVESPEED * data->scr->mlx->delta_time;
	xmov = (mvdist * mvx / length) * -1;
	ymov = mvdist * mvy / length;
	if (fabs(xmov) > 1)
		xmov /= (xmov * -1);
	if (fabs(ymov) > 1)
		ymov /= (ymov * -1);
	ft_move_collision(data, &xmov, &ymov);
	data->px += xmov;
	data->py += ymov;
}