/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:20:22 by aoteo-be          #+#    #+#             */
/*   Updated: 2021/10/21 16:34:40 by aoteo-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_itoa(unsigned long int n);
int		ft_putunbr_fd(unsigned int n);
int		ft_putnbr_fd(int n);
int		check_chars(const char *format, va_list argp);
int		check_decimals(const char *format, va_list argp);
void	chck_hx(const char *format, va_list argp, int *i);
int		ft_printf(const char *format, ...);
#endif
