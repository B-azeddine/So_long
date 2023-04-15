/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_allocation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:27:23 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/10 05:55:51 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	send_to_allocation(t_vars *t)
{
	int	x;
	int	y;

	t->m = mlx_init();
	if (!t->m)
	{
		free_map(t->map);
		exit (1);
	}
	t->w = mlx_new_window(t->m, t->x_map * 90, t->y_map * 90, "so_long");
	if (!t->w)
	{	
		ft_putstr("failed to upload window !");
		free_map(t->map);
		exit (1);
	}
	t->bg = mlx_xpm_file_to_image(t->m, "textures/Blue1.xpm", &x, &y);
	if (!t->bg)
	{
		destroy_bg(t);
		exit (1);
	}
}

void	send_to_allocation2(t_vars *t)
{
	int	x;
	int	y;

	t->img = mlx_xpm_file_to_image(t->m, "textures/far.xpm", &x, &y);
	if (!t->img)
	{
		destroy_img(t);
		exit (1);
	}
	t->wall = mlx_xpm_file_to_image(t->m, "textures/wall.xpm", &x, &y);
	if (!t->wall)
	{
		destroy_wall(t);
		exit (1);
	}
}

void	send_to_allocation3(t_vars *t)
{
	int	x;
	int	y;

		t->s = mlx_xpm_file_to_image(t->m, "textures/cheese.xpm", &x, &y);
	if (!t->s)
	{
		destroy_sheese(t);
		exit (1);
	}
	t->c = mlx_xpm_file_to_image(t->m, "textures/closed.xpm", &x, &y);
	if (!t->c)
	{
		destroy_closed(t);
		exit (1);
	}
	t->o = mlx_xpm_file_to_image(t->m, "textures/opened.xpm", &x, &y);
	if (!t->o)
	{
		destroy_opened(t);
		exit (1);
	}
}
