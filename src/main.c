/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 20:38:57 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/31 03:40:29 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lem_ipc.h"

int					init_share_memory(char *path, t_player **p, t_env **arena)
{
	int				seg_id;
	int				map_id;
	key_t			key;

	if ((key = ftok("./auteur", 'm')) == -1)
		return (-1);
	if ((seg_id = shmget(key, sizeof(t_env), SHM_R | SHM_W)) < 0)
	{
		if ((seg_id = shmget(key, sizeof(t_env), IPC_CREAT | SHM_R | SHM_W)) < 0)
		{
			ft_putstr_fd("shmeget() map fail\n", 2);
			exit (-1);
		}
	}
	if (!(*arena = (t_env *)shmat(seg_id, NULL, SHM_R | SHM_W)))
	{
		printf("shmat() attachement map fail\n");
		exit(-1);
	}
	if (!(*p = (t_player *)malloc(sizeof(t_player))))
		return (-1);
	(*p)->key_seg = key;
	return (seg_id);
}

void			creat_sb_write(t_player **player, t_env **arena)
{
	int		sb_id;

	if ((sb_id = semget((*player)->key_seg, 0, SETVAL)) < 0)
	{
		sb_id = semget((*player)->key_seg, 1, IPC_CREAT | IPC_EXCL | 0666);
		if (sb_id < 0)
		{
			ft_putstr_fd("error creat sb_id", 2);
			exit(-1);
		}
		if (semctl(sb_id, 0, SETVAL, 1) < 0 )
		{
			ft_putstr_fd("error init sb", 2);
			exit (-2);
		}
	}
}

void			creat_sb_read(t_player **player, t_env **arena)
{
	int		sb_id;

	if ((sb_id = semget((*player)->key_seg, 1, GETVAL)) < 0)
	{
		sb_id = semget((*player)->key_seg, 1, IPC_CREAT | IPC_EXCL | 0666);
		if (sb_id < 0)
		{
			ft_putstr_fd("error creat sb_id", 2);
			exit(-1);
		}
		if (semctl(sb_id, 0, SETVAL, 1) < 0 )
		{
			ft_putstr_fd("error init sb", 2);
			exit (-2);
		}
	}
}

int				main(int ac, char **av)
{
	t_player		*player;
	t_env			*arena;

	if (ac != 2)
		return (-1);
	player->seg_id = init_share_memory(av[0], &player, &arena);
	creat_sb_read(&player, &arena);
	creat_sb_write(&player, &arena);
	

	return (0);
}
