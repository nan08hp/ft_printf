/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konan <konagash@student.42tokyo.jp>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:02:39 by Konan             #+#    #+#             */
/*   Updated: 2021/02/09 00:27:07 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			parse_format(const char **fmt, va_list list, t_flag *flag)
{
	if (**fmt == 'c')
		ft_parse_char(list, flag);
	else if (**fmt == 's')
		ft_parse_str(list, flag);
	else if (**fmt == 'i' || **fmt == 'd')
		ft_parse_int(list, flag);
	else if (**fmt == 'u')
		ft_parse_unsigned(list, flag);
	else if (**fmt == '%')
		ft_parse_persent(flag);
	else if (**fmt == 'x' || **fmt == 'X')
		ft_parse_hex(fmt, list, flag);
	else if (**fmt == 'p')
		ft_parse_pointer(list, flag);
	else if (**fmt == '\0')
		return (flag->len);
	else
		write(1, *fmt, 1);
	(*fmt)++;
	return (flag->len);
}

char		*parse_fill(char *s, char c, int width)
{
	char		*ret;
	int			i;
	int			len;

	if (width > 0)
	{
		if ((len = width - ft_strlen(s)) < 0)
			len = 0;
		if ((ret = malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		i = 0;
		while (i < len)
		{
			ret[i] = c;
			i++;
		}
		ret[i] = '\0';
	}
	else
	{
		if ((ret = malloc(sizeof(char))) == NULL)
			return (NULL);
		ret[0] = '\0';
	}
	return (ret);
}

char		*parse_width(char *s, t_flag *flag)
{
	char		*fill;
	char		*tmp;

	if (flag->width < 0)
		fill = parse_fill(s, ' ', -flag->width);
	else if (flag->flag[1] > 0)
		fill = parse_fill(s, ' ', flag->width);
	else if (flag->flag[0] > 0 && flag->prec != 0)
		fill = parse_fill(s, '0', flag->width);
	else
		fill = parse_fill(s, ' ', flag->width);
	if ((flag->flag[1] > 0 && flag->width > 0) || flag->width < 0)
	{
		tmp = s;
		s = ft_strjoin(s, fill);
		safe_free(tmp);
	}
	else if (flag->width >= 0)
	{
		tmp = s;
		s = ft_strjoin(fill, s);
		safe_free(tmp);
	}
	safe_free(fill);
	return (s);
}

char		*parse_prec(char *s, t_flag *flag)
{
	char		*fill;
	char		*tmp;

	fill = parse_fill(s, '0', flag->prec);
	if (flag->prec > 0)
	{
		tmp = s;
		s = ft_strjoin(fill, s);
		safe_free(tmp);
		flag->flag[0] = -1;
	}
	safe_free(fill);
	return (s);
}
