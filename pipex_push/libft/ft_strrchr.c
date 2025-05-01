/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:06:06 by jpaselt           #+#    #+#             */
/*   Updated: 2024/11/28 17:03:52 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			n = i;
		i++;
	}
	if ((unsigned char)s[n] == (unsigned char)c)
		return ((char *)s + n);
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}
