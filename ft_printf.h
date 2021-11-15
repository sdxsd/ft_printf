/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/12 16:40:01 by wmaguire      #+#    #+#                 */
/*   Updated: 2021/11/15 14:48:46 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
int		handle_variable(const char *spec, va_list arglist);
void	ft_puthex(unsigned int nb, unsigned int mode);
void	ft_putvoid(int ptr);

#endif