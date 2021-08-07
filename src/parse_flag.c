/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:44:03 by konagash          #+#    #+#             */
/*   Updated: 2021/02/06 21:10:41 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		init_flags(t_flag *flags)
{
	flags->flag[0] = 0;
	flags->flag[1] = 0;
	flags->width = 0;
	flags->prec = -1;
	flags->len = 0;
}

int			segment_flag(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void		set_param(int *param, va_list list, const char **fmt)
{
	int		num;

	num = 0;
	if (**fmt == '*')
	{
		*param = va_arg(list, int);
		(*fmt)++;
	}
	else
	{
		while (ft_isdigit(**fmt))
		{
			num = (num * 10) + (**fmt - '0');
			(*fmt)++;
		}
		*param = num;
	}
}

void		get_flags(const char **fmt, va_list list, t_flag *flag)
{
	int	index;

	(*fmt)++;
	init_flags(flag);
	while ((index = segment_flag("0-", **fmt)) >= 0)
	{
		flag->flag[index] = 1;
		(*fmt)++;
	}
	set_param(&flag->width, list, fmt);
	if (**fmt == '.')
	{
		(*fmt)++;
		set_param(&flag->prec, list, fmt);
	}
}
