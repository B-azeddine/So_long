/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:29:23 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/07 21:46:31 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_full(int fd, char *save, int *x)
{
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strnchr(save, '\n'))
	{
		*x = read(fd, buf, BUFFER_SIZE);
		if (*x <= 0)
			break ;
		buf[*x] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	int			x;

	x = 0;
	if (BUFFER_SIZE <= 0 || fd == 1 || fd == 2 || fd < 0)
	{
		if (save)
			free(save);
		return (NULL);
	}
	save = ft_read_full(fd, save, &x);
	if (ft_strlen(save) > 0 && x >= 0)
	{
		buf = ft_nwline(save);
		save = ft_cutnwline(save);
		return (buf);
	}
	free(save);
	save = 0;
	return (0);
}
