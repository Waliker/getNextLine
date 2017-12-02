/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:24:03 by ndelest           #+#    #+#             */
/*   Updated: 2017/12/02 22:06:13 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_linecopy(char **line, char **buff, size_t i)
{
	size_t	j;

	j = i;
	while ((*buff)[i] != 0 && (*buff)[i] != '\n')
		++i;
	*line = ft_strnew(i - j);
	*line = ft_strncpy(*line, &(*buff)[j], (i - j));

	return (i);
}

static char	*ft_resizebuffer(char **buff, int count)
{
	char *tmp;

	tmp = ft_strnew(BUFF_SIZE * (count + 1));
	tmp = ft_strcpy(tmp, *buff);
	*buff = ft_strnew(BUFF_SIZE * (count + 1));
	*buff = ft_strcpy(*buff, tmp);
	ft_strdel(&tmp);
	return (*buff);
}

int		get_next_line(const int fd, char **line)
{
	static char		*buff;
	int				nbread;
	int				count;
	static size_t	i;

	count = 0;
	nbread = 1;
	if (line == NULL)
		return (-1);
	if (!i || buff == NULL)
	{
		i = 0;
		//		ft_putstr("je vais read le fd !\n");
		buff = ft_strnew(BUFF_SIZE);
		while ((nbread = read(fd, &buff[BUFF_SIZE * count], BUFF_SIZE)) > 0)
		{
			buff[(BUFF_SIZE * count) + nbread] = 0;
			count++;
			buff = ft_resizebuffer(&buff, count);
		}
		if (nbread < 0)
		{
			ft_strdel(&buff);
			return (-1);
		}
	}
	ft_putnbr(i);
	ft_putchar('\n');
	if (buff != NULL)
	{
		i = ft_linecopy(line, &buff, i);
		//		ft_putstr("le buffer en sortie de linecopy :\n");
		//		ft_putstr(buff);
		//		ft_putchar('\n');
		//		ft_putnbr(i);

	}
	if ((buff && buff[i] == 0) || (nbread == 0 && count < 2))
	{
		ft_strdel(&buff);
		//		ft_putstr("je vais retourner 0 apres avoir free le buff\n");
		return (0);
	}
	if (buff[i] != 0)
		i++;
	return (1);
}
