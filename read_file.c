/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:12:37 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/30 19:05:26 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 				Rewritten ft_strjoin function to 
 * 						join two strings. Used to copy the
 * 						content of the file to the data->content.
 * 
 * @param s1 			First string		
 * @param s2 			Second string
 * @return char* 		Pointer to the joined string
 * 
 * @attention 			`ft_calloc` is used to allocate memory
 * 						for the joined string and `free` to
 * 						clean the first string. 
 */
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

/**
 * @brief 				Function to check if the file exists
 * 						and open it. If the file does not exist
 * 						the program will exit with an error.
 * 						Function reads `.cub` file and saves its
 * 						content to the data->content array.
 *
 * @param file_name 	Name of the file to read from
 * @param data 			Pointer to the main data struct
 */
void	ft_read_file(char *file_name, t_data *data)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = ft_check_and_open(file_name);
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
	ft_extract_data(data);
	ft_print_extracted(data);
	close(fd);
}

/**
 * @brief 				Function to print the content read
 * 						from `.cub` file and extracted 
 * 						in to the data structure. 
 * 	
 * @param data 			Pointer to the main data struct
 */
void	ft_print_extracted(t_data *data)
{
	ft_print_fields(data);
	ft_print_colors(data);
	ft_printf(GREEN"\nTextures are loaded\n"RST);
	ft_print_map(data);
	ft_print_position(data);
}
