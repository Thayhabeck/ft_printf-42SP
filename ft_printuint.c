/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:36:23 by thabeck-          #+#    #+#             */
/*   Updated: 2022/06/09 14:17:21 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_baseuint(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*nb;
	int		len;

	len = ft_baseuint(n);
	nb = (char *)malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (0);
	nb[len] = '\0';
	while (n != 0)
	{
		nb[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (nb);
}

int	ft_printuint(unsigned int n)
{
	int		len;
	char	*nb;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		nb = ft_uitoa(n);
		len += ft_printstr(nb);
		free(nb);
	}
	return (len);
}
