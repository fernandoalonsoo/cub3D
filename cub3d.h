/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:44:15 by fealonso          #+#    #+#             */
/*   Updated: 2025/08/12 17:02:18 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include "get_next_line/src/get_next_line.h"
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
void	print_config_debug(const t_config *cfg);

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
				STR NUM UTILS
************************************************/

void	ft_strtrim_newline(char *s);
int		ft_numlen(int n);

/***********************************************
				 PARSER
************************************************/

int		parse_cub(const char *path, t_config *cfg);
int		read_cub_file(const char *path, char ***lines);
int		parse_config_line(char *line, t_config *cfg);
int		parse_map(char **lines, int start_index, t_config *cfg);
int		validate_map(t_config *cfg);

/***********************************************
				 PARSER UTILS
************************************************/

int		config_complete(const t_config *cfg);
int		is_empty_line(const char *s);
char	*skip_blank(char *s);
int		is_config_prefix(const char *s);

/***********************************************
				 GET NEXT LINE 
************************************************/

char	*get_next_line(int fd);

#endif