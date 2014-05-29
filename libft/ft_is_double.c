/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/02 13:25:00 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/02 13:30:33 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_double(char *str, int i, int car)
{
	int		j;

	j = 0;
	while (j < i)
	{
		if (str[j] == car)
			return (1);
		j++;
	}
	return (0);
}
