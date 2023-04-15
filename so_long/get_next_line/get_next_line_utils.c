/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:55:37 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/04 17:30:26 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	x;

	x = 0;
	if (!s)
		return (0);
	while (s[x])
		x++;
	return (x);
}

char	*ft_strnchr(char *str, char c)
{
	int	x;

	x = 0;
	if (!str)
		return (0);
	while (str[x] != 0)
	{
		if (str[x] == c)
			return (str + x);
		x++;
	}
	return (0);
}

char	*ft_strjoin(char *save, char *buf)
{
	int		x;
	int		y;
	char	*line;

	x = 0;
	y = 0;
	line = malloc(ft_strlen(save) + ft_strlen(buf) + 1);
	if (!line)
		return (0);
	if (save)
	{
		while (save[x])
		{
			line[x] = save[x];
			x++;
		}
	}
	while (buf[y])
		line[x++] = buf[y++];
	line[x] = 0;
	if (save)
		free(save);
	return (line);
}

char	*ft_nwline(char *save)
{
	int		x;
	char	*nwline;

	x = 0;
	while (save[x] != '\n' && save[x])
		x++;
	if (save[x] == '\n')
		x++;
	nwline = malloc(x + 1);
	x = 0;
	while (save[x] != '\n' && save[x])
	{
		nwline[x] = save[x];
		x++;
	}
	if (save[x] == '\n')
	{
		nwline[x] = '\n';
		x++;
	}
	nwline[x] = 0;
	return (nwline);
}

char	*ft_cutnwline(char *save)
{
	int		x;
	int		y;
	char	*cutnwline;

	x = 0;
	y = 0;
	while (save[x] != '\n' && save[x])
		x++;
	if (save[x] == '\n')
		x++;
	cutnwline = malloc((ft_strlen(save) - x) + 1);
	while (save[x])
		cutnwline[y++] = save[x++];
	cutnwline[y] = 0;
	free(save);
	return (cutnwline);
}
