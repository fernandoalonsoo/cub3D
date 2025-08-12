/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:20:20 by fealonso          #+#    #+#             */
/*   Updated: 2025/08/12 11:48:11 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		config_complete(const t_config *cfg);
int		is_empty_line(const char *s);
char	*skip_blank(char *s);
int		is_config_prefix(const char *s);

int	config_complete(const t_config *cfg)
{
	if (!cfg->north_path || !cfg->south_path)
		return (0);
	if (!cfg->east_path || !cfg->west_path)
		return (0);
	if (cfg->floor_color < 0 || cfg->ceiling_color < 0)
		return (0);
	return (1);
}

int	is_empty_line(const char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r'
		|| s[i] == '\v' || s[i] == '\f')
		i++;
	return (s[i] == 0 || s[i] == '\n');
}

char	*skip_blank(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return (s + i);
}

int	is_config_prefix(const char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	if (!ft_strncmp(s, "NO", 2) && (s[2] == ' '
			|| s[2] == '\t' || s[2] == 0 || s[2] == '\n'))
		return (1);
	if (!ft_strncmp(s, "SO", 2) && (s[2] == ' '
			|| s[2] == '\t' || s[2] == 0 || s[2] == '\n'))
		return (1);
	if (!ft_strncmp(s, "WE", 2) && (s[2] == ' '
			|| s[2] == '\t' || s[2] == 0 || s[2] == '\n'))
		return (1);
	if (!ft_strncmp(s, "EA", 2) && (s[2] == ' '
			|| s[2] == '\t' || s[2] == 0 || s[2] == '\n'))
		return (1);
	if (*s == 'F' && (s[1] == ' ' || s[1] == '\t' || s[1] == 0 || s[1] == '\n'))
		return (1);
	if (*s == 'C' && (s[1] == ' ' || s[1] == '\t' || s[1] == 0 || s[1] == '\n'))
		return (1);
	return (0);
}
