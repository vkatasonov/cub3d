/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_field_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:47:43 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/03 19:33:53 by vkatason         ###   ########.fr       */
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

int	ft_fill_field_path(t_data *data, char *str, int i)
{
	if (!data->no && i == 1)
	{
		data->no = ft_get_field_path(str);
		return (0);
	}
	else if (!data->so && i == 2)
	{
		data->so = ft_get_field_path(str);
		return (0);
	}
	else if (!data->we && i == 3)
	{
		data->we = ft_get_field_path(str);
		return (0);
	}
	else if (!data->ea && i == 4)
	{
		data->ea = ft_get_field_path(str);
		return (0);
	}
	return (1);
}

int	ft_fill_colors(t_data *data, char *str, int i)
{
	char	**colour;
	int		*tmp;

	tmp = NULL;
	if (i == 6)
		tmp = &data->f[0];
	if (i == 7)
		tmp = &data->c[0];
	str++;
	colour = ft_split(str, ',');
	if (tmp[0] == 0)
	{
		tmp[0] = 1;
		tmp[1] = ft_atoi(colour[0]);
		tmp[2] = ft_atoi(colour[1]);
		tmp[3] = ft_atoi(colour[2]);
		if ((colour && colour[3] != 0) || (tmp[1] > 255 || tmp[2] > 255
				|| tmp[3] > 255 || tmp[1] < 0 || tmp[2] < 0 || tmp[3] < 0))
			return (ft_printf_fd(STDERR_FILENO, "Invalid colour found\n"));
	}
	else
		return (ft_printf_fd(STDERR_FILENO, "Duplicate colour found\n"));
	ft_charpp_free(colour);
	return (1);
}
