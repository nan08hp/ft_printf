/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:35:56 by konagash          #+#    #+#             */
/*   Updated: 2020/11/27 00:32:53 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			cnt_word(char const *s, char c)
{
	int		cnt;

	cnt = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		cnt++;
	}
	return (cnt);
}

static int			cnt_char(char const *s, char c)
{
	int		cnt;

	cnt = 0;
	while (s[cnt] != c && s[cnt])
		cnt++;
	return (cnt);
}

static char			**free_malloc(char **result, size_t index)
{
	size_t		i;

	i = 0;
	while (i < index)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char				**ft_split(char const *s, char c)
{
	char		**result;
	int			words;
	int			i;
	int			j;

	i = 0;
	if (!s)
		return (NULL);
	words = cnt_word(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		while (*s == c && *s)
			s++;
		if (!(result[i] = (char *)malloc(sizeof(char) * (cnt_char(s, c) + 1))))
			return (free_malloc(result, i));
		j = 0;
		while (*s != c && *s)
			result[i][j++] = *s++;
		result[i][j] = '\0';
		i++;
	}
	result[i] = NULL;
	return (result);
}
