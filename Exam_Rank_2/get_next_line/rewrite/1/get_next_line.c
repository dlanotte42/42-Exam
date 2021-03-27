/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:52:01 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/11 11:06:24 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line.h"

int		get_next_line(char **line)
{
	char buffer;
	char *temp, *str;
	int len = 0, ret;

	if (!line || !(temp = malloc(sizeof(char) * 4096)))
		return(-1);
	temp[0] = '\0';
	while((ret = read(0, &buffer, 1)) > 0)
	{
		if (buffer == '\0' || buffer == '\n')
			break ;
		temp[len] = buffer;
		temp[len+= 1] = '\0';
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (-1);
	str[len] = '\0';
	while(len-- >= 0)
		str[len] = temp[len];
	free(temp);
	*line = str;
	return(ret);
}