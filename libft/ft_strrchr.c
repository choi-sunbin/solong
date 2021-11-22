/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:54:32 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/01/02 17:46:17 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *dest, int check)
{
	char			*save_point;
	unsigned char	check_char;

	save_point = 0;
	check_char = (unsigned char)check;
	while (1)
	{
		if (*dest == (char)check)
			save_point = (char*)dest;
		if (*dest == 0)
			return (save_point);
		dest++;
	}
	return (0);
}
