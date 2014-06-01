/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_ipc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 02:49:48 by jbernabe          #+#    #+#             */
/*   Updated: 2014/06/01 21:22:37 by jbernabe         ###   ########.fr       */
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
# define	FLAGS	SHM_R | SHM_W
# define	FLAGS2	IPC_CREAT | SHM_R | SHM_W

typedef struct		s_env
{
	int				nb;
	int				map[HEIGHT][WIDTH];
}					t_env;

typedef struct		s_pos
{
	int 			x;
	int 			y;
}					t_pos;

typedef struct		s_player
{
	int				x;
	int				y;
	t_pos			pos;
	t_pos			base_pos;
	int				current_play;
	int				seg_id;
	key_t			key_seg;
	int				sb_id;
	struct sembuf	sb[2];
}					t_player;

int				clean_semf(t_player *p,  int n);
void			test_position(int x, int y);
void			ft_game_position(t_player **p, t_env **e, char *id_player);
void			ft_move_player(t_player **p, t_env **e);
void			fct_go_to(t_player **p, t_env **e);
void			verify_players(int *all_players);
void			ft_play_game(t_player **p, t_env **e);
void			ft_print(t_env *arena);
int				ft_close_sem(int id);
int				ft_open_sem(int id);
void			creat_sb(t_player **player, t_env **arena);
int				init_share_memory(char *path, t_player **p, t_env **arena);

#endif
