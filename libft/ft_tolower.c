/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:01:42 by sunbchoi          #+#    #+#             */
/*   Updated: 2020/12/28 18:26:09 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	unsigned char check;

	if (c >= 256 || c < 0)
		return (c);
	check = (unsigned char)c;
	if (check >= 'A' && check <= 'Z')
		c += 32;
	return (c);
}
