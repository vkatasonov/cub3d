/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromero- <lromero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:56:46 by lromero-          #+#    #+#             */
/*   Updated: 2024/06/06 20:58:49 by lromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_turn_angle(double angle, double *xvector, double *yvector)
{
	double	tcos;
	double	tsin;
	double	tmp;

	if(!angle)
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

int ft_get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
