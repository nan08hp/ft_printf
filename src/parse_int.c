/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:31:30 by konagash          #+#    #+#             */
/*   Updated: 2021/02/07 23:47:41 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*add_sign(char *n)
{
	char		*tmp;

	tmp = n;
	n = ft_strjoin("-", n);
	safe_free(tmp);
	return (n);
}

void		ft_parse_int(va_list list, t_flag *flag)
{
	char		*n;
	long		num;

	num = va_arg(list, int);
	if (num == 0 && flag->prec == 0)
		n = ft_strdup("");
	else if (num < 0)
		n = ft_uitoa(-num);
	else
		n = ft_uitoa(num);
	n = parse_prec(n, flag);
	if (num < 0 && (flag->flag[0] != 1 || flag->prec == 0))
		n = add_sign(n);
	else if (num < 0 && flag->width > 0)
		flag->width--;
	else if (num < 0 && flag->width < 0)
		flag->width++;
	n = parse_width(n, flag);
	if (num < 0 && flag->flag[0] == 1 && flag->prec != 0)
		n = add_sign(n);
	ft_putstr_fd(n, 1);
	flag->len += ft_strlen(n);
	safe_free(n);
}
