/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:15:14 by aoteo-be          #+#    #+#             */
/*   Updated: 2021/10/22 18:46:01 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int static	ft_check_zero(long long_n)
{
	if (long_n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

int static	ft_check_sign(long *long_n)
{
	if (*long_n < 0)
	{
		write(1, "-", 1);
		(*long_n) = -(*long_n);
		return (1);
	}
	return (0);
}	

int	ft_putunbr_fd(unsigned int n)
{
	unsigned int	divisor;
	int				i;
	char			digit;

	i = 0;
	divisor = 1000000000;
	if (ft_check_zero((long)n))
		i++;
	else
	{	
		while (!(n / divisor))
			divisor = divisor / 10;
		while (divisor > 0 )
		{
			digit = (char)(n / divisor + '0');
			write(1, &digit, 1);
			n %= divisor;
			divisor = divisor / 10;
			i++;
		}
	}
	return (i);
}

int	ft_putnbr_fd(int n)
{
	int		divisor;
	int		i;
	char	digit;
	long	long_n;

	i = 0;
	long_n = n;
	divisor = 1000000000;
	if (ft_check_zero((long)n))
		i = 1;
	else
	{	
		i += ft_check_sign(&long_n);
		while (!(long_n / divisor))
			divisor = divisor / 10;
		while (divisor > 0 )
		{
			digit = (char)(long_n / divisor + '0');
			write(1, &digit, 1);
			long_n %= divisor;
			divisor = divisor / 10;
			i++;
		}
	}
	return (i);
}	
