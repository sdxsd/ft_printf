/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 15:29:03 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/16 13:06:38 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

int	handle_variable(const char *spec, va_list arglist)
{
	if (spec[1] == 'c')
		return (ft_putchar_len(va_arg(arglist, int)));
	else if (spec[1] == '%')
		return (ft_putchar_len('%'));
	else if (spec[1] == 's')
		return (ft_putstr_len(va_arg(arglist, char *)));
	else if (spec[1] == 'd' || spec[1] == 'i')
		return (ft_putnbr_len(va_arg(arglist, int)));
	else if (spec[1] == 'p')
		return (ft_putvoid(va_arg(arglist, size_t)));
	else if (spec[1] == 'x')
		return (ft_puthex(va_arg(arglist, unsigned int), 0));
	else if (spec[1] == 'X')
		return (ft_puthex(va_arg(arglist, unsigned int), 1));
	else if (spec[1] == 'u')
		return (ft_unsigned_putnbr(va_arg(arglist, unsigned int)));
	return (1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arglist;
	int		arg_iter;
	int		iterator;
	int		x;

	arg_iter = 0;
	iterator = 0;
	x = 0;
	va_start(arglist, fmt);
	while (fmt[iterator] != '\0')
	{
		if (fmt[iterator] == '%')
		{
			x += handle_variable(&fmt[iterator], arglist);
			va_arg(arglist, int);
			iterator++;
		}
		else
			x += ft_putchar_len(fmt[iterator]);
		iterator++;
	}
	va_end(arglist);
	return (x);
}

/*
int main()
{
	ft_printf("%");
	printf("%");
}
*/