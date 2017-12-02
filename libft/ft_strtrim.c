/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:51:00 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/18 12:50:47 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s[j + 1] != 0)
		j++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > i)
		j--;
	size = j - i + 1;
	if (!(new = (char *)malloc(sizeof(*new) * (size + 1))))
		return (NULL);
	j = 0;
	while (s[i] != 0 && j < size)
		new[j++] = s[i++];
	new[j] = 0;
	return (new);
}
