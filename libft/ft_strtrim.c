/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 08:19:36 by jkwak             #+#    #+#             */
/*   Updated: 2022/01/10 20:41:23 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_start(char const *s1, char const *set)
{
	int	start;
	int	i;

	start = 0;
	while (*(s1 + start))
	{
		i = 0;
		while (*(set + i))
		{
			if (*(s1 + start) == *(set + i))
				break ;
			else
				i++;
		}
		if (*(set + i) == 0)
			return (start);
		else
			start++;
	}
	return (start);
}

int	find_end(int check, char const *s1, char const *set)
{
	int	end;
	int	i;

	end = check;
	while (*(s1 + check))
	{
		i = 0;
		while (*(set + i))
		{
			if (*(s1 + check) == *(set + i))
				break ;
			else
				i++;
		}
		if (*(set + i) == 0)
			end = check;
		check++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*new_str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = find_start(s1, set);
	if (!*(s1 + start))
		return (ft_strdup(""));
	end = find_end(start, s1, set);
	new_str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!new_str)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		*(new_str + i) = *(s1 + start);
		i++;
		start++;
	}
	*(new_str + i) = 0;
	return (new_str);
}
