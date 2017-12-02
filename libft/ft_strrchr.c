/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:36:39 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/16 18:06:57 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*ptr_s;
	int				count;

	ptr_s = s;
	count = 0;
	while (*ptr_s != 0)
	{
		if (*ptr_s == (char)c)
			count++;
		ptr_s++;
	}
	if (c == 0)
		return ((char *)ptr_s);
	else if (count == 0)
		return (NULL);
	while (count > 0)
	{
		if (*s == (char)c)
			count--;
		s++;
	}
	s--;
	return ((char *)s);
}
