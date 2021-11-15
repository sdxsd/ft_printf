/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 15:29:03 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/15 15:00:53 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int	handle_variable(const char *spec, va_list arglist)
{
	if (spec[1] == 'c')
		ft_putchar(va_arg(arglist, int));
	else if (spec[1] == 's')
		ft_putstr(va_arg(arglist, char *));
	else if (spec[1] == 'd' || spec[1] == 'i')
		ft_putnbr(va_arg(arglist, int));
	else if (spec[1] == '%')
		ft_putchar('%');
	else if (spec[1] == 'p')
		ft_putvoid(va_arg(arglist, int));
	else if (spec[1] == 'x')
		ft_puthex(va_arg(arglist, unsigned int), 0);
	else if (spec[1] == 'X')
		ft_puthex(va_arg(arglist, unsigned int), 1);
	else if (spec[1] == 'u')
		ft_putnbr(va_arg(arglist, unsigned int));
	return (1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arglist;
	int		arg_iter;
	int		iterator;

	arg_iter = 0;
	iterator = 0;
	va_start(arglist, fmt);
	while (fmt[iterator] != '\0')
	{
		if (fmt[iterator] == '%')
		{
			handle_variable(&fmt[iterator], arglist);
			va_arg(arglist, int);
			iterator++;
		}
		else
			ft_putchar(fmt[iterator]);
		iterator++;
	}
	return (iterator);
}


int main()
{

	void *ptr = malloc(1024 * 5);
	char *str = "coolej";
	ft_printf("%p\n", (void *)str);
	printf("%p\n", (void *)str);
}
