/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:31:57 by konagash          #+#    #+#             */
/*   Updated: 2021/02/06 21:09:07 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char			*ft_toupper_str(char *s)
{
	int			i;
	char		*res;

	if ((res = malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = s[i];
	free(s);
	s = NULL;
	return (res);
}

void			ft_parse_hex(const char **fmt, va_list list, t_flag *flag)
{
	unsigned int	n;
	char			*hex;

	n = va_arg(list, unsigned int);
	if (n == 0 && flag->prec == 0)
		hex = ft_strdup("");
	else if (**fmt == 'x')
		hex = convert_base((unsigned int)n, "0123456789abcdef");
	else
		hex = convert_base((unsigned int)n, "0123456789ABCDEF");
	hex = parse_prec(hex, flag);
	hex = parse_width(hex, flag);
	ft_putstr_fd(hex, 1);
	flag->len += ft_strlen(hex);
	safe_free(hex);
}
