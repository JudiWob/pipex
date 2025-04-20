/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:22:04 by jpaselt           #+#    #+#             */
/*   Updated: 2024/11/28 17:02:35 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_s;
	unsigned char	*ptr_d;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr_s = (unsigned char *) src;
	ptr_d = (unsigned char *) dest;
	while (n--)
		*ptr_d++ = *ptr_s++;
	return (dest);
}
