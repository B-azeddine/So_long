/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:28:03 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/08 21:05:32 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_caracters(t_vars *t, int i, int j)
{
	if (t->map[i][j] == '1')
		mlx_put_image_to_window(t->m, t->w, t->wall, j * 90, i * 90);
	if (t->map[i][j] == 'C')
		mlx_put_image_to_window(t->m, t->w, t->s, j * 90, i * 90);
	if (t->map[i][j] == 'E')
		mlx_put_image_to_window(t->m, t->w, t->c, j * 90, i * 90);
	if (t->map[i][j] == 'E' && t->count == 0)
		mlx_put_image_to_window(t->m, t->w, t->o, t->x * 90, t->y * 90);
}

void	print_element(t_vars *t, int i, int j)
{
	i = 0;
	j = 0;
	while (t->map[i])
	{
		j = 0;
		while (t->map[i][j])
		{
			print_caracters(t, i, j);
			j++;
		}
		i++;
	}
}

int	ff(t_vars *t)
{
	static int	frame;

	frame = 0;
	if (frame % 500 == 0)
	{
		bg_screen(t);
	}
	frame++;
	if (frame > 50000)
		frame = 0;
	return (0);
}
