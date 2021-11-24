/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:58:22 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/11/24 21:24:45 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	check;

	if (c >= 256 || c < 0)
		return (c);
	check = (unsigned char)c;
	if (check >= 'a' && check <= 'z')
		c -= 32;
	return (c);
}
