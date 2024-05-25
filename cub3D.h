/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:47:37 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/16 18:49:37 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

/*
** ASCII colors escape sequences for printf
** Usage:
**      ft_printf(RED "Red bold text" RST);
**		ft_printf(B "Bold text goes here" RST);
*/
# define RST "\033[0m"        /* Reset to default color */
# define BU "\033[1;4;0m"     /* Bold and underlined text*/
# define B "\033[1m"          /* Bold text default color */
# define U "\033[4m"          /* Underlined text default color */
# define RED "\033[1;31m"     /* Bold Red*/
# define GREEN "\033[1;32m"   /* Bold Green */
# define YELLOW "\033[1;33m"  /* Bold Yellow */
# define BLUE "\033[1;34m"    /* Bold Blue */
# define MAGENTA "\033[1;35m" /* Bold Magenta */
# define CYAN "\033[1;36m"    /* Bold Cyan */
# define WHITE "\033[1;37m"   /* Bold White */

/**
 * @param px 		corresponds to player position on the x axis
 * @param py 		corresponds to player position on the y axis
 * @example 		(0,0) corresponds to the upper-left corner of the map
 * @param dir 		holds the direction the player is facing (y, x)
 * @example 		North:	[-1, 0]
 * 					South:	[1, 0]
 * 					East:	[0, 1]
 * 					West:	[0, -1]
*/

typedef struct s_scr
{
	void			*mlx;
	void			*win;
	mlx_image_t		*img[4];
	mlx_texture_t	*texture[4];
}					t_scr;

typedef struct s_data
{
	char			**content;
	char			**map;
	char			**mapcopy;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	double			px;
	double			py;
	double			dir[2];
	int				f[4];
	int				c[4];
	int				map_height;
	t_scr			*scr;
}					t_data;

/***** FUNCTIONS *****/

void	ft_check_argc(int n);
void	ft_read_file(char *file_name, t_data *data);
int		ft_check_and_open(char *file);
void	ft_check_dir(char *filename);
void	ft_empty_file(char *file_name);
char	*ft_lines_join(char *s1, char *s2);
void	ft_extract_data(t_data *data);
void	ft_extract_path(t_data *data);
int		ft_check_path(t_data *data, char *tmp);
int		ft_set_path(t_data *data, char *tmp, int i);
char	*ft_get_path_value(char *tmp);
void	ft_path_not_found(t_data *data);
void	ft_extract_color(t_data *data);
int		ft_find_color(t_data *data, char *tmp);
int		ft_set_color(t_data *data, char *tmp, int i);
int		ft_get_color_values(int *value, char **color, char *tmp);
void	ft_color_not_found(t_data *data);
void	ft_check_textures(t_data *data);
void	ft_extract_map(t_data *data);
int		ft_map_height(t_data *data);
void	ft_not_tab(t_data *data);
void	ft_not_valid_char(t_data *data);
void	ft_check_map(t_data *data);
void	ft_copy_map(t_data *data);
void	ft_get_player_position(t_data *data);
void	ft_check_player_direction(t_data *data, char c);

/***** PRINTING FUNCTIONS *****/

void	ft_print_data_content(t_data *data);
void	ft_print_fields(t_data *data);
void	ft_print_colors(t_data *data);
void	ft_print_map(t_data *data);
void	ft_print_position(t_data *data);

/***** CLEANUP FUNCTIONS *****/

void	ft_free_data(t_data *data);
void	ft_clean_scr(t_data *data);
void	ft_destroy_images(t_data *data);
void	ft_destroy_textures(t_data *data);

#endif