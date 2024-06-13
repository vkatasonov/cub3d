/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:56:46 by lromero-          #+#    #+#             */
/*   Updated: 2024/06/13 15:31:31 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 			Function to calculate the distance
 * 					between two points.
 * 
 * @param x1 		The x position of the first point.
 * @param y1 		The y position of the first point.
 * @param x2 		The x position of the second point.
 * @param y2 		The y position of the second point.
 * @return double 	The distance between the two points.
 */
void	ft_turn_angle(double angle, double *xvector, double *yvector)
{
	double	tcos;
	double	tsin;
	double	tmp;

	if (!angle)
		return ;
	tcos = cos(angle);
	tsin = sin(angle);
	tmp = *xvector;
	*xvector = *xvector * tcos - *yvector * tsin;
	*yvector = *yvector * tcos + tmp * tsin;
	tmp = sqrt(*xvector * *xvector + *yvector * *yvector);
	*xvector /= tmp;
	*yvector /= tmp;
}

/**
 * @brief 			Helps to calculate to take 
 * 					the RGBA values
 * 					and return the color.
 */
int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
