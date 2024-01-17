/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:46:01 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/01/16 15:46:03 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	int	printed_len;

	printed_len = 0;
	if (format == 'c')
		printed_len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		printed_len += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		printed_len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'i' || format == 'd')
		printed_len += ft_print_int(va_arg(args, int));
	else if (format == 'u')
		printed_len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		printed_len += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		printed_len += ft_print_precent();
	return (printed_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed_len;

	if (!format)
		return (0);
	va_start(args, format);
	i = 0;
	printed_len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			printed_len += ft_format(args, format[i + 1]);
			i++;
		}
		else
			printed_len += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (printed_len);
}
