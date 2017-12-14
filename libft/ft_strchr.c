/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:31:10 by ndelest           #+#    #+#             */
/*   Updated: 2017/12/14 17:55:22 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	i;

	i = (char)c;
	while (*s != 0)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == 0)
		return ((char *)s);
	else
		return (NULL);
}
