#include "../../cub3d.h"

void	print_lines(char **lines)
{
	int	i;

	if (!lines)
	{
		printf("(no hay líneas)\n");
		return ;
	}
	i = 0;
	while (lines[i])
	{
		printf("[%d] %s", i, lines[i]);
		i++;
	}
}

void	print_config_debug(const t_config *cfg)
{
	printf("=== CONFIG DEBUG ===\n");

	// Texturas
	printf("NO: %s\n", cfg->north_path ? cfg->north_path : "(null)");
	printf("SO: %s\n", cfg->south_path ? cfg->south_path : "(null)");
	printf("WE: %s\n", cfg->west_path ? cfg->west_path : "(null)");
	printf("EA: %s\n", cfg->east_path ? cfg->east_path : "(null)");

	// Colores (dec y hex)
	printf("F: %d (0x%06X)\n", cfg->floor_color, cfg->floor_color);
	printf("C: %d (0x%06X)\n", cfg->ceiling_color, cfg->ceiling_color);

	// Validación
	printf("Config completa: %s\n", config_complete(cfg) ? "SI" : "NO");

	// Mapa (si existe)
	if (cfg->map && cfg->map_height > 0)
	{
		printf("--- MAPA (%dx%d) ---\n", cfg->map_height, cfg->map_width);
		for (int y = 0; y < cfg->map_height; y++)
			printf("[%d] \t %s", y, cfg->map[y]);
	}
	else
		printf("(No hay mapa)\n");

	printf("====================\n");
}
