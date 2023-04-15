/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:44:10 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/08 17:27:42 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(char	*s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!s2)
	{
		return (NULL);
	}
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
