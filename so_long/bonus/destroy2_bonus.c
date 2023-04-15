/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:10:05 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/10 05:38:30 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_sheese(t_vars *t)
{
	destroy_img(t);
	mlx_destroy_image(t->m, t->w);
}

void	destroy_closed(t_vars *t)
{
	destroy_sheese(t);
	mlx_destroy_image(t->m, t->s);
}

void	destroy_opened(t_vars *t)
{
	destroy_closed(t);
	mlx_destroy_image(t->m, t->c);
}
