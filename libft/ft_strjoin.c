/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:27:00 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/11/24 21:23:03 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (s1 == 0 && s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)ft_calloc(sizeof(char), s1_len + s2_len + 1);
	if (str == 0)
		return (0);
	ft_memcpy(str, s1, s1_len);
	ft_strlcat(str, s2, s1_len + s2_len + 1);
	return (str);
}
