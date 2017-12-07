/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:24:03 by ndelest           #+#    #+#             */
/*   Updated: 2017/12/07 20:34:16 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_checkContent(t_getLine *list)
{
	int		i;

	i = 0;
	while (i < BUFF_SIZE && ((char *)(list->lst->content))[i] != '\n')
		i++;
	if (i < BUFF_SIZE)
	{
		list->line_size = -1;
		ft_memset(list->lst->content, 0, i);
		((char *)(list->lst->content))[i] = 0; 
	}
	else
	{
		list->line_size = 0;
		ft_memset(list->lst->content, 0, i);
	}
}

static char	*ft_resizeline(char **buff, int count)
{
	char *tmp;

	tmp = ft_strnew(BUFF_SIZE * (count + 1));
	tmp = ft_strcpy(tmp, *buff);
	*buff = ft_strnew(BUFF_SIZE * (count + 1));
	*buff = ft_strcpy(*buff, tmp);
	ft_strdel(&tmp);
	return (*buff);
}

static size_t		ft_linecopy(char **line, t_getLine *list)
{
	int		ret;
	int		i;
	char	*ptr;
	char	buff[BUFF_SIZE];

	ret = 1;
	i = 0;
	ptr = NULL;
	ft_memset(buff, 0, BUFF_SIZE);
	if (list->line_size == 0)
		*line = ft_strnew(BUFF_SIZE);
	if ((ret = read(list->fd, buff, BUFF_SIZE)) == -1)
		return (ret);
	while ((*line)[i] != 0)
		i++;
	list->lst = ft_lstnew((const void *)buff, BUFF_SIZE);
	ptr = (char *)ft_memccpy(*line + i, list->lst->content, '\n', BUFF_SIZE); 
	if (ptr == NULL && ret > 0)
	{
		list->line_size++;
		*line = ft_resizeline(line, list->line_size);
		ft_linecopy(line, list);
	}
	else if (ptr != NULL)
		*(ptr - 1) = 0;
	return ((ret == 0) ? ret : 1);
}

int		get_next_line(const int fd, char **line)
{
	static t_getLine	*list;
	int					ret;
	int					i;
	char				*ptr;

	if (line == NULL)
		return (-1);

	i = 0;
	if (!list)
	{
		list = (t_getLine *)malloc(sizeof(*list));
		list->fd = fd;
		list->line_size = 0;
	}
	if (list->line_size == -1)
	{
		while (((char *)(list->lst->content))[i] == 0 && i < BUFF_SIZE)
			i++;
		if (i < BUFF_SIZE)
		{
			*line = ft_strnew(BUFF_SIZE - i);
			if ((ptr = ft_memccpy(*line, &(list->lst->content[i]), '\n', BUFF_SIZE - i)) != NULL)
			{
				*(ptr - 1) = 0;
				ft_checkContent(list);
				return (1);
			}
			list->line_size = 1;
			*line = ft_resizeline(line, list->line_size);
		}
		else
			list->line_size = 0;
	}
	ret = ft_linecopy(line, list);
	if (ret == 1)
		ft_checkContent(list);
	ft_putendl("nouvelle ligne");
	ft_putendl(*line);
	return (ret);
}
