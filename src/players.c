/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 16:31:03 by jbernabe          #+#    #+#             */
/*   Updated: 2014/06/01 21:33:13 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

int				ft_close_sem(int id)
{
	struct sembuf ope[2];

	ope[0].sem_num = 0;
	ope[0].sem_op = -1;
	ope[0].sem_flg = SEM_UNDO;
	return (semop(id, ope, 1));
}

int				ft_open_sem(int id)
{
	struct sembuf ope[2];

	ope[0].sem_num = 0;
	ope[0].sem_op = -1;
	ope[0].sem_flg = SEM_UNDO;
	return (semop(id, ope, 1));
}

void			ft_move_player(t_player **p, t_env **e)
{
	int			i;
	int			j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if ((*e)->map[i][j] != 0 && (*e)->map[i][j] != (*p)->current_play)
			{
				(*p)->pos.y = i;
				(*p)->pos.x = j;
				fct_go_to(p, e);
				ft_putstr("\033[2J\033[1;1H");
				ft_print(*e);
				ft_putchar('\n');
				sleep(1);
				return ;
			}
			j++;
		}
		i++;
	}
}
