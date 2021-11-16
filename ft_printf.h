/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/12 16:40:01 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/16 11:38:21 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	handle_variable(const char *spec, va_list arglist);
int	ft_puthex(size_t nb, unsigned int mode);
int	ft_putvoid(size_t ptr);
int	ft_unsigned_putnbr(unsigned int nb);
int	ft_putstr_len(char *str);
int	ft_putnbr_len(int nb);
int	ft_putchar_len(char c);

#endif