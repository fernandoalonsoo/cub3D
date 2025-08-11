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