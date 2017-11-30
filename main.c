/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:47:59 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/30 19:46:36 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char *line;
	int		fd;

	if (argc > 0)
	{
		fd = open(argv[1], O_RDONLY);
		ft_putstr("Valeur de fd :");
		ft_putnbr(fd);
		ft_putchar('\n');
		get_next_line(fd, &line);
		ft_putstr("LA CHAINE LINE : \n");
		ft_putstr(line);
		ft_putchar('\n');
		get_next_line(fd, &line);
		ft_putstr("LA CHAINE LINE : \n");
		ft_putstr(line);
		ft_putchar('\n');
	}
	return 0;
}
