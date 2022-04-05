/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:04:45 by jkwak             #+#    #+#             */
/*   Updated: 2022/04/05 21:31:35 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_format(va_list ap, int count)
{
	unsigned long long	n;
	char				*s;

	n = (unsigned long long)va_arg(ap, void *);
	ft_putstr_fd("0x", 1);
	count += 2;
	if (n == 0)
		s = ft_strdup("0");
	else
		s = ft_itoa_hexa_base(n, 1);
	count += ft_strlen(s);
	ft_putstr_fd(s, 1);
	if (s)
		free(s);
	return (count);
}

int	ft_hexa_format(va_list ap, char c, int count)
{
	unsigned int	n;
	char			*s;

	n = va_arg(ap, unsigned int);
	if (n == 0)
		s = ft_strdup("0");
	else
	{
		if (c == 'x')
			s = ft_itoa_hexa_base(n, 1);
		else
			s = ft_itoa_hexa_base(n, 2);
	}
	count += ft_strlen(s);
	ft_putstr_fd(s, 1);
	if (s)
		free(s);
	return (count);
}
