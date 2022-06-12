/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:24:03 by thabeck-          #+#    #+#             */
/*   Updated: 2022/06/11 15:24:43 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convertptr(unsigned long n)
{
	char	*hex_base;

	hex_base = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ft_convertptr(n / 16);
		ft_convertptr(n % 16);
	}
	else
		ft_printchar(hex_base[n]);
	free(hex_base);
	return (0);
}

int	ft_printptr(unsigned long n)
{
	int	len;

	len = 1;
	if (n == 0)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	ft_convertptr(n);
	while (n >= 16)
	{
		n = n / 16;
		len++;
	}
	return (len);
}
