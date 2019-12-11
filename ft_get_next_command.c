/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddarell <ddarell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 23:32:33 by ddarell           #+#    #+#             */
/*   Updated: 2019/12/11 23:36:06 by ddarell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_get_next_command(int fd, char *cmd)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (i < 4 && (ret = read(fd, cmd + i, 1)) > 0)
	{
		if (*(cmd + i) == '\n')
			break ;
		i++;
	}
	if (ret == -1 || (ret > 0 && (i > 3 || i < 2)) || (ret == 0 && i != 0))
		ft_error();
	cmd[i] = 0;
	return (ret);
}
