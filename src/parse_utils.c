/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:49:33 by konagash          #+#    #+#             */
/*   Updated: 2021/02/06 00:12:03 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		safe_free(void *p)
{
	free(p);
	p = NULL;
}

char		*ft_chr_to_str(char c)
{
	char	*s;

	if ((s = (malloc(sizeof(char) * 2))) == NULL)
		return (NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

void		ft_print_str(const char *s, size_t index)
{
	size_t		i;

	if (s == NULL)
		return ;
	i = 0;
	while (i < index && s[i] != '\0')
		i++;
	write(1, s, i);
}

static int	count_digit(unsigned int n)
{
	int			digit;

	digit = 1;
	while (n > 9)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char		*ft_uitoa(unsigned int n)
{
	char		*result;
	int			i;
	int			digit;

	i = 0;
	digit = count_digit(n);
	if (!(result = (char *)malloc(sizeof(char) * (digit + 1))))
		return (NULL);
	while (n > 9)
	{
		result[digit - i - 1] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	result[digit - i - 1] = (n % 10) + '0';
	result[digit] = '\0';
	return (result);
}
