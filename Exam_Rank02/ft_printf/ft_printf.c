/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:42:47 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/03/15 21:00:02 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void			ft_putchar(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->printed += 1;
}

void			ft_putnbr_base(unsigned int number, int base, t_flags *flags)
{
	if (number > base - 1 )
	{
		ft_putnbr_base(number / base, base, flags);
		ft_putchar("123456789abcdef"[number % base], flags);
	}else 
		ft_putchar("123456789abcdef"[number], flags);
}

int				ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int				ft_find_number(char *str, int i)
{
	int		number = 0, j = 0, len = i;
	char	*substr;

    while(ft_isdigit(str[len]))
    {
        number = number * 10 + (str[len] - 48);
        len++;
    }
	return (number);
}

int				ft_calc_flags(char *str, int i)
{
	if (ft_isdigit(str[i]))
		return (ft_find_number(str, i));
	return (0);
}

t_flags			*ft_check_flags(char *str, int i, t_flags *flags, char params)
{
	while(str[i] != params)
	{
		if (str[i] == '.')
			flags->precision = ft_calc_flags(str, i + 1);
		else if (ft_isdigit(str[i]) && flags->precision == 0 && flags->width == 0)
			flags->width = ft_calc_flags(str, i);
		i++;
	}
	return (flags);
}

char			ft_check_params(char *str, int i)
{
	if (str[i] == '%')
		while(str[i++])
			if (str[i] == 'd' || str[i] == 'x' || str[i] == 's')
				return (str[i]);
	return (0);
}

int				ft_skip_content(char *str, int i)
{
	int		len = i;
	char	param;

	if ((param = ft_check_params(str, i)) > 0)
		while(str[len] != param)
			len++;
	len -= i;
	return(len + 1);
}

int				ft_strlen(char *str)
{
	int		i = 0;
	while(str[i])
		i++;
	return (i);
}

void			ft_print_final(char *str, int i, t_flags *flags, char params, va_list list)
{
	
}

int				ft_printf(const char *str, ...)
{
	t_flags		flags;
	int			i = 0;
	char		params;
	va_list		list;

	flags.precision = 0;
	flags.width = 0;
	flags.printed = 0;
	va_start(list, str);
	while(str[i])
	{
		if ((params = ft_check_params((char*)str, i)) > 0)
		{
			ft_check_flags((char*)str, i, &flags, params);
			ft_print_final((char*)str, i, &flags, params, list);
		}
		else
			ft_putchar(str[i], &flags);
		i += ft_skip_content((char*)str, i);
	}
	va_end(list);
	return (flags.printed);
}

int				main(void)
{
	
	ft_printf("--_%d_--\n", ft_printf("%20.2s", "toto"));
	printf("--_%d_--\n", printf("%10.2s", "toto"));

	return (0);
}