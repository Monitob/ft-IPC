/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 16:31:03 by jbernabe          #+#    #+#             */
/*   Updated: 2014/06/01 22:37:06 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

int				ft_close_sem(t_player *p)
{
	p->sb[1].sem_num = 1;
	p->sb[1].sem_op = -1;
	p->sb[1].sem_flg = 0;
	return (semop(1, p->sb, 1));
}

int				ft_open_sem(t_player *p)
{
	p->sb[0].sem_num = 1;
	p->sb[0].sem_op = 1;
	p->sb[0].sem_flg = 0;
	return (semop(1, p->sb, 1));
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
	if ((*e)->nb < 3)
		clean_semf(*p, 1);
}
