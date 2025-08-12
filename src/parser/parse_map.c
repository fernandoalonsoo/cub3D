/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:06:13 by fealonso          #+#    #+#             */
/*   Updated: 2025/08/12 16:56:06 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int			parse_map(char **lines, int map_start, t_config *cfg);
static int	alloc_map(char **lines, int map_start, t_config *cfg, int *count);
static int	fill_map(char **lines, int map_start, t_config *cfg, int count);

int	parse_map(char **lines, int map_start, t_config *cfg)
{
	int	count;

	if (alloc_map(lines, map_start, cfg, &count))
		return (1);
	if (fill_map(lines, map_start, cfg, count))
		return (1);
	return (0);
}

static int	alloc_map(char **lines, int map_start, t_config *cfg, int *count)
{
	int	i;

	*count = 0;
	i = map_start;
	while (lines[i])
	{
		(*count)++;
		i++;
	}
	if (*count == 0)
		return (1);
	cfg->map = (char **)malloc(sizeof(char *) * (*count + 1));
	if (!cfg->map)
		return (1);
	return (0);
}

static int	fill_map(char **lines, int map_start, t_config *cfg, int count)
{
	int	i;
	int	len;

	cfg->map_width = 0;
	i = 0;
	while (i < count)
	{
		cfg->map[i] = ft_strdup(lines[map_start + i]);
		if (!cfg->map[i])
			return (free_lines(&cfg->map), 1);
		len = ft_strlen(cfg->map[i]);
		if (len > 0 && cfg->map[i][len - 1] == '\n')
			len--;
		if (len > cfg->map_width)
			cfg->map_width = len;
		i++;
	}
	cfg->map[i] = NULL;
	cfg->map_height = count;
	return (0);
}
