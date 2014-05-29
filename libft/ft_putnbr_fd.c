/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 01:42:44 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/16 23:33:06 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	char	ctr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if ((n / 10) == 0)
	{
		ctr = n % 10 + '0';
		ft_putchar_fd(ctr, fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ctr = n % 10 + '0';
	ft_putchar_fd(ctr, fd);
}
