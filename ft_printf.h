/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:11:09 by thabeck-          #+#    #+#             */
/*   Updated: 2022/06/09 14:19:08 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_findform(va_list arg, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_baseuint(unsigned int nb);
char	*ft_uitoa(unsigned int n);
int		ft_printuint(unsigned int n);
int		ft_convertptr(unsigned long n);
int		ft_printptr(unsigned long n);
int		ft_basehex(unsigned int nb);
void	ft_converthex(unsigned int nb, const char format);
int		ft_printhex(unsigned int nb, const char format);

#endif
