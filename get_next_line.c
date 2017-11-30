/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:24:03 by ndelest           #+#    #+#             */
/*   Updated: 2017/11/30 20:27:32 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*static int	ft_searchline(char **line, char *buff, static int linenbr)
{
	size_t	i;
	int		count;

	i = 0;
	while (buff[i++] != 0)
	{
		if (buff[i] == '\n')
			return (1)
	}
}*/

static void ft_linecopy(int linenbr, char **line, char *tmp)
{
	size_t	i;
	int		count;
	size_t	j;

	i = 0;
	count = 0;
	while (tmp[i] != 0 && count < linenbr)
		if (tmp[i++] == '\n')
			count++;
	j = i;
	while (tmp[i] != 0 && tmp[i] != '\n')
		++i;
	*line = ft_strnew(i - j);
	*line = ft_strncpy(*line, &tmp[j], (i - j));
}

static char	*ft_resizebuffer(char *buff, int count)
{
	char *tmp;

	tmp = ft_strnew(BUFF_SIZE * (count) + 1);
	tmp = ft_strcpy(tmp, buff);
	buff = ft_strnew(BUFF_SIZE * (count + 1));
	buff = strcpy(buff, tmp);

	return (buff);
}

static int	ft_entireline(const int fd, int linenbr, char **line, char *buff)
{
	int		nbread;
	int		count;


	ft_bzero((void *) buff, BUFF_SIZE);
	count = 0;
	while ((nbread = read(fd, &buff[BUFF_SIZE * count], BUFF_SIZE)) > 0)
	{
		buff[nbread * (count + 1)] = 0;
		count++;
		buff = ft_resizebuffer(buff, count);
	}
	ft_putstr("LE BUFFER : \n");
	ft_putstr(buff);
	ft_putchar('\n');
	if (*buff != 0)
	{
		ft_linecopy(linenbr, line, buff);
		return (1);
	}
	else if (nbread == -1)
		return (-1);
	else
		return (0);
}

int		get_next_line(const int fd, char **line)
{
	static int	linenbr;
	int			i;
	static char		*buff;

	if (!*line)
		linenbr = 0;
	if (!*line)
	{
		buff = ft_strnew(BUFF_SIZE);
		i = ft_entireline(fd, linenbr, line, buff);
	}
	else
	{
		ft_linecopy(linenbr, line, buff);
		return (1);
	}
	linenbr++;
	return (i);
}
