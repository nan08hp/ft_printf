/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parsent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:32:12 by konagash          #+#    #+#             */
/*   Updated: 2021/02/07 23:13:42 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_parse_persent(t_flag *flag)
{
	char		*s;
	char		*fill;
	char		*tmp;

	s = ft_strdup("%");
	if (flag->prec == 0)
	{
		fill = parse_fill(s, '0', flag->width);
		tmp = s;
		s = ft_strjoin(fill, s);
		safe_free(tmp);
		safe_free(fill);
	}
	else
		s = parse_width(s, flag);
	flag->len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	safe_free(s);
}
