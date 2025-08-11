/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:01:06 by fealonso          #+#    #+#             */
/*   Updated: 2025/08/11 10:32:12 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		is_cub_file(const char *s);
void	init_config(t_config *c);

int	is_cub_file(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	if (i < 4)
		return (0);
	return (s[i - 4] == '.' && s[i - 3] == 'c'
		&& s[i - 2] == 'u' && s[i - 1] == 'b');
}

void	init_config(t_config *c)
{
	c->north_path = NULL;
	c->south_path = NULL;
	c->east_path = NULL;
	c->west_path = NULL;
	c->floor_color = -1;
	c->ceiling_color = -1;
	c->map = NULL;
	c->map_width = 0;
	c->map_height = 0;
	c->player_x = -1;
	c->player_y = -1;
	c->player_dir = 0;
}
