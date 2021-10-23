/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:54:44 by aoteo-be          #+#    #+#             */
/*   Updated: 2021/10/21 16:35:18 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format_not_percentage(const char *format, int *i)
{
	write(1, format, 1);
	(*i) = (*i) + 1;
}

int	ft_printf(const char *format, ...)
{
	va_list	argp;
	int		i;

	i = 0;
	va_start(argp, format);
	while (*format != '\0')
	{
		if (*format != '%')
			ft_format_not_percentage(format, &i);
		else
		{
			format++;
			i += check_chars(format, argp);
			i += check_decimals(format, argp);
			chck_hx(format, argp, &i);
		}
		format++;
	}
	va_end(argp);
	return (i);
}
