/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchouir <abchouir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:54:12 by abchouir          #+#    #+#             */
/*   Updated: 2026/11/14 16:47:58 by abchouir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long	n;
	int		count;
	int		res;

	count = 0;
	n = nb;
	if (n < 0)
	{
		count = ft_putchar('-');
		if (count == -1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		res = ft_putnbr(n / 10);
		if (res == -1)
			return (-1);
		count += res;
	}
	res = ft_putchar((n % 10) + '0');
	if (res == -1)
		return (-1);
	count += res;
	return (count);
}
