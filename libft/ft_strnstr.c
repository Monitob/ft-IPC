/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 10:40:05 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/17 00:46:25 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1)
		return (NULL);
	if (*(s2) == '\0')
		return ((char *)s1);
	while ((*(s1 + i) != '\0') && (i < n))
	{
		j = 0;
		while ((*(s1 + i + j) == s2[j]) && ((i + j) < n) && (s2[j] != '\0'))
		{
			j++;
		}
		if (*(s2 + j) == '\0')
		{
			return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
