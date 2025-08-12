/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:21:39 by fealonso          #+#    #+#             */
/*   Updated: 2025/08/12 16:53:03 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int			validate_map(t_config *cfg);
static int	is_valid_char(char c);
static int	validate_row(t_config *cfg, int x, int y, int *player_count);
static int	check_player(t_config *cfg, int x, int y);
static int	is_closed(t_config *cfg, int x, int y);

int	validate_map(t_config *cfg)
{
	int	x;
	int	y;
	int	player_count;

	player_count = 0;
	y = 0;
	while (y < cfg->map_height)
	{
		x = 0;
		while (cfg->map[y][x])
		{
			if (validate_row(cfg, x, y, &player_count))
				return (1);
			x++;
		}
		y++;
	}
	if (player_count != 1)
		return (1);
	return (0);
}

static int	validate_row(t_config *cfg, int x, int y, int *player_count)
{
	if (!is_valid_char(cfg->map[y][x]))
	{
		if (cfg -> map[y][x] == '\n')
			return (0);
		return (1);
	}
	if (ft_strchr("NSEW", cfg->map[y][x]))
		*player_count += check_player(cfg, x, y);
	if (cfg->map[y][x] == '0' || ft_strchr("NSEW", cfg->map[y][x]))
		if (!is_closed(cfg, x, y))
			return (1);
	return (0);
}

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' '
		|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	check_player(t_config *cfg, int x, int y)
{
	cfg->player_x = x;
	cfg->player_y = y;
	cfg->player_dir = cfg->map[y][x];
	return (1);
}

static int	is_closed(t_config *cfg, int x, int y)
{
	if (y == 0 || x == 0 || y == cfg->map_height - 1 || x >= cfg->map_width - 1)
		return (0);
	if (cfg->map[y - 1][x] == ' ' || cfg->map[y + 1][x] == ' ' ||
		cfg->map[y][x - 1] == ' ' || cfg->map[y][x + 1] == ' ')
		return (0);
	return (1);
}
