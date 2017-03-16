/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:28:57 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/13 16:29:12 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_magic		*init_struct(void)
{
	t_magic		*m;

	m = (t_magic *)malloc(sizeof(t_magic));
	m->buf = NULL;
	m->w_str = NULL;
	return (m);
}

void		clear_struct(t_magic *m, char fl)
{
	ft_bzero(m->print, PRINT);
	m->w = -1;
	m->p = -1;
	m->r = 0;
	m->len = 1;
	m->c = 0;
	m->mod = fl;
	if (m->buf)
	{
		free(m->buf);
		m->buf = NULL;
	}
	if (m->w_str)
	{
		free(m->w_str);
		m->w_str = NULL;
	}
}

void		del_struct(t_magic **m)
{
	if ((*m)->buf)
	{
		free((*m)->buf);
		(*m)->buf = NULL;
	}
	if ((*m)->w_str)
	{
		free((*m)->w_str);
		(*m)->w_str = NULL;
	}
	free(*m);
	*m = NULL;
}
