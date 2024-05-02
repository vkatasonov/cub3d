/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:12:37 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/02 22:25:26 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_lines_join(char *s1, char *s2)
{
	char	*joined;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	joined = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!joined)
		return (NULL);
	i = -1;
	j = -1;
	if (s1)
	{
		while (s1[++i])
			joined[i] = s1[i];
		free(s1);
	}
	while (s2[++j])
		joined[i++] = s2[j];
	return (joined);
}

void	ft_read_file(char *file_name, t_data *data)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = ft_check_and_open(file_name);
	ft_empty_file(file_name);
	tmp = ft_calloc(sizeof(char), 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_lines_join(tmp, line);
		free(line);
	}
	data->content = ft_split(tmp, '\n');
	free(tmp);
	//ft_get_data(data);
	close(fd);
}
