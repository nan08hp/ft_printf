/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konan <konagash@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:39:35 by Konan             #+#    #+#             */
/*   Updated: 2021/02/06 16:58:02 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_digit_base(unsigned long n, unsigned int base)
{
	int		digit;

	digit = 1;
	while (n >= base)
	{
		n /= base;
		digit++;
	}
	return (digit);
}

char		*convert_base(unsigned long n, char *base_char)
{
	char					*res;
	int						digit;
	unsigned int			base;

	if (base_char == NULL)
		return (NULL);
	base = ft_strlen(base_char);
	digit = ft_digit_base(n, base);
	if (!(res = malloc(sizeof(char) * (digit + 1))))
		return (NULL);
	res[digit] = '\0';
	while (digit-- > 0)
	{
		res[digit] = base_char[n % base];
		n /= base;
	}
	return (res);
}
