/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/15 12:07:06 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/15 17:07:59 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_puthex(size_t nb, unsigned int mode)
{
	size_t	temp;

	if (nb != 0)
	{
		ft_puthex(nb / 16, mode);
		temp = nb % 16;
		if (temp < 10)
			ft_putchar(temp + 48);
		else
		{
			if (mode && mode)
				ft_putchar(temp + 55);
			else
				ft_putchar(ft_tolower(temp + 55));
		}
	}
}

void	ft_unsigned_putnbr(unsigned int nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		return ;
	}	
	ft_putnbr(nb / 10);
	ft_putnbr((nb % 10));
}

void	ft_putvoid(size_t ptr)
{
	ft_putstr("0x");
	ft_puthex((size_t)ptr, 0);
}
