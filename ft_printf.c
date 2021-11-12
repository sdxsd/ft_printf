/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 15:29:03 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/12 16:46:39 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	handle_variable(const char *spec)
{
	int	iter;

	iter = 1;
	if (spec[iter] == c)
	{
		ft_putchar('c');
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arglist;
	int		arg_iter;
	int		iterator;

	arg_iter = 0;
	iterator = 0;
	va_start(arglist, arg_iter);
	while (fmt[iterator] != '\0')
	{
		if (fmt[iterator] == '%')
			ft_putstr(handle_variable(&fmt[iterator]));
		else
			ft_putchar(fmt[iterator]);
	}
}
