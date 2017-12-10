/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:24:03 by ndelest           #+#    #+#             */
/*   Updated: 2017/12/10 16:07:06 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_resizeline(char **buff, int count, int i)
{
	char *tmp;

	tmp = ft_strnew(count);
	tmp = ft_strncpy(tmp, *buff, count - i);
//	ft_putendl("chaine de tmp");
//	ft_putendl(tmp);
	ft_strdel(buff);
	return (tmp);
}

static size_t		ft_linecopy(char **line, t_list *file, int fd)
{
	int		ret;
	int		i;
	int		j;
	char	buff[BUFF_SIZE + 1];

	i = 0;
	j = 0;
	ft_memset(buff, 0, BUFF_SIZE + 1);
	if ((ret = read(fd, buff, BUFF_SIZE)) < 1)
		return (ret);
	while (buff[i] != '\n' && i < BUFF_SIZE)
		i++;
	if (((t_line *)(file->content))->i != 0)
	{
//		ft_putendl(*line);
//		ft_putnbr(((t_line *)(file->content))->i);
		*line = ft_resizeline(line, i + ((t_line *)(file->content))->i, i);
	}
	else
		*line = ft_strnew(i);
//	while (*(line[j]) != 0)
//		j++;
	j = ((t_line *)(file->content))->i;
//	ft_putstr("valeur de j : ");
//	ft_putnbr(j);
//	ft_putchar('\n');
	ft_strncpy(*line + j, buff, i);
	//	ft_putstr("Chaine buff :");
	//	ft_putendl(buff);
//	ft_putstr("valeur de ret : ");
//	ft_putnbr(ret);
//	ft_putchar('\n');
//	ft_putstr("Chaine line du buff :");
//	ft_putendl(*line);
	if (buff[i] == 0 && ret > 0)
	{
//		ft_putendl("je fais la recursive");
		((t_line *)(file->content))->i = ((t_line *)(file->content))->i + ft_strlen(buff);
		return (ft_linecopy(line, file, fd));
	}
	//		if (((t_line *)(file->content))->rem != NULL)
	//			ft_strdel(&((t_line *)(file->content))->rem);
	else if (ret > 0)
	{
//		ft_putendl("je remplie le reste");
		((t_line *)(file->content))->rem = ft_strnew(BUFF_SIZE - i);
		ft_strncpy(((t_line *)(file->content))->rem, &buff[i + 1], BUFF_SIZE - i);
		((t_line *)(file->content))->i = 0;
	}

	return ((ret == 0) ? ret : 1);
}

static t_line	ft_linkinit(int fd)
{
	t_line	getLine;

	getLine.rem = NULL;
	getLine.fd = fd;
	getLine.i = 0;
	return (getLine);
}

int		get_next_line(const int fd, char **line)
{
	static t_list		*file;
	int					ret;
	t_line				getLine;
	int					i;

	if (line == NULL)
		return (-1);
	i = 0;
	if (!file)
	{
		getLine = ft_linkinit(fd);
		file = ft_lstnew(&getLine, sizeof(getLine));
//		ft_putendl(((t_line *)(file->content))->rem);
//		ft_putstr("valeur de fd : ");
//		ft_putnbr(((t_line *)(file->content))->fd);
//		ft_putchar('\n');
//		ft_putstr("valeur de i : ");
//		ft_putnbr(((t_line *)(file->content))->i);
//		ft_putchar('\n');

	}
	if (((t_line *)(file->content))->rem != NULL && ((t_line *)(file->content))->rem[((t_line *)(file->content))->i] != 0)
	{
		while (((t_line *)(file->content))->rem[((t_line *)(file->content))->i + i] != '\n' 
				&& ((t_line *)(file->content))->rem[((t_line *)(file->content))->i + i]  != 0)
			i++;
//		ft_putendl("la chaine de remai :");
//		ft_putendl(((t_line *)(file->content))->rem);
		*line = ft_strnew(i);

		*line = ft_strncpy(*line, (&((t_line *)(file->content))->rem[((t_line *)(file->content))->i]), i);
		((t_line *)(file->content))->i = ((t_line *)(file->content))->i + i + 1;
//		ft_putstr("Chaine line du remain :");
//		ft_putendl(*line);
//		ft_putendl("ce qu'il reste du remain :");
//		ft_putendl((&((t_line *)(file->content))->rem[((t_line *)(file->content))->i]));
		if (((t_line *)(file->content))->rem[((t_line *)(file->content))->i - 1] == '\n' || i == 0)
		{
			ft_putendl("je retourne 1");
			return (1);
		}
	}
	((t_line *)(file->content))->i = i; 
	ret = ft_linecopy(line, file, fd);
//	ft_putendl("c'est fini");
//	ft_putnbr(ret);
//	ft_putchar('\n');
	if (ret == 0 && ((t_line *)(file->content))->rem != NULL)
	{
		ft_strdel((&((t_line *)(file->content))->rem));
	}
//	ft_putstr("Chaine line avant le return :");
//	ft_putendl(*line);
	return (ret);
}
