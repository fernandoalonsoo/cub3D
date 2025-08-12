/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:57:53 by fealonso          #+#    #+#             */
/*   Updated: 2025/08/12 16:39:31 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_strtrim_newline(char *s);
int		ft_numlen(int n);

void	ft_strtrim_newline(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	if (i == 0)
		return ;
	i--;
	while (i >= 0 && (s[i] == '\n' || s[i] == '\r'
			|| s[i] == ' ' || s[i] == '\t'))
	{
		s[i] = '\0';
		i--;
	}
}

int	ft_numlen(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		if (n == -2147483648)
			return (len + 10);
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
