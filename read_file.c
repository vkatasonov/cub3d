/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:12:37 by vkatason          #+#    #+#             */
/*   Updated: 2024/04/30 21:34:23 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 			Function to check file extension, 
 * 					and possibility to open file
 * 	
 * @param file 		The file to check
 * @return int 		The file descriptor
 * @note 			If file is NULL, cannot be opened or 
 * 					it has wrong file extension (not ".cub"), 
 * 					it will print an error message and exit the program.
 * @var filename 	Variable to store the file name
 * @var extension 	Variable to store the file extension
 * @var fd 			File descriptor 
 */
int	ft_check_and_open(char *file)
{
	char	*filename;
	char	*extension;
	int		fd;

	if (!file)
	{
		perror(RED "Error\nPlease include map (\".cub\" file)\n" RST);
		exit(EXIT_FAILURE);
	}
	filename = ft_strtrim(file, " ");
	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strcmp(extension, ".cub") != 0)
	{
		perror(RED "Error\nInvalid file extension \n" RST);
		exit(EXIT_FAILURE);
	}
	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
	{
		perror(RED "Error\nOpening file \n" RST);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * @brief 			Function to check if file is empty
 * 					It opens a file and reads it byte by byte
 * 					If it finds a non-whitespace character, 
 * 					it closes the file and returns
 * 					If it reaches the end of the file
 * 					and there are only whitespace characters, 
 * 					it prints an error message and exits the program.
 * 
 * @param file_name The file to check
 * @note 			If file is empty,
					it will print an error message and exit the program.
 * @var buffer 		Variable to store the buffer
 * @var fd 			File descriptor
 */
void	ft_empty_file(char *file_name)
{
	char	buffer[1];
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		perror(RED "Error\nOpening file \n" RST);
		exit(EXIT_FAILURE);
	}
	while (read(fd, buffer, sizeof(buffer)) > 0)
	{
		if (!ft_isspace(buffer[0]))
		{
			close(fd);
			return ;
		}
	}
	if (read(fd, buffer, sizeof(buffer)) == 0)
	{
		perror(RED "Error\nFile is empty \n" RST);
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

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
	//ft_get_and_check_dimension(data);
	//ft_check_map(data);
	close(fd);
}
