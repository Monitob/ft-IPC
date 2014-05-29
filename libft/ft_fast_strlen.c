/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 01:09:07 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/02 19:55:35 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

size_t					ft_fast_strlen(const char	*text)
{
	const char			*s;
	const uint32_t		*pdw_text;
	register uint32_t	dw_text;

	pdw_text = (uint32_t *)text;
	while (1)
	{
		dw_text = *pdw_text;
		if ((dw_text - 0x01010101UL) & ~dw_text & 0x80808080UL)
		{
			s = (const char *)pdw_text;
			while (*s)
				s++;
			return (s - text);
		}
		pdw_text++;
	}
}
