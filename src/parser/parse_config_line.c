/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:12:20 by fealonso          #+#    #+#             */
/*   Updated: 2025/08/12 16:51:58 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	has_space(const char *s, int id_len);
static int	set_texture(char **slot, char *after_id);
static int	parse_rgb(char *s, int *out);
static int	read_num(char **ps, int *val);

int	parse_config_line(char *line, t_config *cfg)
{
	char	*s;
	int		color;

	s = skip_blank(line);
	if (!ft_strncmp(s, "NO", 2) && has_space(s, 2))
		return (set_texture(&cfg->north_path, s + 2));
	if (!ft_strncmp(s, "SO", 2) && has_space(s, 2))
		return (set_texture(&cfg->south_path, s + 2));
	if (!ft_strncmp(s, "WE", 2) && has_space(s, 2))
		return (set_texture(&cfg->west_path, s + 2));
	if (!ft_strncmp(s, "EA", 2) && has_space(s, 2))
		return (set_texture(&cfg->east_path, s + 2));
	if ((*s == 'F' && has_space(s, 1) && cfg->floor_color < 0
			&& !parse_rgb(s + 1, &color)) || (*s == 'C' && has_space(s, 1)
			&& cfg->ceiling_color < 0 && !parse_rgb(s + 1, &color)))
	{
		if (*s == 'F')
			cfg->floor_color = color;
		else
			cfg->ceiling_color = color;
		return (0);
	}
	return (1);
}

static int	has_space(const char *s, int id_len)
{
	char	c;

	c = s[id_len];
	return (c == ' ' || c == '\t' || c == 0 || c == '\n');
}

static int	set_texture(char **slot, char *after_id)
{
	char	*path;

	if (*slot)
		return (1);
	path = ft_strdup(skip_blank(after_id));
	if (!path || *path == '\0' || *path == '\n')
		return (free(path), 1);
	ft_strtrim_newline(path);
	*slot = path;
	return (0);
}

static int	parse_rgb(char *s, int *out)
{
	int		r;
	int		g;
	int		b;

	if (read_num(&s, &r))
		return (1);
	s = skip_blank(s);
	if (*s != ',')
		return (1);
	s++;
	if (read_num(&s, &g))
		return (1);
	s = skip_blank(s);
	if (*s != ',')
		return (1);
	s++;
	if (read_num(&s, &b))
		return (1);
	s = skip_blank(s);
	if (*s && *s != '\n')
		return (1);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (1);
	*out = (r << 16) | (g << 8) | b;
	return (0);
}

static int	read_num(char **ps, int *val)
{
	char	*s;

	s = skip_blank(*ps);
	if (!ft_isdigit((unsigned char)*s))
		return (1);
	*val = ft_atoi(s);
	while (*s && ft_isdigit((unsigned char)*s))
		s++;
	*ps = s;
	return (0);
}
