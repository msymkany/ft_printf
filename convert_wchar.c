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

int				size_wchar(wchar_t w)
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

char			*wchar_conv(wchar_t w)
{
	int		size;
	char	*buf;

	size = size_wchar(w);
	buf = ft_strnew(size);
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

static size_t	arg_len(wchar_t *arg)
{
	size_t	i;

	i = 0;
	while (arg[i++])
		;
	return (i);
}

void			wstr_conv(wchar_t *arg, t_magic *m)
{
	char	*tmp;
	size_t	i;
	size_t	r;

	r = 0;
	i = 0;
	m->print[3] = (!arg) ? '0' : '1';
	if (!arg)
		m->buf = ft_strdup("(null)");
	else
	{
		m->w_str = ft_strnew(arg_len(arg));
		while (arg[i])
		{
			m->w_str[i] = (char)size_wchar(arg[i]);
			r += (size_t)m->w_str[i++];
		}
		m->buf = ft_strnew(r);
		while (i--)
		{
			tmp = wchar_conv(*(arg++));
			m->buf = ft_strcat(m->buf, tmp);
			ft_strdel(&tmp);
		}
	}
}
