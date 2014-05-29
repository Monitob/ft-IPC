/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:10:26 by jbernabe          #+#    #+#             */
/*   Updated: 2013/12/01 20:39:57 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	ps1[n];

	if (s1 == s2)
		return (s1);
	else
	{
		ft_memcpy(ps1, s2, n);
		ft_memcpy(s1, ps1, n);
	}
	return (s1);
}
