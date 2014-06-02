/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 16:33:20 by jbernabe          #+#    #+#             */
/*   Updated: 2014/06/01 22:18:18 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

void		test_position(int x, int y)
{
	ft_putstr("base pos old x ");
	ft_putnbr(x);
	ft_putchar('\n');
	ft_putstr("base old y");
	ft_putnbr(y);
	ft_putchar('\n');
}

int			clean_semf(t_player *p, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		semctl(p->sb_id, i, IPC_RMID, i);
		i++;
	}
	exit (-1);
}

void		verify_players(int *all_players)
{
	int		i;

	i = 0;
	while (i < 150)
	{
		ft_putnbr(all_players[i]);
		i++;
	}
	ft_putchar('n');
}
