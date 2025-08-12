/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 09:55:08 by fealonso          #+#    #+#             */
/*   Updated: 2025/08/12 17:01:02 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_config	cfg;

	if (argc != 2)
		return (exit_error(NULL, "Usage: ./cub3D <map.cub>"));
	if (!is_cub_file(argv[1]))
		return (exit_error(NULL, "Invalid extension (expected .cub)"));
	init_config(&cfg);
	if (parse_cub(argv[1], &cfg) != 0)
		return (exit_error(&cfg, "Invalid .cub file"));
	/* print_lines(lines); 		// DEBUG: QUITARRRRR en la entrega */
	/* print_config_debug(cfg); // DEBUG: QUITARRRRR en la entrega */
	/* RENDERIZADO: init_mlx(&cfg) ANDRESITO <3 */
	free_config(&cfg);
	return (0);
}
