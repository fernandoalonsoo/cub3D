/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:44:15 by fealonso          #+#    #+#             */
/*   Updated: 2025/08/11 11:25:51 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>


typedef struct s_config
{
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;
	int		floor_color;
	int		ceiling_color;
	char	**map;
	int		map_width;
	int		map_height;
	double	player_x;
	double	player_y;
	char	player_dir;
}	t_config;

/***********************************************
				BORRAR
************************************************/

void	print_lines(char **lines);

/***********************************************
				INITIALIZE
************************************************/

int		is_cub_file(const char *s);
void	init_config(t_config *c);

/***********************************************
				  ERRORS
************************************************/

int		exit_error(t_config *cfg, const char *msg);

/***********************************************
					FREE
************************************************/

void	free_config(t_config *c);
void	free_lines(char ***arr);

/***********************************************
				 PARSER
************************************************/

int		parse_cub(const char *path, t_config *cfg);
int		read_cub_file(const char *path, char ***lines);
int		parse_config_line(char *line, t_config *cfg);
int		parse_map(char **lines, int start_index, t_config *cfg);
int		validate_map(t_config *cfg);

/***********************************************
				 GET NEXT LINE 
************************************************/

char	*get_next_line(int fd);

# endif