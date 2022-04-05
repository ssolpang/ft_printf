/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:35:42 by jkwak             #+#    #+#             */
/*   Updated: 2022/01/11 18:26:01 by jkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	word_clear(char **grp)
{
	int	i;

	i = 0;
	while (*(grp + i))
	{
		free(*(grp + i));
		i++;
	}
	free(grp);
}

int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			i++;
		else
		{
			count++;
			while (*(s + i) && (*(s + i) != c))
				i++;
		}	
	}
	return (count);
}

char	**word_list(char **grp, char const *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (*(s + i) && (j < word_count(s, c)))
	{
		len = 0;
		while (*(s + i) && (*(s + i) == c))
			i++;
		while (*(s + i) && (*(s + i) != c))
		{
			i++;
			len++;
		}
		*(grp + j) = (char *)malloc(sizeof(char) * (len + 1));
		if (!*(grp + j))
		{
			word_clear(grp);
			return (NULL);
		}
		ft_strlcpy(*(grp + (j++)), (s + i - len), len + 1);
	}
	return (grp);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**grp;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	grp = (char **)malloc(sizeof(char *) * (count + 1));
	if (!grp)
		return (NULL);
	grp = word_list(grp, s, c);
	if (!grp)
		return (NULL);
	*(grp + count) = NULL;
	return (grp);
}
