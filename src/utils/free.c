/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:00:42 by fealonso          #+#    #+#             */
/*   Updated: 2025/08/11 11:23:42 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void			free_config(t_config *c);
static void		free_str(char **p);
static void		free_map(char ***m);
void			free_lines(char ***arr);

void	free_config(t_config *c)
{
	if (!c)
		return ;
	free_str(&c->north_path);
	free_str(&c->south_path);
	free_str(&c->east_path);
	free_str(&c->west_path);
	free_map(&c->map);
}

static void	free_str(char **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

static void	free_map(char ***m)
{
	int	i;

	if (!m || !*m)
		return ;
	i = 0;
	while ((*m)[i])
	{
		free((*m)[i]);
		i++;
	}
	free(*m);
	*m = NULL;
}

void	free_lines(char ***arr)
{
	int	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}
