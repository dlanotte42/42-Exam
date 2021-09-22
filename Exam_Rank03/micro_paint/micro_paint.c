/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:00:12 by dlanotte          #+#    #+#             */
/*   Updated: 2021/09/22 16:06:05 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	micro_paint(void)
{
	
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		micro_paint();
	else
		write(1, "Error: argument\n", 16);
	return (0);
}
