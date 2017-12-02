/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:00:02 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/19 17:19:07 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printnbr_fd(int nb, int fd)
{
	if (nb >= 10 || nb <= -10)
	{
		ft_printnbr_fd(nb / 10, fd);
		ft_printnbr_fd(nb % 10, fd);
	}
	else if (nb < 0)
	{
		nb = -nb + 48;
		ft_putchar_fd(nb, fd);
	}
	else
	{
		nb = nb + 48;
		ft_putchar_fd(nb, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		ft_printnbr_fd(n, fd);
	else
	{
		ft_putchar_fd('-', fd);
		ft_printnbr_fd(n, fd);
	}
}
