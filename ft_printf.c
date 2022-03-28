/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:10:26 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/28 21:26:47 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# include <stdio.h>

int	ft_printf(const char *format, ...)
{
	int		i;
	int		n;
	char	*s;
	size_t	nb;
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
				ap = ft_char_format(ap);
			else if (format[i + 1] == 's')
				ap = ft_string_format(ap);
			else if ((format[i + 1] == 'd') || (format[i + 1] == 'i'))
			{
				n = va_arg(ap, int);
				ft_putstr_fd(ft_itoa(n), 1);
			}
			else if (format[i + 1] == 'p')
			{
				nb = (size_t)va_arg(ap, void *);
				ft_putstr_fd("0x", 1);
				ft_putstr_fd(ft_itoa_hexa_base(nb, 1), 1);
			}
			else if (format[i + 1] == 'u')
			{
				nb = va_arg(ap, unsigned int);
				ft_putstr_fd(ft_itoa_unsigned(nb), 1);
			}
			else if ((format[i + 1] == 'x') || (format[i + 1] == 'X'))
			{
				nb = va_arg(ap, unsigned int);
				if (format[i + 1] == 'x')
					ft_putstr_fd(ft_itoa_hexa_base(nb, 1), 1);
				else if (format[i + 1] == 'X')
					ft_putstr_fd(ft_itoa_hexa_base(nb, 2), 1);
			}
			else if (format [i + 1] == '%')
			{
				ft_putchar_fd('%' ,1);
			}
			i += 2;
		}
		write(1, &format[i], 1);
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
