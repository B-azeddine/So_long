/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:59:43 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/10 05:42:28 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ini_line(t_arg1 *a)
{
	a->i = 0;
	a->j = 0;
	a->fline_x = 0;
	a->s_fline_x = 0;
	a->fline_y = 0;
	a->s_fline_y = 0;
}

int	check_map(t_vars *t)
{
	t_arg1	a;

	ini_line(&a);
	while (t->map[0][a.fline_x])
		a.fline_x++;
	a.s_fline_x = a.fline_x - 1;
	t->x_map = a.s_fline_x + 1;
	while (t->map[a.fline_y])
		a.fline_y++;
	a.s_fline_y = a.fline_y - 1;
	t->y_map = a.s_fline_y + 1;
	a.fline_x = 0;
	a.fline_y = 0;
	wall_lines(&a, t);
	check_line_length(&a, t);
	a.fline_x = 0;
	a.fline_y = 0;
	put_items(&a, t);
	wall_screen(&a, t);
	return (0);
}

int	allocation(t_vars *t)
{
	send_to_allocation(t);
	send_to_allocation2(t);
	send_to_allocation3(t);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	t;

	t.move = 0;
	t.x_pl = 0;
	t.y_pl = 0;
	t.direction = 1;
	if (ac == 2)
	{
		t.map = read_file_1(av[1]);
		if (!t.map)
			return (ft_putstr("empty map\n"), 1);
		check_map(&t);
		if (allocation(&t))
			return (ft_putstr("failed to get an image !"), 1);
		bg_screen(&t);
		mlx_hook(t.w, 17, 1L << 0, *close_win, &t);
		mlx_loop_hook(t.m, *ff, &t);
		mlx_key_hook(t.w, key_hook, &t);
		mlx_loop(t.m);
	}
	else
		ft_putstr("more than the arguments needed\n");
	return (0);
}
