/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 22:12:19 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/10 05:27:32 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_bg(t_vars *t)
{
	free_map(t->map);
	ft_putstr("failed to upload image !");
	mlx_destroy_window(t->m, t->w);
}

void	destroy_img(t_vars *t)
{
	destroy_bg(t);
	mlx_destroy_image(t->m, t->bg);
}

void	destroy_wall(t_vars *t)
{
	destroy_img(t);
	mlx_destroy_image(t->m, t->img);
}
