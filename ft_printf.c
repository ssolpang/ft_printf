/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:10:26 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/26 01:04:20 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	char	*s;
	va_list	ap;

	i = 0;
	s = malloc(sizeof(int));
	if (!s)
		return (0);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				*s = va_arg(ap, int);
				write(1, s, 1);
			}
			else if (format[i + 1] == 'd')
			{
				*s = va_arg(ap, int);
				ft_putstr_fd(ft_itoa(*s), 1);
			}
			i += 2;
		}
		write(1, &format[i], 1);
		i++;
	}
	return (0);
}
