/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:46:09 by aoteo-be          #+#    #+#             */
/*   Updated: 2021/10/21 16:28:48 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_char(const char *format, va_list argp)
{
	char	data;

	if (*format == 'c')
		data = (char)va_arg(argp, int);
	else
		data = *format;
	write(1, &data, 1);
	return (1);
}

static int	ft_format_string(va_list argp)
{
	char	*string;
	size_t	len;

	string = va_arg(argp, char *);
	if (string == NULL)
		string = "(null)";
	len = ft_strlen(string);
	write(1, string, len);
	return ((int)len);
}

int	check_chars(const char *format, va_list argp)
{
	if (*format == '%' || *format == 'c')
		return (ft_format_char(format, argp));
	else if (*format == 's')
		return (ft_format_string(argp));
	else
		return (0);
}
