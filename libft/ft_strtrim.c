/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 11:43:09 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/17 00:53:26 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_white(char s)
{
	if (s == ' ' || s == '\n' || s == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	st_len;

	if (s)
	{
		while (*s && is_white(*s))
			s++;
		st_len = ft_strlen(s);
		while (st_len && is_white(s[st_len - 1]))
			st_len--;
		str = ft_strnew(st_len);
		if (str)
			ft_strncpy(str, s, st_len);
		return (str);
	}
	else
		return (NULL);
}
