/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:47:59 by ndelest           #+#    #+#             */
/*   Updated: 2017/12/07 19:32:16 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char *line;
	int		fd;
	int		fd2;
//	char	n = '\n';

	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open("me.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
		ft_putendl("Je suis dans le main");
		while (get_next_line(fd, &line) == 1)
		{
			ft_putstr(line);
			write(fd2, line, strlen(line));
//			write(fd2, &n, 1);
			free(line);
		}
		close(fd);
		close(fd2);
	}
	return 0;
}
