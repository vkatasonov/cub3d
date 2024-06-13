/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:19:20 by lromero-          #+#    #+#             */
/*   Updated: 2024/06/13 15:29:17 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 			Function to calculate the next square
 * 					along the ray.
 * 
 * @param pos 		The position of the ray.
 * @param dir 		The direction of the ray.
 * @param r 		The ratio of the ray.
 * @param dir2 		The direction of the ray.
 * @return double 	The next square along the ray.
 */
static double	ft_next_square(double pos, double dir, double r, double dir2)
{
	double	next_line;
	double	side;

	next_line = (int)pos;
	if (dir > 0)
		next_line++;
	else if (dir < 0 && next_line == pos)
		next_line--;
	side = next_line - pos;
	if ((side < 0) != (dir2 < 0))
		side *= -1;
	return (side * r);
}

/**
 * @brief 			Function to move the ray to the next line.
 * 
 * @param ray_pos	The position of the ray.
 * @param dir 		The direction of the ray.
 * @return double 	The position of the ray on the next line.
 */
static double	ft_move_to_line(double ray_pos, double dir)
{
	double	end_pos;

	end_pos = (int)ray_pos;
	if (dir > 0)
		end_pos++;
	else if (dir < 0 && end_pos == ray_pos)
		end_pos--;
	return (end_pos);
}

/**
 * @brief 			Function to check if the ray intersects
 * 
 * @param ray		The ray to check.
 * @param px 		The position of the ray.
 * @return int 		1 if the ray intersects, 0 otherwise.
 */
static int	ft_intersection(t_ray *ray, double px)
{
	double	x;

	x = ft_move_to_line(ray->x, ray->dx);
	x = fabs(px - x);
	if (fabs(ray->yjump) < fabs(ray->xjump))
	{
		if ((fabs(ray->xjump) < 1 && !fmod(ray->x, 1))
			|| (fmod(ray->x, 1) && fmod(ray->y, 1)
				&& x > fabs(ray->xjump)))
			return (0);
		return (1);
	}
	else
	{
		if ((fabs(ray->yjump) < 1 && !fmod(ray->y, 1))
			|| (fmod(ray->x, 1) && fmod(ray->y, 1)
				&& x < fabs(ray->xjump)))
			return (1);
	}
	return (0);
}

/**
 * @brief 			Function to check if the ray hits the wall.
 * 
 * @param ray		The ray to check.
 * @param flag 		The flag to check the direction.
 * @param map 		The map to check.
 * @return int 		1 if the ray hits the wall, 0 otherwise.
 */
static int	ft_check_hit(t_ray *ray, int flag, char **map)
{
	double	y;
	double	x;

	y = (int)ray->y;
	x = (int)ray->x;
	if (!flag && ray->dy < 0)
		y--;
	else if (flag && ray->dx < 0)
		x--;
	if (map[(int)y][(int)x] == '1')
	{
		if (x == ray->x && ray->dx > 0)
			ray->hitside = 2;
		else if (x == ray->x - 1 && ray->dx < 0)
			ray->hitside = 3;
		else if (y == ray->y && ray->dy > 0)
			ray->hitside = 0;
		else
			ray->hitside = 1;
		return (1);
	}
	return (0);
}

/**
 * @brief 			Function to calculate the ray collision.
 * 
 * @param ray 		The ray to calculate.
 * @param px 		The position of the ray.
 * @param map 		The map to check.
 */
void	ft_ray_collision(t_ray *ray, double px, char **map)
{
	int		hit;
	double	xratio;
	double	yratio;

	xratio = fabs(ray->dy / ray->dx);
	yratio = fabs(ray->dx / ray->dy);
	hit = 0;
	while (!hit)
	{
		ray->yjump = ft_next_square(ray->x, ray->dx, xratio, ray->dy);
		ray->xjump = ft_next_square(ray->y, ray->dy, yratio, ray->dx);
		if (ft_intersection(ray, px))
		{
			ray->y += ray->yjump;
			ray->x = ft_move_to_line(ray->x, ray->dx);
			hit = ft_check_hit(ray, 1, map);
		}
		else
		{
			ray->x += ray->xjump;
			ray->y = ft_move_to_line(ray->y, ray->dy);
			hit = ft_check_hit(ray, 0, map);
		}
	}
}
