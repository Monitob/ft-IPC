/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:35:38 by jbernabe          #+#    #+#             */
/*   Updated: 2013/12/30 17:07:28 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p_char;

	p_char = b;
	while (len > 0)
	{
		*p_char = c;
		p_char++;
		len--;
	}
	return (b);
}
