/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:13:20 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/01/17 14:14:50 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_print_char(const char ch);
int	ft_print_str(const char *s);
int	ft_print_int(int n);
int	ft_print_precent(void);
int	ft_print_hex(unsigned int n, const char format);
int	ft_print_unsigned(unsigned int n);
int	ft_printf(const char *format, ...);
int	ft_print_ptr(unsigned long long ptr);

#endif
