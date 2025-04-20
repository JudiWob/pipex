/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:56:09 by jpaselt           #+#    #+#             */
/*   Updated: 2024/11/28 17:03:15 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;
	size_t	n;

	dst_len = ft_strlen(dst);
	n = dst_len;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size < dst_len)
		return (ft_strlen(src) + size);
	while (src[i] && (n + i) < size - 1)
	{
		dst[n + i] = src[i];
		i++;
	}
	dst[n + i] = '\0';
	return (ft_strlen(src) + dst_len);
}
