/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:59:49 by fealonso          #+#    #+#             */
/*   Updated: 2025/08/11 10:14:55 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	exit_error(t_config *cfg, const char *msg);

int	exit_error(t_config *cfg, const char *msg)
{
	write(2, "Error\n", 6);
	if (msg)
		write(2, msg, (int)strlen(msg));
	write(2, "\n", 1);
	if (cfg)
		free_config(cfg);
	return (1);
}
