/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 21:36:08 by sunbchoi          #+#    #+#             */
/*   Updated: 2020/12/23 21:36:14 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int fill_char, size_t size)
{
	size_t loop;

	loop = 0;
	while (loop < size)
	{
		((unsigned char*)dest)[loop] = (unsigned char)fill_char;
		loop++;
	}
	return (dest);
}
