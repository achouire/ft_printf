/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchouir <abchouir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 09:57:32 by abchouir          #+#    #+#             */
/*   Updated: 2026/11/14 09:15:58 by abchouir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putstr(const char *str);
int	ft_putchar(int c);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int n);
int	ft_put_hex(unsigned long n, char format);
int	ft_putptr(void *ptr);
int	ft_format(char format, va_list args);

#endif