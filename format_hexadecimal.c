/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:04:45 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/29 16:05:33 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer_format(va_list ap)
{
	size_t	n;
	char	*s;

	n = (size_t)va_arg(ap, void *);
	ft_putstr_fd("0x", 1);
	s = ft_itoa_hexa_base(n, 1);
	ft_putstr_fd(s, 1);
	free(s);
}

void	ft_hexa_format(va_list ap, char c)
{
	unsigned int	n;
	char			*s;

	n = va_arg(ap, unsigned int);
	if (c == 'x')
		s = ft_itoa_hexa_base(n, 1);
	else if (c == 'X')
		s = ft_itoa_hexa_base(n, 2);
	ft_putstr_fd(s, 1);
	free(s);
}