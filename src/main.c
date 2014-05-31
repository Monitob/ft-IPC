/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 20:38:57 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/31 22:44:34 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lem_ipc.h"

int 				make_semf(key_t key, int n)
{
	union semun		arg;
	int 			sb_id;
	int 			i;

	if ((sb_id = semget(key, n, IPC_CREAT | IPC_EXCL | 0666)) < 0)
	{
		semctl(sb_id, 0, IPC_RMID);
		if ((sb_id = semget(key, n, IPC_CREAT | 0666)) != -1)
		{
			arg.val = 1;
			i = 0;
			while (i < n)
			{
				semctl(sb_id, 0, SETVAL, arg);
				i++;
			}
		}
	}
	printf("sb_id %d\n", sb_id);
	return (sb_id);
}
		
void				ft_shm_zero(t_env **arena)
{
	int 		i;
	int 		j;

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
	int	flags;
	int flags2;

	flags = SHM_R | SHM_W;
	flags2 = IPC_CREAT | SHM_R | SHM_W;
	if (((*p)->key_seg = ftok(path	, 0)) == -1)
		return (-1);
	ft_putstr("ftok -> ");
	ft_putnbr((*p)->key_seg);
	ft_putchar('\n');
	if (((*p)->seg_id = shmget((*p)->key_seg, sizeof(t_env), flags)) <= 0)
	{
		if (((*p)->seg_id = shmget((*p)->key_seg, sizeof(t_env), flags2)) == -1)
		{
			ft_putstr_fd("error init share memory()\n", 2);
			return (-1);
		}
		if (!(*arena = (t_env *)shmat((*p)->seg_id, (void *)0, SHM_R | SHM_W)))
		{
			printf("shmat() attachement map fail\n");
			return (-1);
		}
		ft_shm_zero(arena);
		return ((*p)->key_seg);
	}
	if (!(*arena = (t_env *)shmat((*p)->seg_id, (void *)0, SHM_R | SHM_W)))
	{
		printf("shmat() attachement map fail\n");
		return (-1);
	}
	return ((*p)->key_seg);
}

void			ft_close_sem(t_player *p, int id)
{
	p->sb[0].sem_num = id;
	p->sb[0].sem_op = -1;
	p->sb[0].sem_flg = SEM_UNDO;
	if ((semop(p->sb_id, p->sb, 2)) == -1)
		ft_putstr_fd("close sem () fail\n", 2);
}

void			ft_open_sem(t_player *p, int id)
{
	p->sb[0].sem_num = id;
	p->sb[0].sem_op = 1;
	p->sb[0].sem_flg = SEM_UNDO;
	if ((semop(p->sb_id, p->sb, 2)) == -1)
		ft_putstr_fd("close sem () fail\n", 2);
}	

void			ft_print(t_env *arena)
{
	int			i;
	int			j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			printf(" %d", arena->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void 			ft_game(t_player *p, t_env *e, char *id_player)
{
	srand(time(NULL));
	printf("%s\n", id_player);

	while (1)
	{
		p->x = rand() % WIDTH;
		p->y = rand() % HEIGHT;
		printf("case test -%c- de coord %d %d\n", e->map[p->y][p->x], p->y, p->x);
		if (e->map[p->y][p->x] != ft_atoi(id_player))
		 	break;
	}
	
	if (e->map[p->y][p->x] == 0 && e->map[p->y + 1][p->x + 1] == 0 && 
		e->map[p->y + 2][p->x + 2] == 0)
	{
		e->map[p->y][p->x] = p->team_nb;
		e->map[p->y + 1][p->x + 1] = p->team_nb;
		e->map[p->y + 2][p->x + 2] = p->team_nb;
	}
}

void			ft_move_player(t_player *p, t_env *e)
{
	int			i;
	int			j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (e->map[i][j] == p->team_nb)
			{
				e->map[p->y + 1][p->x + 1] = 0;
				e->map[p->y + 2][p->x + 2] = 0;
				e->map[p->y][p->x] = 0;
				e->map[p->y + 2][p->x + 2] = p->team_nb;
				e->map[p->y + 3][p->x + 3] = p->team_nb;
				break ;
			}
			j++;
		}
		printf("\n");
		i++;
	}
}

void			ft_play_game(t_player *p, t_env *e)
{
	while (1)
	{
		ft_close_sem(p, READ);
		ft_close_sem(p, WRITE);
		ft_move_player(p, e);
		ft_open_sem(p, WRITE);
		ft_open_sem(p, READ);
	}
}

int				main(int ac, char **av)
{
	t_player		*player;
	t_env			*arena;

	if (ac != 2)
		return (-1);
	if (!(player = (t_player *)malloc(sizeof(t_player))))
		return (-1);
	player->key_seg = init_share_memory(av[0], &player, &arena);
	printf("playe key %d\n", player->key_seg);
	player->sb_id = make_semf(player->key_seg, 2);
	printf("semafore id %d\n", player->sb_id);
	if (player->sb_id < 0)
	{
		ft_putstr_fd("semget() fail\n", 2);
		exit (-1);
	}
	player->team_nb = ft_atoi(av[1]);
	ft_game(player, arena, av[1]);
		ft_play_game(player, arena);
	ft_print(arena);
	
	return (0);
}
