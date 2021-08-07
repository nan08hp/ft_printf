/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:31:09 by konagash          #+#    #+#             */
/*   Updated: 2021/02/06 09:11:52 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_parse_char(va_list list, t_flag *flag)
{
	char		c;
	char		*s;

	c = va_arg(list, int);
	s = ft_chr_to_str(c);
	if (flag->flag[0] > 0)
		flag->flag[0] = 0;
	if (c == '\0' && flag->width > 0)
		flag->width--;
	if (c == '\0' && flag->flag[1] == 1)
	{
		write(1, &c, 1);
		flag->len++;
	}
	s = parse_width(s, flag);
	ft_putstr_fd(s, 1);
	flag->len += ft_strlen(s);
	if (c == '\0' && flag->flag[1] == 0)
	{
		write(1, &c, 1);
		flag->len++;
	}
	safe_free(s);
}
