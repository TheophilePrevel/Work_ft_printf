/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprevel <tprevel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:13:34 by tprevel           #+#    #+#             */
/*   Updated: 2019/11/09 17:13:38 by tprevel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*out;

	if (!(out = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	out->content = content;
	out->next = NULL;
	return (out);
}
