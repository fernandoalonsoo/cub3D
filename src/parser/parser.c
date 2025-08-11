/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:11:04 by fealonso          #+#    #+#             */
/*   Updated: 2025/08/11 11:33:10 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int			parse_cub(const char *path, t_config *cfg);

int	parse_cub(const char *path, t_config *cfg)
{
	char	**lines;

	(void) cfg;
	lines = NULL;
	if (read_cub_file(path, &lines) != 0)
		return (1);
	print_lines(lines);

	return (0);
}
