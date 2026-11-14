/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchouir <abchouir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 15:58:34 by abchouir          #+#    #+#             */
/*   Updated: 2026/11/12 09:54:59 by abchouir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	count;
	int	res;

	res = 0;
	count = 0;
	if (n > 9)
	{
		count = ft_putunbr(n / 10);
		if (count == -1)
			return (-1);
	}
	res = ft_putchar((n % 10) + '0');
	if (res == -1)
		return (-1);
	count += res;
	return (count);
}
