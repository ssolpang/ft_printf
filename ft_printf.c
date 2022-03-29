/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:10:26 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/29 16:19:12 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				ft_char_format(ap);
			else if (format[i + 1] == 's')
				ft_string_format(ap);
			else if ((format[i + 1] == 'd') || (format[i + 1] == 'i'))
				ft_decimal_integer_format(ap);
			else if (format[i + 1] == 'p')
				ft_pointer_format(ap);
			else if (format[i + 1] == 'u')
				ft_unsigned_int_format(ap);
			else if ((format[i + 1] == 'x') || (format[i + 1] == 'X'))
			{
				if (format[i + 1] == 'x')
					ft_hexa_format(ap, 'x');
				else if (format[i + 1] == 'X')
					ft_hexa_format(ap, 'X');
			}
			else if (format [i + 1] == '%')
				ft_putchar_fd('%', 1);
			i += 2;
		}
		ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	int a = 1;
	printf("   : 1%, 10% | 2% ,10% | 3%,10% | 4%, 10 | 5% ,10 | 6%,10\n");
	ft_printf("ft : 2%, 10% | 2% ,10% | 2%,10% | 2%, 10 | 2% ,10 | 2%,10\n");
	return (0);
}
