/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_ipc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 02:49:48 by jbernabe          #+#    #+#             */
/*   Updated: 2014/05/29 05:52:48 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IPC_H
# define LEM_IPC_H

typedef struct	s_ipc
{
	int			segment_id; /*id for the attached segmend*/
	char		*share_addr; /*attached point*/
	int 		is_attached; /*flags used on attach */
	int			**table;
}				t_ipc;

int				**ft_init_matrix(int len_matrix);
#endif
