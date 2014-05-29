/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 16:14:06 by jbernabe          #+#    #+#             */
/*   Updated: 2013/12/01 19:27:14 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*f_c;
	const char	*p;

	if (c == '\0')
		return (ft_strchr(s, '\0'));
	f_c = NULL;
	while ((p = ft_strchr (s, c)) != NULL)
	{
		f_c = p;
		s = p + 1;
	}
	return ((char *)f_c);
}
