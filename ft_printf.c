/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:10:26 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/27 15:41:43 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int		i;
	char	*s;
	int		nb;
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
				ft_putchar_fd(*s, 1);
			}
			else if (format[i + 1] == 'd')
			{
				nb = va_arg(ap, int);
				ft_putstr_fd(ft_itoa(nb), 1);
			}
			else if (format[i + 1] == 's')
			{
				s = va_arg(ap, char *);
				ft_putstr_fd(s, 1);
			}
			else if (format[i + 1] == 'p')
			{
				nb = va_arg(ap, int);
				ft_putstr_fd(ft_itoa_hexa_base(nb), 1);
			}
			i += 2;
		}
		write(1, &format[i], 1);
		i++;
	}
	return (0);
}

int	main(void)
{
	int	a = 1;
	printf("%p\n", &a);
	ft_printf("%p\n", &a);
	return (0);
}
