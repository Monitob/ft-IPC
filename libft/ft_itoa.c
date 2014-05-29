/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 11:25:33 by jbernabe          #+#    #+#             */
/*   Updated: 2014/01/12 20:53:15 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	find_digits_nbr(int nbr)
{
	int		i;

	i = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr > 10)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

static void	fill_digits(char *result, long nbr)
{
	char	buf[2];

	if (nbr < 0)
	{
		nbr = -nbr;
		result = ft_strcat(result, "-");
	}
	if (nbr < 10)
	{
		buf[0] = (char)nbr + 48;
		buf[1] = '\0';
		result = ft_strcat(result, buf);
	}
	else
	{
		fill_digits(result, nbr / 10);
		fill_digits(result, nbr % 10);
	}
}

char		*ft_itoa(int n)
{
	int		digits;
	char	*result;

	digits = find_digits_nbr(n);
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (result)
	{
		ft_bzero(result, sizeof(char) * (digits + 1));
		fill_digits(result, (long)n);
	}
	return (result);
}
