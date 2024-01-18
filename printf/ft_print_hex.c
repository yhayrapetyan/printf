/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:21:57 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/01/17 14:21:59 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	ft_write_hex(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_print_hex(n / 16, format);
		ft_print_hex(n % 16, format);
	}
	else
	{
		if (n < 10)
			ft_print_char((n + '0'));
		else
		{
			if (format == 'x')
				ft_print_char(('a' + n - 10));
			else
				ft_print_char(('A' + n - 10));
		}
	}
}

int	ft_print_hex(unsigned int n, const char format)
{
	if (n == 0)
		write(1, "0", 1);
	else
		ft_write_hex(n, format);
	return (ft_hex_len(n));
}
