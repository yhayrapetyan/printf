/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:41:50 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/01/17 14:41:52 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void	ft_put_ptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_print_char(('0' + ptr));
		else
			ft_print_char(('a' + ptr - 10));
	}
}

static int	ft_ptr_len(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
		return (0);
	while (ptr)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	printed_len;

	printed_len = 0;
	printed_len += write(1, "0x", 2);
	if (ptr == 0)
		printed_len += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		printed_len += ft_ptr_len(ptr);
	}
	return (printed_len);
}
