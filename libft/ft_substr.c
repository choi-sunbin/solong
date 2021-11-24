/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:38:33 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/11/24 21:24:31 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub_str;
	size_t		str_len;

	sub_str = ft_calloc(sizeof(char), len + 1);
	if (s == 0)
		return (0);
	str_len = ft_strlen(s);
	if (str_len <= start)
		return (ft_strdup(""));
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
