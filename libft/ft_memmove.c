/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:33:08 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/01/03 20:21:09 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char		*temp_d;
	const unsigned char	*temp_s;

	if (dest == 0 && src == 0)
		return (0);
	if (dest <= src)
	{
		temp_d = (unsigned char*)dest;
		temp_s = (unsigned char*)src;
		while (size--)
			*temp_d++ = *temp_s++;
	}
	else
	{
		temp_d = (unsigned char*)dest + size;
		temp_s = (unsigned char*)src + size;
		while (size--)
			*--temp_d = *--temp_s;
	}
	return (dest);
}
