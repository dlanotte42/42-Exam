/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:02:27 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/04 16:41:19 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_inv_check(char *str, char c, int i)
{
	while(str[i--] && i >= 0)
	{
		if (str[i] == c)
			return (0);
	}
	return (1);
}

void	ft_inter(char *s1, char *s2)
{
	int i; 
	int j;

	i = 0;
	j = 0;
	while(s1[i])
	{
		while(s2[j])
		{
			if (ft_inv_check(s1, s2[j], i) && s1[i] == s2[j])
			{
				ft_putchar(s1[i]);
				break ;
			}
			j++;
		}
		j = 0;
		i++;
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
