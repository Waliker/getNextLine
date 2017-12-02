/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:07:25 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/16 15:16:51 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	stock;

	i = 0;
	stock = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		stock = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (stock != 0)
			return (stock);
		else
			i++;
	}
	if (s1[i] == 0)
	{
		stock = -(unsigned char)s2[i];
		return (stock);
	}
	else
	{
		stock = (unsigned char)s1[i];
		return (stock);
	}
}
