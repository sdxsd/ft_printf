/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/11 15:29:03 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/15 11:56:01 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	handle_variable(const char *spec, va_list arglist)
{
	int	iter;

	iter = 1;
	if (spec[iter] == 'c')
		ft_putchar(va_arg(arglist, int));
	else if (spec[iter] == 's')
		ft_putstr(va_arg(arglist, char *));
	else if (spec[iter] == 'd')
		ft_putnbr(va_arg(arglist, int));
	else if (spec[iter] == '%')
		ft_putchar('%');
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
	return (0);
}

int main()
{
	ft_printf("da's een %d uit %d %s", 10, 10, "lekker snoepje!\n");
}