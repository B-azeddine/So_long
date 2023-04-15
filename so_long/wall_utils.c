/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 23:40:50 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/08 22:15:54 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(void)
{
	exit(0);
	return (0);
}

void	wall_lines(t_arg1 *a, t_vars *t)
{
	while (t->map[a->fline_y])
	{
		if ((ft_strlen(t->map[a->fline_y]) - 1) != a->s_fline_x)
		{
			free_map(t->map);
			ft_putstr("map invalid \n");
			exit(1);
		}
		else
			a->fline_y++;
	}
}

void	eyit(t_vars *t, int keycode, int *add)
{
	*add = 0;
	if (keycode == 0 && t->map[t->y_pl][t->x_pl - 1] != '1')
	{
		t->x_pl -= 1;
		*add = 1;
		t->direction = 0;
	}
	if (keycode == 1 && t->map[t->y_pl + 1][t->x_pl] != '1')
	{
		t->y_pl += 1;
		*add = 1;
	}
}

void	send_to_key_hook(t_vars *t, int keycode)
{
	int	add;

	add = 0;
	eyit(t, keycode, &add);
	if (keycode == 2 && t->map[t->y_pl][t->x_pl + 1] != '1')
	{
		t->x_pl += 1;
		add = 1;
		t->direction = 1 ;
	}
	if (keycode == 13 && t->map[t->y_pl - 1][t->x_pl] != '1')
	{
		t->y_pl -= 1;
		add = 1;
	}
	if (add)
	{
		t->move++;
		ft_putnbr(t->move);
		ft_putchar('\n');
	}
}

int	key_hook(int keycode, t_vars *t)
{	
	if (keycode == 53)
	{
		free_map(t->map);
		exit(0);
	}
	send_to_key_hook(t, keycode);
	if (t->map[t->y_pl][t->x_pl] == 'C')
	{
		t->count--;
		t->map[t->y_pl][t->x_pl] = '0';
	}
	if (t->x_pl == t->x && t->y_pl == t->y && t->count == 0)
	{
		free_map(t->map);
		exit(0);
	}
	return (0);
}
