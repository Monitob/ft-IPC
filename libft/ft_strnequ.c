/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:06:57 by jbernabe          #+#    #+#             */
/*   Updated: 2013/12/03 10:54:15 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*pr1;
	char	*pr2;
	size_t	i;

	pr1 = (char *)s1;
	pr2 = (char *)s2;
	i = 0;
	while (((pr1[i] != '\0') && (i < n)) || (pr2[i] != '\0'))
	{
		if (pr1[i] != pr2[i])
			return (0);
		++i;
	}
	if (i == n)
		return (1);
	return (1);
}
