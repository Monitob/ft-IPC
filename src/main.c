/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 20:38:57 by jbernabe          #+#    #+#             */
/*   Updated: 2014/06/01 21:33:32 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lem_ipc.h"

int					make_semf(key_t key, int n)
{
	union semun		arg;
	int				sb_id;
	int				i;

	if ((sb_id = semget(key, n, IPC_CREAT | IPC_EXCL | 0666)) < 0)
	{
		if ((sb_id = semget(key, n, IPC_CREAT | 0666)) != -1)
		{
			i = 0;
			while (i < n)
			{
				arg.val = i;
				semctl(sb_id, i, SETVAL, arg);
				i++;
			}
		}
	}
	return (sb_id);
}

void				ft_shm_zero(t_env **arena)
{
	int			i;
	int			j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < HEIGHT)
		{
			(*arena)->map[i][j] = 0;
			j++;
		}
		i++;
	}
}

int					init_share_memory(char *path, t_player **p, t_env **arena)
{
	if (((*p)->key_seg = ftok(path, 0)) == -1)
		return (-1);
	if (((*p)->seg_id = shmget((*p)->key_seg, sizeof(t_env), FLAGS)) <= 0)
	{
		if (((*p)->seg_id = shmget((*p)->key_seg, sizeof(t_env), FLAGS2)) == -1)
		{
			ft_putstr_fd("error init share memory()\n", 2);
			return (-1);
		}
		if (!(*arena = (t_env *)shmat((*p)->seg_id, (void *)0, SHM_R | SHM_W)))
		{
			ft_putstr("shmat() attachement map fail\n");
			return (-1);
		}
		ft_shm_zero(arena);
		return ((*p)->key_seg);
	}
	if (!(*arena = (t_env *)shmat((*p)->seg_id, (void *)0, SHM_R | SHM_W)))
	{
		ft_putstr("shmat() attachement map fail\n");
		return (-1);
	}
	return ((*p)->key_seg);
}

void				ft_game_position(t_player **p, t_env **e, char *id_player)
{
	srand(time(NULL));
	(*p)->current_play = ft_atoi(id_player);
	(*e)->nb += 1;
	while (1)
	{
		(*p)->x = rand() % WIDTH;
		(*p)->y = rand() % HEIGHT;
		if ((*e)->map[(*p)->y][(*p)->x] == 0)
			break ;
	}
	if ((*e)->map[(*p)->y][(*p)->x] == 0)
	{
		(*e)->map[(*p)->x][(*p)->y] = (*p)->current_play;
		(*p)->base_pos.x = (*p)->x;
		(*p)->base_pos.y = (*p)->y;
	}
}

int					main(int ac, char **av)
{
	t_player		*player;
	t_env			*arena;

	if (ac != 2)
		return (-1);
	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (-1);
	player->key_seg = init_share_memory(av[0], &player, &arena);
	player->sb_id = make_semf(player->key_seg, 2);
	if (player->sb_id < 0)
	{
		ft_putstr_fd("semget() fail\n", 2);
		exit (-1);
	}
	ft_game_position(&player, &arena, av[1]);
	while (arena->nb < 3)
		;
	ft_play_game(&player, &arena);
	clean_semf(player, 2);
	return (0);
}
