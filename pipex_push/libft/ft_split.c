/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:48:14 by jpaselt           #+#    #+#             */
/*   Updated: 2025/04/27 15:23:10 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_split(char const *s, char c);
static int		count_len(const char *s, char c);
static int		count_words(char const *s, char c);
static char		*make_space(int len);
static void		ft_free(char **charr, int j);

static int	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	count_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void	ft_free(char **charr, int j)
{
	while (j > 0)
	{
		free(charr[j - 1]);
		j--;
	}
	free(charr);
}

static char	*make_space(int len)
{
	char	*charr;

	charr = (char *)malloc((len + 1) * sizeof(char));
	if (!charr)
		return (NULL);
	return (charr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**charr;

	if (!s)
		return (NULL);
	charr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!charr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			charr[j] = make_space(count_len(s + i, c));
			if (!charr[j])
				return (ft_free(charr, j), NULL);
			ft_strlcpy(charr[j], s + i, count_len(s + i, c) + 1);
			j++;
		}
		i++;
	}
	charr[j] = NULL;
	return (charr);
}
