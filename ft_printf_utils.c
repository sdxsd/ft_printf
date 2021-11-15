/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/15 12:07:06 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/15 14:48:37 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_puthex(unsigned int nb, unsigned int mode)
{
	static int	temp;

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

void	ft_putvoid(int ptr)
{
	ft_putstr("0x1");
	ft_puthex((int)ptr, 0);
}
