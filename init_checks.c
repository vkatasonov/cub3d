/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:20:25 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/03 20:19:07 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief 			Function to check if the number 
 * 					of arguments is correct. 
 * 					according to the subject, programm 
 * 					should have not more that two arguments.
 * 
 * @param n			The number of arguments
 */
void	ft_check_argc(int n)
{
	if (n < 2)
	{
		ft_printf_fd(STDERR_FILENO, RED "No file name provided.\n" RST);
		ft_printf_fd(STDERR_FILENO,
			YELLOW "Correct usage:" RST);
		ft_printf_fd(STDERR_FILENO,
			" ./cub3D <map.cub>\n");
		exit(1);
	}
	if (n != 2)
	{
		ft_printf_fd(STDERR_FILENO,
			RED "Error\nInvalid number of arguments\n" RST);
		ft_printf_fd(STDERR_FILENO,
			YELLOW "Correct usage:" RST);
		ft_printf_fd(STDERR_FILENO,
			" ./cub3D <map.cub>\n");
		exit(1);
	}
	return ;
}

/**
 * @brief 			Function to check if file is empty
 * 					It opens a file and reads it byte by byte
 * 					If it finds a non-whitespace character, 
 * 					it closes the file and returns.
 * 					If it reaches the end of the file
 * 					and there are only whitespace characters, 
 * 					it prints an error message and exits the program.
 * 
 * @param file_name The file to check
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
		ft_printf_fd(STDERR_FILENO, RED "Error\nOpening file \n" RST);
		ft_printf_fd(STDERR_FILENO,
			YELLOW "File provided:" RST);
		ft_printf_fd(STDERR_FILENO, " %s\n", file_name);
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
	ft_printf_fd(STDERR_FILENO, RED "Error\nFile is empty \n" RST);
	close(fd);
	exit(EXIT_FAILURE);
}

/**
 * @brief				Helper function for ft_check_and_open
 * 						which checks if the file is a directory
 * 						and prints an error message if it is.	
 * 
 * @param filename		The file to check
 * @var buffer 			Variable to store the buffer
 * @var fd 				File descriptor
 */
void	ft_check_dir(char *filename)
{
	char	buffer[1];
	int		fd;

	fd = open(filename, O_RDONLY, 0);
	if (read(fd, buffer, sizeof(buffer)) < 0)
	{
		if (errno == EISDIR)
		{
			ft_printf_fd(STDERR_FILENO,
				RED "Error\nCannot open directory\n" RST);
			ft_printf_fd(STDERR_FILENO,
				YELLOW "File provided:" RST);
			ft_printf_fd(STDERR_FILENO, " %s\n", filename);
			close(fd);
			exit(EXIT_FAILURE);
		}
	}
	close(fd);
	return ;
}

/**
 * @brief 			Function to check file extension, 
 * 					and possibility to open file
 * 	
 * @param file 		The file to check
 * @return int 		The file descriptor
 * @note 			If cannot be opened or 
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

	filename = ft_strtrim(file, " ");
	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strcmp(extension, ".cub") != 0)
	{
		ft_printf_fd(STDERR_FILENO, RED "Error\nInvalid file extension \n" RST);
		ft_printf_fd(STDERR_FILENO, YELLOW "Correct usage:" RST);
		ft_printf_fd(STDERR_FILENO, " ./cub3D <map.cub>\n");
		free(filename);
		exit(EXIT_FAILURE);
	}
	free(filename);
	fd = open(file, O_RDONLY, 0);
	ft_check_dir(file);
	ft_empty_file(file);
	return (fd);
}
