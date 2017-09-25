/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:33:06 by ybitton           #+#    #+#             */
/*   Updated: 2017/01/16 16:41:07 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*ft_strnew(size_t size)
{
	char		*c;
	size_t		i;

	c = (char *)ft_memalloc(size + 1);
	if (c == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		c[i] = '\0';
		i++;
	}
	c[i] = '\0';
	return (c);
}
