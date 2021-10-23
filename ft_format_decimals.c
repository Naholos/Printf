/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_decimals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:04:55 by aoteo-be          #+#    #+#             */
/*   Updated: 2021/10/22 17:31:45 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_di(va_list argp)
{
	long int	number;
	int			i;

	number = va_arg(argp, int);
	i = ft_putnbr_fd(number);
	return (i);
}

static int	ft_format_u(va_list argp)
{
	unsigned long	number;
	int				i;

	number = va_arg(argp, unsigned int);
	i = ft_putunbr_fd(number);
	return (i);
}

int	check_decimals(const char *format, va_list argp)
{
	if (*format == 'd' || *format == 'i')
		return (ft_format_di(argp));
	if (*format == 'u')
		return (ft_format_u(argp));
	else
		return (0);
}
