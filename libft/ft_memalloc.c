/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:09:04 by jbernabe          #+#    #+#             */
/*   Updated: 2013/12/25 13:15:08 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = 0;
	if (size == 0)
		return (NULL);
	else
	{
		ptr = malloc(size);
		if (!ptr)
			return (NULL);
		else
		{
			ft_bzero(ptr, size);
			return (ptr);
		}
	}
}
