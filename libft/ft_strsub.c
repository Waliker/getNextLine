/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:17:52 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/18 12:58:50 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(*new) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[start] != 0 && i < len)
	{
		new[i++] = s[start++];
	}
	new[i] = 0;
	return (new);
}
