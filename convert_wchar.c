/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:30:57 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/13 16:31:00 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		size_wchar(wchar_t w)
{
	if (w <= 127)
		return (1);
	else if (w <= 2047)
		return (2);
	else if (w <= 65535)
		return (3);
	else if (w <= 2097151)
		return (4);
	return (0);
}

char	*wchar_conv(wchar_t w, t_magic *m, size_t i)
{
	int		size;
	char	*buf;

	size = size_wchar(w);
	buf = ft_strnew(size);
	if (m->w_str)
		m->w_str[i] = (char)size;
	if (size == 1)
		buf[0] = (char)w;
	else
		buf[0] = (w >> (6 * (size - 1))) | (240 << (4 - size));
	while (--size > 0)
	{
		buf[size] = (w & 63) | 128;
		w = w >> 6;
	}
	return (buf);
}

void 	realoc_wstr(t_magic *m, size_t r)
{
	char 	*tmp;

	tmp = ft_strnew(50 * r);
	tmp = ft_strcpy(tmp, m->w_str);
	ft_strdel(&m->w_str);
	m->w_str = ft_strdup(tmp);
	ft_strdel(&tmp);
}

void	wstr_conv(wchar_t *arg, t_magic *m)
{
	char 	*tmp;
	char 	*w_char;
	size_t	i;
	size_t	r;

	r = 1;
	i = 0;
	m->print[3] = '0';
	if (!arg)
		m->buf = ft_strdup("(null)");
	else
	{
		m->print[3] = '1';
		m->w_str = ft_strnew(50);
		m->buf = wchar_conv(*arg, m, i++);
		while (*arg && *(++arg))
		{
			if (i == r * 50)
				realoc_wstr(m, ++r);
			tmp = ft_strdup(m->buf);
			ft_strdel(&m->buf);
			w_char = wchar_conv(*arg, m, i++);
			m->buf = ft_strjoin(tmp, w_char);
			ft_strdel(&w_char);
			ft_strdel(&tmp);
		}
	}
}
