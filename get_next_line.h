/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:07:01 by ndelest           #+#    #+#             */
/*   Updated: 2017/12/14 22:10:48 by ndelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>
# define BUFF_SIZE 11

typedef	struct			s_line
{
	char				*rem;
	int					fd;
	int					i;
}						t_line;				
int		get_next_line(const int fd, char **line);
#endif
