/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:13:00 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/16 19:58:46 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int i;
	int is_neg;
	int nb;

	i = 0;
	is_neg = 0;
	nb = 0;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\f' || str[i] == '\v'
			|| str[i] == '\t' || str[i] == 32)
		i++;
	if (str[i] == '-')
		is_neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = (str[i++] - '0') + nb * 10;
	if (is_neg)
		return (-nb);
	return (nb);
}
