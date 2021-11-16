/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/15 12:07:06 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/16 11:45:27 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_puthex(size_t nb, unsigned int mode)
{
	size_t	temp;
	int		x;

	x = 0;
	if (nb != 0)
	{
		x += ft_puthex(nb / 16, mode);
		temp = nb % 16;
		if (temp < 10)
			x += ft_putchar_len(temp + 48);
		else
		{
			if (mode && mode)
				x += ft_putchar_len(temp + 55);
			else
				x += ft_putchar_len(ft_tolower(temp + 55));
		}
	}
	return (x);
}

int	ft_putstr_len(char *str)
{
	int	iterator;

	if (!str)
		return (ft_putstr_len("(null)"));
	iterator = 0;
	while (str[iterator] != '\0')
	{
		write(1, &str[iterator], 1);
		++iterator;
	}
	return (iterator);
}

int	ft_putnbr_len(int nb)
{
	int	x;

	x = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		x += ft_putchar_len('-');
		nb *= (-1);
	}
	if (nb < 10)
		return (ft_putchar_len(nb + '0'));
	x += ft_putnbr_len(nb / 10);
	x += ft_putnbr_len((nb % 10));
	return (x);
}

int	ft_unsigned_putnbr(unsigned int nb)
{
	int	x;

	x = 0;
	if (nb < 10)
		return (ft_putchar_len(nb + '0'));
	x += ft_unsigned_putnbr(nb / 10);
	x += ft_unsigned_putnbr((nb % 10));
	return (x);
}

int	ft_putvoid(size_t ptr)
{
	int	x;

	x = 0;
	ft_putstr("0x");
	x += ft_puthex((size_t)ptr, 0);
	return (x + 2);
}
