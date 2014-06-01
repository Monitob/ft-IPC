/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/01 17:56:43 by jbernabe          #+#    #+#             */
/*   Updated: 2014/06/01 21:26:18 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_ipc.h"

static void		ft_go_to_y(t_player **p, t_env **e, int *change_plan)
{
	if ((*p)->base_pos.y > (*p)->pos.y && (*p)->base_pos.y > 0)
	{
		(*e)->map[(*p)->base_pos.x][(*p)->base_pos.y] = 0;
		(*p)->base_pos.y -= 1;
		(*e)->map[(*p)->base_pos.x][(*p)->base_pos.y] = (*p)->current_play;
	}
	else
	{
		if ((*p)->base_pos.y > (*p)->pos.y && (*p)->base_pos.y < 100)
		{
			(*e)->map[(*p)->base_pos.x][(*p)->base_pos.y] = 0;
			(*p)->base_pos.y += 1;
			(*e)->map[(*p)->base_pos.x][(*p)->base_pos.y] = (*p)->current_play;
		}
	}
	*change_plan = 0;
}

static void		ft_go_increment_x(t_player **p, t_env **e)
{
	if ((*p)->base_pos.x < 100)
	{
		test_position((*p)->base_pos.x, (*p)->base_pos.y);
		(*e)->map[(*p)->base_pos.x][(*p)->base_pos.y] = 0;
		(*p)->base_pos.x += 1;
		(*e)->map[(*p)->base_pos.x][(*p)->base_pos.y] = (*p)->current_play;
		test_position((*p)->base_pos.x, (*p)->base_pos.y);
	}
}

void			fct_go_to(t_player **p, t_env **e)
{
	static	int change_plan = 0;

	if (change_plan == 0)
	{
		change_plan = 1;
		if (((*p)->base_pos.x > (*p)->pos.x && (*p)->base_pos.x > 0))
		{
			test_position((*p)->base_pos.x, (*p)->base_pos.y);
			(*e)->map[(*p)->base_pos.x][(*p)->base_pos.y] = 0;
			(*p)->base_pos.x -= 1;
			(*e)->map[(*p)->base_pos.x][(*p)->base_pos.y] = (*p)->current_play;
			test_position((*p)->base_pos.x, (*p)->base_pos.y);
		}
		else
			ft_go_increment_x(p, e);
	}
	else if (change_plan == 1)
	{
		ft_go_to_y(p, e, &change_plan);
		change_plan = 0;
	}
	return ;
}
