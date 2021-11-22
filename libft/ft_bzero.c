/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:37:46 by sunbchoi          #+#    #+#             */
/*   Updated: 2020/12/23 21:26:59 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *dest, size_t size)
{
	size_t loop;

	loop = 0;
	while (loop < size)
	{
		((unsigned char*)dest)[loop] = 0;
		loop++;
	}
	return (dest);
}
