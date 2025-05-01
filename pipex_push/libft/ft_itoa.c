/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:17:55 by jpaselt           #+#    #+#             */
/*   Updated: 2024/11/28 17:01:58 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert(int n, int len)
{
	char	*itoa;
	long	num;

	num = n;
	itoa = (char *)malloc((len + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	if (num < 0)
	{
		itoa[0] = '-';
		num *= -1;
	}
	if (num == 0)
		itoa[0] = '0';
	while (num != 0)
	{
		itoa[len - 1] = (num % 10) + 48;
		num = num / 10;
		len--;
	}
	return (itoa);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	num;

	len = 0;
	num = n;
	if (n == 0)
		return (convert(0, 1));
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	if (n < 0)
		len++;
	return (convert(n, len));
}
