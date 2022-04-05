/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:31:04 by jkwak             #+#    #+#             */
/*   Updated: 2022/01/10 20:53:12 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len(long long int n)
{
	int	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	nbr_sign(long long int n)
{
	if (n > 0)
		return (1);
	else
		return (-1);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	int				len;
	int				sign;
	long long int	nb;

	nb = (long long int)n;
	if (nb == 0)
		return (ft_strdup("0"));
	len = nbr_len(nb);
	sign = nbr_sign(nb);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	*(nbr + len--) = 0;
	if (nb < 0)
		nb = -nb;
	while (len >= 0)
	{
		*(nbr + len) = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	if (sign < 0)
		*(nbr + 0) = '-';
	return (nbr);
}
