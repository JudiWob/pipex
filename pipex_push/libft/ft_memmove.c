/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:23:02 by jpaselt           #+#    #+#             */
/*   Updated: 2024/11/28 17:02:37 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr_s;
	unsigned char		*ptr_d;

	ptr_s = (const unsigned char *)src;
	ptr_d = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (src > dest)
		ft_memcpy(dest, src, n);
	else
		while (n--)
			ptr_d[n] = ptr_s[n];
	return (dest);
}
