/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:10:05 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/08 01:10:43 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
