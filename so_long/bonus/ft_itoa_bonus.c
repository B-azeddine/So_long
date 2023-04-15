/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:02:50 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/08 22:27:43 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		len = 1;
		nbr *= -1;
	}
	if (nbr == 0)
		len = 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{	
	unsigned int	nbr;
	int				sign;
	int				len;
	char			*alpha;

	sign = 0;
	nbr = n;
	len = ft_len(n);
	alpha = (char *)malloc(sizeof(char) * len + 1);
	if (!alpha)
		return (0);
	if (n < 0)
	{
		sign = 1;
		nbr = -n;
	}
	alpha[len--] = '\0';
	while (len >= 0)
	{	
		alpha[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign == 1)
		alpha[0] = '-';
	return (alpha);
}
