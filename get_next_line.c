/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:24:03 by ndelest           #+#    #+#             */
/*   Updated: 2017/12/02 14:34:13 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_linecopy(char **line, char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i] != 0 && buff[i] != '\n')
		++i;
	*line = ft_strnew(i);
	*line = ft_strncpy(*line, buff, (i));
	buff = buff + i + 1;
	return (buff);
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

int		get_next_line(const int fd, char **line)
{
	static char		*buff;
	int		nbread;
	int		count;

	count = 0;
	if (!*line)
	{
		buff = ft_strnew(BUFF_SIZE);
		while ((nbread = read(fd, &buff[BUFF_SIZE * count], BUFF_SIZE)) > 0)
		{
			count++;
			buff = ft_resizebuffer(buff, count);
		}
		buff[BUFF_SIZE * (count)] = 0;
		if (nbread == -1)
		{
			free(buff);
			return (-1);
		}
	}
	if (*buff != 0)
		buff = ft_linecopy(line, buff);
	else
	{
		free(buff);
		return (0);
	}
	return (1);
}
