/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:31:43 by konagash          #+#    #+#             */
/*   Updated: 2021/02/06 21:10:05 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_parse_unsigned(va_list list, t_flag *flag)
{
	char				*u;
	unsigned int		num;

	num = va_arg(list, unsigned int);
	if (num == 0 && flag->prec == 0)
		u = ft_strdup("");
	else
		u = ft_uitoa(num);
	u = parse_prec(u, flag);
	u = parse_width(u, flag);
	ft_putstr_fd(u, 1);
	flag->len = ft_strlen(u);
	safe_free(u);
}
