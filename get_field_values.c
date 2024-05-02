/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_field_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:47:43 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/03 00:14:24 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 				Function to take path of the texture
 * 						passed as a parameter in the map
 * 						(the one that starts with NO, SO, WE, EA)
 * 
 * @param str 			Pointer to the string with texture path
 * @return char* 		Pointer to the string that contains the path
 */
char	*ft_get_field_path(char *str)
{
	char	*tmp;

	tmp = NULL;
	while (*str && *str != ' ')
		str++;
	str = ft_skip_spaces(str);
	tmp = ft_strtrim(str, "\t \n");
	return (tmp);
}
