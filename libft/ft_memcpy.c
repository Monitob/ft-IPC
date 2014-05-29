/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:47:16 by jbernabe          #+#    #+#             */
/*   Updated: 2014/01/12 20:55:13 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*ps1;
	char const	*ps2;

	ps1 = (char *)s1;
	ps2 = (char const *)s2;
	while (n)
	{
		n--;
		*ps1++ = *ps2++;
	}
	return (s1);
}
