/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:35:47 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/10 05:26:05 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	send_put_items(t_arg1 *a, t_vars *t)
{
	if (t->map[a->i][a->j] == 'P')
	{
		t->x_pl = a->j;
		t->y_pl = a->i;
	}
	else if (t->map[a->i][a->j] == 'C')
		t->count++;
	else if (t->map[a->i][a->j] == 'E')
	{
		t->x = a->j;
		t->y = a->i;
	}
	else if (t->map[a->i][a->j] != '1' && t->map[a->i][a->j] != '0')
	{
		ft_putstr("invalid caracter !\n");
		free(t->map);
		exit(1);
	}
}

void	put_items(t_arg1 *a, t_vars *t)
{
	a->i = 0;
	while (t->map[a->i])
	{
		a->j = 0;
		while (t->map[a->i][a->j])
		{
			send_put_items(a, t);
			a->j++;
		}
		a->i++;
	}
}

void	check_line_length(t_arg1 *a, t_vars *t)
{
	a->fline_x = 0;
	a->fline_y = 0;
	while (t->map[0][a->fline_x])
	{
		if (t->map[0][a->fline_x] != '1'
			|| t->map[a->s_fline_y][a->fline_x] != '1')
		{
			free_map(t->map);
			ft_putstr("invalid wall !\n");
			exit(1);
		}
		a->fline_x++;
	}
	while (a->fline_y <= a->s_fline_y)
	{
		if (t->map[a->fline_y][0] != '1'
			|| t->map[a->fline_y][a->s_fline_x] != '1' )
		{
			free_map(t->map);
			ft_putstr("invalid wall !\n");
			exit(1);
		}
		a->fline_y++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	wall_screen(t_arg1 *a, t_vars *t)
{
	if ((a->s_fline_x) >= 29 || (a->s_fline_y) >= 16)
	{
		free_map(t->map);
		ft_putstr("map invalid !\n");
		exit(1);
	}
	if (!check_uniq_items(t->map, t->x_map, t->y_map))
	{
		free_map(t->map);
		ft_putstr("double exit/player or 0 coins on map !\n");
		exit(1);
	}
}
