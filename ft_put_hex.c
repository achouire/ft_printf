/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchouir <abchouir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 09:30:56 by abchouir          #+#    #+#             */
/*   Updated: 2026/11/14 16:47:37 by abchouir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long n, char format)
{
	char	*str_upper;
	char	*str_lower;
	int		count;
	int		res;

	str_lower = "0123456789abcdef";
	str_upper = "0123456789ABCDEF";
	res = 0;
	count = 0;
	if (n >= 16)
	{
		count = ft_put_hex((n / 16), format);
		if (count == -1)
			return (-1);
	}
	if (format == 'X')
		res = ft_putchar(str_upper[n % 16]);
	else
		res = ft_putchar(str_lower[n % 16]);
	if (res == -1)
		return (-1);
	count += res;
	return (count);
}
