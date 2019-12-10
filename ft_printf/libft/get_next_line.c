/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:56:33 by ddarell           #+#    #+#             */
/*   Updated: 2019/09/25 15:49:40 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_linecut(char *str, char *ptr)
{
	char *line;

	*ptr = 0;
	line = ft_strdup(str);
	*ptr = '\n';
	return (line);
}

static int	ft_checkrest(char *rest, char **line)
{
	char *nptr;

	nptr = ft_strchr(rest, '\n');
	if ((*line = ft_linecut(rest, nptr)) == NULL)
		return (-1);
	ft_strncpy(rest, nptr + 1, GNL_BUFF_SIZE + 1);
	return (1);
}

static int	ft_readfd(char *rest, char *buf, char **line, const int fd)
{
	int		ret;
	char	*tmp1;
	char	*tmp2;
	char	*nptr;

	while ((ret = read(fd, buf, GNL_BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		if ((nptr = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strncpy(rest, nptr + 1, GNL_BUFF_SIZE + 1);
			tmp1 = *line;
			tmp2 = ft_linecut(buf, nptr);
			*line = ft_strjoin(tmp1, tmp2);
			free(tmp1);
			free(tmp2);
			return ((tmp2 == NULL || *line == NULL) ? -1 : -2);
		}
		tmp1 = *line;
		*line = ft_strjoin(tmp1, buf);
		free(tmp1);
		if (*line == NULL)
			return (-1);
	}
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[GNL_BUFF_SIZE + 1];
	static char	rest[MAX_FD + 1][GNL_BUFF_SIZE + 1];

	if (GNL_BUFF_SIZE <= 0 || GNL_BUFF_SIZE > 8000000
	|| fd < 0 || fd > 10240 || !(line))
		return (-1);
	ft_bzero(buf, GNL_BUFF_SIZE + 1);
	if (ft_strchr(rest[fd], '\n'))
		return (ft_checkrest(rest[fd], line));
	if ((*line = ft_strdup(rest[fd])) == NULL)
		return (-1);
	if ((ret = (ft_readfd(rest[fd], buf, line, fd))) == -2)
		return (1);
	if (ret == 0 && !(ft_strchr(buf, '\n')) && (ft_strlen(*line)))
	{
		ft_bzero(rest[fd], GNL_BUFF_SIZE + 1);
		return (1);
	}
	return (ret);
}
