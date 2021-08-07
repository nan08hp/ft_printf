/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:31:20 by konagash          #+#    #+#             */
/*   Updated: 2021/02/06 21:08:19 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_parse_str(va_list list, t_flag *flag)
{
	char	*s;
	char	*tmp;

	s = va_arg(list, char*);
	if (s == NULL)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(s);
	if (flag->prec >= 0)
	{
		tmp = s;
		s = ft_substr(s, 0, flag->prec);
		safe_free(tmp);
	}
	s = parse_width(s, flag);
	ft_putstr_fd(s, 1);
	flag->len += ft_strlen(s);
	safe_free(s);
}
