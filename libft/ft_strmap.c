/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:22:44 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/19 17:51:27 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	if (s == NULL)
		return (NULL);
	if (!(new = ft_strnew((ft_strlen(s)))))
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		new[i] = (*f)(s[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}
