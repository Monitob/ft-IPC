/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_ipc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 02:49:48 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/31 22:25:11 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IPC_H
# define LEM_IPC_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <sys/stat.h>
# include <time.h>
# include "libft.h"

# define	READ 	1
# define	WRITE	2
# define	WIDTH	20
# define	HEIGHT	20

typedef struct	s_env
{
	int			map[HEIGHT][WIDTH];
}				t_env;

typedef struct	s_player
{
	int			x;
	int			y;
	int			seg_id;
	key_t		key_seg;
	int			team_nb;
	int			sb_id;
	struct sembuf sb[2];
}				t_player;

void			creat_sb(t_player **player, t_env **arena);
int				init_share_memory(char *path, t_player **p, t_env **arena);
#endif
