/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 19:12:01 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/17 00:43:07 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = 0;
	i = 0;
	ptr = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	else
	{
		while (i < size + 1)
		{
			ptr[i] = '\0';
			i++;
		}
		return (ptr);
	}
}
