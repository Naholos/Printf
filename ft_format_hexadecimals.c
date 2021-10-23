/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hexadecimals.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:06:51 by aoteo-be          #+#    #+#             */
/*   Updated: 2021/10/22 17:30:43 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dec2hex(char *str, size_t *lst, size_t num, const char *format)
{
	int	offset;
	int	i;
	int	len;

	offset = 7;
	if (*format == 'x' || *format == 'p')
		offset = 39;
	i = 0;
	while (num >= 16)
	{
		lst[i] = num % 16;
		num /= 16;
		i++;
	}
	lst[i] = num;
	len = 0;
	while (len <= i)
	{
		str[len] = (char)(lst[i - len] + '0');
		if (lst[i - len] >= 10)
			str[len] = (char)(str[len] + offset);
		len++;
	}
	return (len);
}

static unsigned long	check_p(va_list argp, int *i)
{
	unsigned long	number;

	number = (unsigned long)va_arg(argp, void *);
	write(1, "0x", 2);
	(*i) = (*i) + 2 ;
	return (number);
}

static long	ch_x(va_list argp)
{
	long	number;

	number = va_arg(argp, unsigned int);
	return (number);
}

void	chck_hx(const char *format, va_list argp, int *i)
{
	char			*string;
	unsigned long	*list;
	long			number;
	int				len;

	if (*format == 'p')
		number = check_p(argp, i);
	else if (*format == 'x' || *format == 'X')
		number = ch_x(argp);
	else
		return ;
	list = malloc(2 * sizeof(unsigned long) * sizeof(unsigned long));
	if (list == NULL)
		exit (-1);
	string = malloc(2 * sizeof(unsigned long) * sizeof(unsigned long));
	if (string == NULL)
		exit (-1);
	len = dec2hex(string, list, number, format);
	free (list);
	write (1, string, len);
	free(string);
	(*i) = (*i) + len;
}
