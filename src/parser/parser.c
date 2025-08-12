/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:11:04 by fealonso          #+#    #+#             */
/*   Updated: 2025/08/12 17:01:34 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int			parse_cub(const char *path, t_config *cfg);
static int	config_lines(char **lines, t_config *cfg, int *map_start);

int	parse_cub(const char *path, t_config *cfg)
{
	char	**lines;
	int		map_start;

	lines = NULL;
	if (read_cub_file(path, &lines) != 0)
		return (1);
	if (config_lines(lines, cfg, &map_start) != 0)
		return (free_lines(&lines), 1);
	if (parse_map(lines, map_start, cfg) != 0)
		return (free_lines(&lines), 1);
	free_lines(&lines);
	if (validate_map(cfg) != 0)
		return (1);
	return (0);
}

static int	config_lines(char **lines, t_config *cfg, int *map_start)
{
	int		i;
	char	*s;

	i = -1;
	*map_start = -1;
	while (lines[++i])
	{
		if (is_empty_line(lines[i]))
			continue ;
		s = skip_blank(lines[i]);
		if (is_config_prefix(s))
		{
			if (parse_config_line(lines[i], cfg) != 0)
				return (1);
			continue ;
		}
		*map_start = i;
		break ;
	}
	if (*map_start == -1)
		return (1);
	if (!config_complete(cfg))
		return (1);
	return (0);
}
