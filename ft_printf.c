/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:10:32 by thabeck-          #+#    #+#             */
/*   Updated: 2022/06/09 15:23:27 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_findform(va_list arg, const char format)
{
	int		len;
	char	*nbr;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(arg, int));
	if (format == 's')
		len += ft_printstr(va_arg(arg, char *));
	if (format == 'p')
		len += ft_printptr(va_arg(arg, unsigned long));
	if (format == 'd' || format == 'i')
	{
		nbr = ft_itoa(va_arg(arg, int));
		len += ft_printstr(nbr);
		free(nbr);
	}
	if (format == 'u')
		len += ft_printuint(va_arg(arg, unsigned int));
	if (format == 'x' || format == 'X')
		len += ft_printhex(va_arg(arg, unsigned int), format);
	if (format == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_findform(arg, str[i + 1]);
			i++;
		}
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
