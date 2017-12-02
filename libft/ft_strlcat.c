/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:00:30 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/16 18:51:28 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	cnt;

	i = ft_strlen(dst);
	if (i > size)
	{
		return (size + ft_strlen(src));
	}
	else
	{
		cnt = i + ft_strlen(src);
		j = 0;
		while (i < size - 1 && src[j] != 0)
			dst[i++] = src[j++];
		dst[i] = 0;
		return (cnt);
	}
}
