/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konan <konagash@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 11:47:12 by Konan             #+#    #+#             */
/*   Updated: 2021/05/09 18:34:13 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		parse_printf(const char *fmt, va_list list)
{
	int			len;
	char		*head;
	t_flag		flag;

	if (fmt == NULL)
		return (-1);
	len = 0;
	head = (char *)fmt;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			ft_print_str(head, fmt - head);
			get_flags(&fmt, list, &flag);
			len += parse_format(&fmt, list, &flag);
			head = (char *)fmt;
		}
		else
		{
			fmt++;
			len++;
		}
	}
	ft_print_str(head, fmt - head);
	return (len);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		list;
	int			ret;

	va_start(list, fmt);
	ret = parse_printf(fmt, list);
	va_end(list);
	return (ret);
}
