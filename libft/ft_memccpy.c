/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:38:16 by jbernabe          #+#    #+#             */
/*   Updated: 2013/12/01 19:01:52 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t		i;
	char		*ps1;
	const char	*ps2;

	ps1 = (char *)s1;
	ps2 = (const char *)s2;
	i = 0;
	while (i < n)
	{
		ps1[i] = ps2[i];
		if (*(ps2 + i) == (unsigned char)c)
		{
			return ((char *)(ps1 + i + 1));
		}
		i++;
	}
	return (NULL);
}
