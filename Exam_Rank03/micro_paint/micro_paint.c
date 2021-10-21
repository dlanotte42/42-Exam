/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:00:12 by dlanotte          #+#    #+#             */
/*   Updated: 2021/10/21 22:27:09 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

typedef struct s_base
{
	int		width;
	int		height;
	char	background;
}				t_base;			

t_base	ft_init(FILE *file)
{
	t_base	pattern;

	if (fscanf(file, "%d %d %c\n", &pattern.width, \
		&pattern.height, &pattern.background) == 3)
	{
		if (pattern.width <= 0 || pattern.width > 300 \
			|| pattern.height <= 0 || pattern.height > 300)
		{
			pattern.height = -1;
		}
	}
	return (pattern);
}

void	micro_paint(FILE *file)
{
	t_base	base;

	base = ft_init(file);
	if (base.height == -1)
		return (0);
}

int	main(int argc, char **argv)
{
	FILE	*file;

	if (argc == 2)
	{
		file = fopen(argv[1], "r");
		if (file)
			micro_paint(file);
		fclose(file);
	}
	else
		write(1, "Error: argument\n", 16);
	return (0);
}
