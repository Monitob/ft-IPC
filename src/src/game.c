/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 14:13:08 by jbernabe          #+#    #+#             */
/*   Updated: 2014/06/01 22:27:25 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

void		ft_print(t_env *arena)
{
	int		i;
	int		j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (arena->map[i][j] == 0)
				ft_putstr(". ");
			else
			{
				ft_putnbr(arena->map[i][j]);
				ft_putchar(' ');
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putstr("this is the end!!!!!\n");
}

void		ft_play_game(t_player **p, t_env **e)
{
	while (1)
	{
		ft_close_sem(*p);
		ft_move_player(p, e);
		ft_open_sem(*p);
	}
}
