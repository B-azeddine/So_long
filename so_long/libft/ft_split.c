/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablidi <ablidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:05:08 by ablidi            #+#    #+#             */
/*   Updated: 2023/04/08 17:27:36 by ablidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	words(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		{
			i++;
		}
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			counter++;
		}
	}
	return (counter);
}

static int	letters(const char *s, int p, char c)
{
	int	counter;

	counter = 0;
	while (s[p] && s[p] != c)
	{
		++p;
		++counter;
	}
	return (counter);
}

static char	**call_alloc(char **p, char const *s, int i, char c)
{
	int	j;
	int	k;

	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] && s[i] == c)
			++i;
		if (s[i])
		{
			p[j] = (char *)malloc(sizeof(char) * (letters(s, i, c) + 1));
			if (!p[j])
				return (NULL);
			while (s[i] && s[i] != c)
			{
				p[j][k++] = s[i];
				++i;
			}
			p[j][k] = '\0';
			++j;
		}
	}
	p[j] = NULL;
	return (p);
}

char	**ft_split(char	*s, char c)
{
	char	**p;
	int		i;

	i = 0;
	p = malloc(sizeof(char *) * (words(s, c) + 1));
	if (!p)
		return (NULL);
	call_alloc(p, s, i, c);
	return (p);
}
