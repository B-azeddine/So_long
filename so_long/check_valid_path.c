/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:18:01 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/08 21:06:10 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sml_fct(char **map, t_arg2 *arg2, int ac)
{
	arg2->changed = 1;
	if (ac == 1)
		map[arg2->i][arg2->j + 1] = 'P';
	if (ac == 2)
		map[arg2->i][arg2->j - 1] = 'P';
	if (ac == 3)
		map[arg2->i + 1][arg2->j] = 'P';
	if (ac == 4)
		map[arg2->i - 1][arg2->j] = 'P';
}

void	chek_mouvement_far(char **map, t_arg2 *arg2)
{
	while (map[arg2->i])
	{
		arg2->j = 0;
		while (map[arg2->i][arg2->j])
		{
			if (map[arg2->i][arg2->j] == 'P')
			{
				if (map[arg2->i][arg2->j + 1] != 'P'
					&& map[arg2->i][arg2->j + 1] != '1')
					sml_fct(map, arg2, 1);
				if (map[arg2->i][arg2->j - 1] != 'P'
					&& map[arg2->i][arg2->j - 1] != '1')
					sml_fct(map, arg2, 2);
				if (map[arg2->i + 1][arg2->j] != 'P'
					&& map[arg2->i + 1][arg2->j] != '1')
					sml_fct(map, arg2, 3);
				if (map[arg2->i - 1][arg2->j] != 'P'
					&& map[arg2->i - 1][arg2->j] != '1')
					sml_fct(map, arg2, 4);
			}
			arg2->j++;
		}
		arg2->i++;
	}
}

void	send_to_check_valid(char **map)
{
	t_arg2	arg2;

	arg2.i = 0;
	arg2.j = 0;
	while (map[arg2.i])
	{
		arg2.j = 0;
		while (map[arg2.i][arg2.j])
		{
			if (map[arg2.i][arg2.j] == 'C' || map[arg2.i][arg2.j] == 'E')
			{
				free_map(map);
				ft_putstr("invalid path \n");
				exit(1);
			}
			arg2.j++;
		}
		arg2.i++;
	}
}

int	check_valid_map(char **map)
{
	t_arg2	arg2;

	arg2.changed = 1;
	arg2.i = 0;
	arg2.j = 0;
	while (arg2.changed)
	{
		arg2.changed = 0;
		arg2.i = 0;
		chek_mouvement_far(map, &arg2);
	}
	send_to_check_valid(map);
	free_map(map);
	return (0);
}

void	bg_screen(t_vars *t)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	mlx_clear_window(t->m, t->w);
	mlx_put_image_to_window(t->m, t->w, t->bg, 0, 0);
	print_element(t, i, j);
	mlx_put_image_to_window(t->m, t->w, t->img, t->x_pl * 90, t->y_pl * 90);
}
