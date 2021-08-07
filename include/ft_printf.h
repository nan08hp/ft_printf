/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konagash <konagash@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 21:03:47 by konagash          #+#    #+#             */
/*   Updated: 2021/02/08 23:40:23 by konagash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int		flag[2];
	int		field;
	int		width;
	int		prec;
	int		len;
}				t_flag;

int				ft_printf(const char *format, ...);
int				ft_parse_printf(const char *fmt, va_list list);

void			ft_parse_char(va_list list, t_flag *flag);
void			ft_parse_str(va_list list, t_flag *flag);
void			ft_parse_int(va_list list, t_flag *flag);
void			ft_parse_unsigned(va_list list, t_flag *flag);
void			ft_parse_parsent(va_list list, t_flag *flag);
void			ft_parse_hex(const char **fmt, va_list list, t_flag *flag);
void			ft_parse_pointer(va_list list, t_flag *flag);
void			ft_parse_persent(t_flag *flag);

int				parse_format(const char **fmt, va_list list, t_flag *flag);
char			*parse_width(char *s, t_flag *flag);
char			*parse_prec(char *s, t_flag *flag);
char			*parse_fill(char *s, char c, int width);
char			*ft_chr_to_str(char c);

char			*convert_base(unsigned long n, char *base_char);
void			safe_free(void *p);
void			ft_print_str(const char *s, size_t index);
char			*ft_chr_to_str(char c);
char			*ft_uitoa(unsigned int n);

void			get_flags(const char **fmt, va_list list, t_flag *flag);

#endif
