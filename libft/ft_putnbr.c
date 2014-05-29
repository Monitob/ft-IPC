/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:47:09 by jbernabe          #+#    #+#             */
/*   Updated: 2013/12/01 19:08:34 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	ctr;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if ((n / 10) == 0)
	{
		ctr = n % 10 + '0';
		ft_putchar(ctr);
		return ;
	}
	ft_putnbr(n / 10);
	ctr = n % 10 + '0';
	ft_putchar(ctr);
}
