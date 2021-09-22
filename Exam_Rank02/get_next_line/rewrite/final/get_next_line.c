/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:16:03 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/03/15 18:23:26 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line.h"

int		get_next_line(char **line)
{
	char	*temp, *str;
	int		ret, len = 0;
	char	buffer;

	if (!line || !(temp = malloc(4096)))
		return(-1);
	temp[0] = '\0';
	while ((ret = read(0, &buffer, 1)) > 0)
	{
		if (buffer == '\0' || buffer == '\n')
			break ;
		temp[len] = buffer;
		temp[len += 1] = '\0';
	}
	if (!(str = malloc(len + 1)))
		return (-1);
	str[len] = '\0';
	while(len-- > 0)
		str[len] = temp[len];
	*line = str;
	free(temp);
	return(ret);
}