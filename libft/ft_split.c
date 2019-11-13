/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:05:08 by tprevel           #+#    #+#             */
/*   Updated: 2019/11/08 16:35:01 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenword(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static size_t	ft_wdc(const char *s, char c)
{
	size_t	wdc;
	size_t	i;

	i = 0;
	wdc = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || (s[i - 1] == c)))
			wdc++;
		i++;
	}
	return (wdc);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	k;
	char	**out;

	i = 0;
	k = 0;
	if (!(out = malloc(sizeof(char *) * (ft_wdc(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || (s[i - 1] == c)))
		{
			if (!(out[k] = ft_substr(s + i, 0, ft_lenword(s + i, c))))
			{
				while (k > 0)
					free(out[k--]);
				free(out);
				return (NULL);
			}
			k++;
		}
		i++;
	}
	out[k] = 0;
	return (out);
}
