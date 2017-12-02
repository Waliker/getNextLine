/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:17:17 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/16 18:04:39 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *locate;

	locate = (unsigned char *)s;
	while (n--)
	{
		if (*locate == (unsigned char)c)
			return (locate);
		locate++;
	}
	return (NULL);
}
