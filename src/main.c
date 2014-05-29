/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 20:38:57 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/29 05:52:14 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "lem_ipc.h"

int				**ft_init_matrix(int len_matrix)
{
	int 	**matrix;
	int		i;
	int		j;

	i = 0;
	if (!(matrix = (int **)malloc(sizeof(int *) * len_matrix + 2)))
		return (0);
	while (i < len_matrix + 1)
	{
		if (!(matrix[i] = (int *)malloc(sizeof(int) * len_matrix + 2)))
			return (0);
		j = 0;
		while (j < len_matrix)
		{
			matrix[i][j] = 0;
			j++;
		}
		matrix[i][j] = -1;
		i++;
	}	
	matrix[len_matrix] = NULL;
	return (matrix);
}

void				init_share_memory(t_ipc *game)
{
	char			*share_memory;
	struct shmid_ds	shmbuffer;
	const int 		size_memo_share = sizeof(game);
/*allocate a shared memory segment */
	if ((game->segment_id = shmget(IPC_PRIVATE, size_memo_share,
						IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR)) < 0)
	{
		printf("segment id fail\n");
		exit(-1);
	}
	printf("%d **** this is segment_id\n", game->segment_id);
	if ((share_memory = (char *)shmat(game->segment_id, 0, 0)) == (char *)-1)
	{
		printf("shmat() fail\n");
		exit(-2);
	}
	printf("share memory %d\n",share_memory[0]++);
}

t_ipc			*init_map(t_ipc *game)
{
	if (!(game = (t_ipc *)malloc(sizeof(t_ipc))))
		return (NULL);
	game->table = ft_init_matrix(100);
	return (game);
}

int				main(void)
{
	t_ipc		*court;

	court = init_map(court);
	init_share_memory(court);
	return (0);
}