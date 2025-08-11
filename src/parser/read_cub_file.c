/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:50:16 by fealonso          #+#    #+#             */
/*   Updated: 2025/08/11 11:24:02 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int			read_cub_file(const char *path, char ***lines);
static int	add_line(char ***dst, int *count, char *line);

int	read_cub_file(const char *path, char ***lines)
{
	char	*line;
	int		fd;
	int		n;

	*lines = NULL;
	n = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (add_line(lines, &n, line))
		{
			close(fd);
			return (1);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (n == 0);
}

static int	add_line(char ***dst, int *count, char *line)
{
	char	**new_arr;
	int		i;

	new_arr = (char **)malloc(sizeof(char *) * (*count + 2));
	if (!new_arr)
		return (free(line), 1);
	i = 0;
	while (i < *count)
	{
		new_arr[i] = (*dst)[i];
		i++;
	}
	new_arr[i++] = line;
	new_arr[i] = NULL;
	if (*dst)
		free(*dst);
	*dst = new_arr;
	*count += 1;
	return (0);
}
