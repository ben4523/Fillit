/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:32:20 by ybitton           #+#    #+#             */
/*   Updated: 2017/01/16 16:41:03 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

void		*ft_memalloc(size_t size)
{
	char	*c;
	size_t	i;

	if ((c = malloc(size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		c[i] = 0;
		i++;
	}
	return (c);
}
