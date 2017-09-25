/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:54:17 by ybitton           #+#    #+#             */
/*   Updated: 2017/01/16 16:41:04 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destination;
	char		*srccc;

	srccc = (char*)src;
	destination = (char*)dest;
	while (n-- > 0)
		*destination++ = *srccc++;
	return (dest);
}
