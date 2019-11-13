/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:46:10 by tprevel           #+#    #+#             */
/*   Updated: 2019/10/10 10:56:04 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*out;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(out = malloc(sizeof(char) * len)))
		return (NULL);
	ft_strlcpy(out, s1, ft_strlen(s1) + 1);
	ft_strlcat(out, s2, len);
	return (out);
}
