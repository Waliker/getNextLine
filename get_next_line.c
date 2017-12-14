/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:24:03 by ndelest           #+#    #+#             */
/*   Updated: 2017/12/14 23:23:16 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static void		ft_freeone(t_list **list, t_list *cur)
{
	t_list	*tmp;

	tmp = *list;

	while (tmp->content_size != cur->content_size && tmp->next->content_size 
				!= cur->content_size && tmp != NULL)
		tmp = tmp->next;
	if (tmp != NULL)
	{
		if (tmp->content_size != cur->content_size )
			tmp->next = cur->next;
		else
			*list = cur->next;
		cur->content_size = 0;
		ft_strdel(((char **)&(cur->content)));
		ft_memdel((void **)&cur);
	}
}

static t_list	*ft_currentfd(int fd, t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)(tmp->content_size) == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(NULL, fd);
	tmp->content_size = fd;
	ft_lstadd(list, tmp);
	return (tmp);
}

static char		*ft_linecopy(char *str, int opt)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (opt == 1)
		new = ft_strsub(str, 0, i);
	if (opt == 2)
	{
		if (str[i] != 0)
			j = i + 1;
		else
			j = i;
		while (str[j] != 0)
			j++;
		new = ft_strsub(str, i + 1, j);
		ft_strdel(&str);
	}
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	char			b[BUFF_SIZE + 1];
	t_list			*cur;
	char			*tmp;
	int				r;

	if (BUFF_SIZE <= 0 || fd == 1 || (r = read(fd, "", 0)) == -1)
		return (-1);
	cur = ft_currentfd(fd, &list);
	ft_memset(b, 0, BUFF_SIZE + 1);
	if (cur->content == NULL)
		cur->content = ft_strnew(0);
	while (!(ft_strchr(cur->content, '\n')) && (r = read(fd, b, BUFF_SIZE) > 0))
	{
		tmp = cur->content;
		cur->content = ft_strjoin(cur->content, b);
		ft_strdel(&tmp);
		ft_memset(b, 0, BUFF_SIZE + 1);
	}
	*line = ft_linecopy(cur->content, 1);
	if (r == 0  && *((char *)(cur->content)) == 0)
	{
		ft_freeone(&list, cur);
		return (0);
	}
	cur->content = ft_linecopy(cur->content, 2);
	return (1);
}
