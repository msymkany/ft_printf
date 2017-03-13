/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:55:50 by msymkany          #+#    #+#             */
/*   Updated: 2016/11/30 20:02:12 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == '\0' && s2 == '\0')
		return (0);
	if (s1 && s2 && (ft_strncmp(s1, s2, n) == 0))
		return (1);
	return (0);
}
