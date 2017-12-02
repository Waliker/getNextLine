/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:00:02 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/19 17:18:39 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printnbr(int nb)
{
	if (nb >= 10 || nb <= -10)
	{
		ft_printnbr(nb / 10);
		ft_printnbr(nb % 10);
	}
	else if (nb < 0)
	{
		nb = -nb + 48;
		ft_putchar(nb);
	}
	else
	{
		nb = nb + 48;
		ft_putchar(nb);
	}
}

void		ft_putnbr(int n)
{
	if (n >= 0)
		ft_printnbr(n);
	else
	{
		ft_putchar('-');
		ft_printnbr(n);
	}
}
