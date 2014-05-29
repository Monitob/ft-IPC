/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 20:44:27 by jbernabe          #+#    #+#             */
/*   Updated: 2014/02/07 21:15:20 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del_tab_int(int **tb)
{
	int	i;

	i = 0;
	if (tb != NULL)
	{
		while (tb[i] != NULL)
		{
			free(tb[i]);
			i++;
		}
		free(tb[i]);
		free(tb);
	}
}
