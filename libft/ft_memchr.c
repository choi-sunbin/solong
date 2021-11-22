/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:30:01 by sunbchoi          #+#    #+#             */
/*   Updated: 2020/12/31 00:20:36 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *dest, int find_char, size_t size)
{
	size_t loop;

	loop = 0;
	while (loop < size)
	{
		if (((unsigned char*)dest)[loop] == (unsigned char)find_char)
			return (&((unsigned char*)dest)[loop]);
		loop++;
	}
	return (0);
}
