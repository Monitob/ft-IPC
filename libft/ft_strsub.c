/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 21:05:22 by jbernabe          #+#    #+#             */
/*   Updated: 2013/12/05 20:54:58 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int star, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)ft_memalloc((len + 1) * (sizeof(char)));
	if (!ptr)
		return (NULL);
	while ((s[i] != '\0') && (i < len))
	{
		ptr[i] = s[i + star];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
