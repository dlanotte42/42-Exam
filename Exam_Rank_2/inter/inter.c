/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:21:20 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/11 12:04:48 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_check(char *check, char c)
{
	int i = 0;

	while (check[i])
	{
		if (check[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_inter(char *str, char *check)
{
	char magazzino[255];
	int counter = 0;
	int counter_check = 0;
	int	magazzino_counter = 0;

	while(str[counter])
	{
		while(check[counter_check])
		{
			if (str[counter] == check[counter_check] && ft_check(magazzino, str[counter]))
			{
				magazzino[magazzino_counter++] = str[counter];
				ft_putchar(str[counter]);
			}
			counter_check++;
		}
		counter_check = 0;
		counter++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	else
		ft_putchar('\n');
	return (0);
}