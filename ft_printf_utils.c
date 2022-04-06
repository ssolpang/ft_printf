/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:57:35 by jkwak             #+#    #+#             */
/*   Updated: 2022/04/06 15:45:07 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_len_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char			*nbr;
	int				len;

	if (n == 0)
		return (ft_strdup("0"));
	len = nbr_len_unsigned(n);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	*(nbr + len--) = 0;
	while (len >= 0)
	{
		*(nbr + len) = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (nbr);
}

int	ft_count_digit(unsigned long long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	*ft_itoa_hexa_base(unsigned long long n, int c)
{
	int					digit;
	unsigned long long	temp;
	char				*base;
	char				*adr;

	if (c == 1)
		base = "0123456789abcdef";
	else if (c == 2)
		base = "0123456789ABCDEF";
	digit = ft_count_digit(n);
	adr = (char *)ft_calloc(digit + 1, sizeof(char));
	if (!adr)
		return (NULL);
	digit -= 1;
	while (n != 0)
	{
		temp = n % 16;
		adr[digit] = base[temp];
		n = n / 16;
		digit--;
	}
	return (adr);
}
