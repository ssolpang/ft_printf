/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:57:35 by jkwak             #+#    #+#             */
/*   Updated: 2022/04/05 18:54:31 by jkwak            ###   ########.fr       */
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

char	*cut_front_zero(char *adr, int i)
{
	char	*s;
	int		temp;

	s = (char *)malloc(sizeof(char) * (16 - i));
	if (!s)
		return (NULL);
	temp = 0;
	while (i < 16)
	{
		s[temp] = adr[i + 1];
		temp++;
		i++;
	}
	free(adr);
	return (s);
}

char	*ft_itoa_hexa_base(size_t n, int c)
{
	int		i;
	size_t	temp;
	char	*base;
	char	*adr;

	if (n == 0)
		return ("0");
	if (c == 1)
		base = "0123456789abcdef";
	else if (c == 2)
		base = "0123456789ABCDEF";
	adr = (char *)ft_calloc(17, sizeof(char));
	if (!adr)
		return (NULL);
	i = 16;
	while (n != 0)
	{
		temp = n % 16;
		adr[i] = base[temp];
		n = n / 16;
		(i)--;
	}
	adr = cut_front_zero(adr, i);
	return (adr);
}
