/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:28:59 by tprevel           #+#    #+#             */
/*   Updated: 2019/11/04 16:23:02 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	if (dst == NULL || src == NULL)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	i = -1;
	while (++i < dstsize - 1 && src[i] != '\0')
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}
