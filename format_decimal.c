/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:32:48 by jkwak             #+#    #+#             */
/*   Updated: 2022/03/31 20:53:43 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_decimal_integer_format(va_list ap)
{
	int		n;
	char	*s;

	n = va_arg(ap, int);
	s = ft_itoa(n);
	ft_putstr_fd(s, 1);
	free(s);
}

void	ft_unsigned_int_format(va_list ap)
{
	unsigned int	n;
	char			*s;

	n = va_arg(ap, unsigned int);
	s = ft_itoa_unsigned(n);
	ft_putstr_fd(s, 1);
	free(s);
}
