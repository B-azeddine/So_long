/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:59:53 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/10 05:07:46 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extention(char *map_name)
{
	int		ext;

	ext = ft_strlen (map_name) - 4;
	if (ext < 0 || ft_strncmp(map_name + ext, ".ber", 5))
	{
		ft_putstr ("invalid extention\n");
		exit(1);
	}
}

void	send_t_rf(t_readf *rf)
{
	while (rf->line)
	{
		if (ft_strlen(rf->line) == 1)
		{
			free(rf->line);
			free(rf->f);
			ft_putstr("invalid map , extra empty lines !\n");
			exit(1);
		}
		rf->f = ft_strjoin(rf->f, rf->line);
		free(rf->line);
		rf->line = get_next_line(rf->fd);
	}
}

char	**read_file_1(char *map_name)
{
	t_readf	rf;

	check_extention(map_name);
	rf.fd = open(map_name, O_RDONLY);
	if (rf.fd < 0)
	{
		ft_putstr("file not exist\n");
		exit(1);
	}
	rf.line = get_next_line(rf.fd);
	rf.f = ft_strdup("");
	if (rf.line != NULL)
	{
		send_t_rf(&rf);
		rf.bointer = ft_split(rf.f, '\n');
	}
	else
		rf.bointer = NULL;
	free(rf.f);
	return (rf.bointer);
}
