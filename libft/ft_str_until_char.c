/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_until_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 15:25:30 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/02 15:27:56 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_search_position(char *str, int c)
{
	int		i;

	i = 0;
	if (!str || !c)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] && str[i + 1] != c
			&& str[i - 1] != c && str[i - 1] >= 0 && str[i - 1])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char		*ft_str_until_char(char *str, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !c)
		return (NULL);
	while (str[i] != '\0')
	{
		if ((j = ft_search_position(str, c)) != -1)
		{
			return ((char *)str + j);
		}
		i++;
	}
	return (NULL);
}
