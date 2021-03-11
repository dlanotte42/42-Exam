/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:04:31 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/11 11:10:41 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line.h"

int		get_next_line(char **line)
{
	char *str, *temp;
	int len = 0, ret;
	char buffer;
	
	if (!line || (!(temp = malloc(4096))))
		return(-1);
	temp[0] = '\0';
	while ((ret = read(0, &buffer, 1)) > 0)
	{
		if (buffer == '\0'|| buffer == '\n')
			break ;
		temp[len] = buffer;
		temp[len+= 1] = '\0';
	}
	if (!(str = malloc(len + 1)))
		return(-1);
	str[len] = '\0';
	while (len-- > 0)
		str[len] = temp[len];
	free(temp);
	*line = str;
	return (ret);
}