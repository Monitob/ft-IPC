/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 11:57:25 by vjarysta          #+#    #+#             */
/*   Updated: 2014/04/17 00:24:59 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	char	*tmp;
	size_t	n;

	tmp = NULL;
	if (ptr != NULL)
	{
		n = ft_strlen((char *)ptr);
		if ((tmp = ft_memalloc(n + size + 1)) == NULL)
			return (NULL);
		ft_memcpy(tmp, ptr, n);
		ft_memdel(&ptr);
	}
	return (tmp);
}
