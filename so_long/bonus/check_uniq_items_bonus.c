/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_uniq_items_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:45:43 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/08 22:45:00 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialisation(t_arg	*ag)
{
	ag->i = 0;
	ag->i = 0;
	ag->exit = 0;
	ag->player = 0;
	ag->count = 0;
}

void	send_to_cui(char **map, t_arg *ag)
{
	if (map[ag->i][ag->j] == 'P')
		ag->player++;
	if (map[ag->i][ag->j] == 'E')
		ag->exit++;
	if (map[ag->i][ag->j] == 'C')
		ag->count++;
}

int	check_uniq_items(char	**map, int x_map, int y_map)
{
	t_arg	ag;
	char	**test_map;

	initialisation(&ag);
	test_map = malloc(sizeof(char *) * (y_map + 1));
	while (map[ag.i])
	{
		test_map[ag.i] = malloc(x_map + 1);
		ag.j = -1;
		while (map[ag.i][++ag.j])
		{
			test_map[ag.i][ag.j] = map[ag.i][ag.j];
			send_to_cui(map, &ag);
		}
		test_map[ag.i][ag.j] = 0;
		ag.i++;
	}
	test_map[ag.i] = 0;
	check_valid_map(test_map);
	if (ag.player != 1 || ag.exit != 1 || ag.count < 1)
		return (0);
	return (1);
}
