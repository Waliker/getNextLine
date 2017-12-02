/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:59:04 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/21 10:11:31 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	i;

	i = (unsigned char)c;
	if (ft_memchr(src, c, n))
	{
		while (*(unsigned char *)src != i)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
		*(unsigned char *)dst++ = *(unsigned char *)src;
		return (dst);
	}
	else
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
}
