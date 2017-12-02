/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:18:06 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/21 11:10:25 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbstr(char const *s, char c)
{
	int	i;
	int	stock;

	i = 0;
	stock = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			stock++;
			while (s[i] != c && s[i + 1] != 0)
				i++;
		}
		i++;
	}
	return (stock);
}

static int		ft_cursor(char const *s, char c, int i)
{
	while (s[i] == c && s[i] != 0)
		i++;
	return (i);
}

static int		ft_letters(char const *s, char c, int i)
{
	int		stock;

	stock = 0;
	while (s[i] != c && s[i] != 0)
	{
		i++;
		stock++;
	}
	return (stock);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tabstr;
	int		i;
	int		word;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	word = ft_nbstr(s, c);
	if (!(tabstr = (char **)malloc(sizeof(*tabstr) * (word + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (j < word)
	{
		k = 0;
		i = ft_cursor(s, c, i);
		if (!(tabstr[j] = ft_strnew((ft_letters(s, c, i)))))
			return (NULL);
		while (s[i] != c && s[i] != 0)
			tabstr[j][k++] = s[i++];
		tabstr[j++][k] = 0;
	}
	tabstr[j] = 0;
	return (tabstr);
}
