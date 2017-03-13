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

int 	size_wchar(wchar_t w)
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

char	*wchar_conv(wchar_t w)
{
	int			size;
	char			*buf;

	size = size_wchar(w);
	buf = ft_strnew(size);
	if (size == 1)
		buf[0] = w;
	else
		buf[0] = (w >> (6 * (size - 1))) | (240 << (4 - size));
	while (--size > 0)
	{
		buf[size] = (w & 63) | 128;
		w = w >> 6;
	}
	return (buf);
}

void	wstr_conv(wchar_t *arg, t_magic *m)
{
	if (!arg)
		m->buf = ft_strdup("(null)");
	else
	{
		m->buf = wchar_conv(*arg);
		while (*arg)
		{
			arg++;
			m->buf = ft_strjoin(m->buf, wchar_conv(*arg));
		}
	}
	m->print[3] = '1';
}
