/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:32:26 by konagash          #+#    #+#             */
/*   Updated: 2021/02/09 13:59:40 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*add_prefix(char *res)
{
	char	*tmp;

	tmp = res;
	res = ft_strjoin("0x", res);
	safe_free(tmp);
	return (res);
}

void		ft_parse_pointer(va_list list, t_flag *flag)
{
	unsigned long		p;
	char				*res;
	char				*tmp;

	p = (unsigned long)va_arg(list, void*);
	res = convert_base(p, "0123456789abcdef");
	if (flag->prec == 0)
	{
		tmp = res;
		res = ft_substr(res, 0, flag->prec);
		safe_free(tmp);
	}
	res = parse_prec(res, flag);
	res = add_prefix(res);
	res = parse_width(res, flag);
	ft_putstr_fd(res, 1);
	flag->len += ft_strlen(res);
	safe_free(res);
}
