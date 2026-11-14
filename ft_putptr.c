/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchouir <abchouir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 09:40:58 by abchouir          #+#    #+#             */
/*   Updated: 2026/11/14 10:43:55 by abchouir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	size_t	res;
	int		count;
	int		ret;

	res = 0;
	count = 0;
	if (!ptr)
	{
		count = ft_putstr("(nil)");
		if (count == -1)
			return (-1);
		return (count);
	}
	res = (size_t)ptr;
	ret = ft_putstr("0x");
	if (ret == -1)
		return (-1);
	count += ret;
	ret = ft_put_hex(res, 'p');
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
