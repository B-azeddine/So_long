/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:38:03 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/08 22:27:02 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int a)
{
	char	cmt;

	if (a >= 0 && a <= 9)
	{
		cmt = a + '0';
		ft_putchar(cmt);
	}
	if (a > 9)
	{
		ft_putnbr(a / 10);
		ft_putnbr(a % 10);
	}
}
