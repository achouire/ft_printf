/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchouir <abchouir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:57:01 by abchouir          #+#    #+#             */
/*   Updated: 2026/11/14 10:17:12 by abchouir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_char(const char *format, va_list args)
{
	if (format[0] == '%' && !format[1])
		return (-1);
	if (format[0] == '%')
		return (ft_format (format[1], args));
	else
		return (ft_putchar (format[0]));
}

static void	ft_moving_index(const char *format, size_t *i)
{
	if (format[*i] == '%')
		(*i)++;
	(*i)++;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;
	int		res;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		res = ft_print_char(&format[i], args);
		if (res == -1)
		{
			va_end(args);
			return (-1);
		}
		count += res;
		ft_moving_index(format, &i);
	}
	va_end(args);
	return (count);
}
