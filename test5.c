#include "lemipc.h"

int main(int argc, char **argv)
{
	t_map		*map;
	int			mem_id;
	key_t		key;
	t_player	player;
	int			sem_id;
	struct sembuf sb[1];
	argc += 0;

	/* synopsis final :
						allocation de l'ipc;
						test de la zone memoire, si elle n'existe pas  creation avec ipc_creat;
						nb++ pour savoir le nombre de joueur
						test et init des semaphore a faire
	*/
	player.team_nb = atoi(argv[1]);
	if ((key = ftok(argv[0], 0)) == -1)
	{
		printf("Non\n");
		return (-1);
	}
	printf("cle = %d\n", (int)key);
	//alloc segment memoire , d'abord test s'il exist, si non je le cree avec le flag ipc_creat

	if ((mem_id = shmget(key, sizeof(t_map), SHM_W  | SHM_R)) <= 0)
	{
		printf("create memory \n");
		if ((mem_id = shmget(key, sizeof(t_map), IPC_CREAT | SHM_W  | SHM_R)) == -1)
		{
			printf("error %d\n", mem_id);
			return (-1);
		};
	}
	
	printf("memid = %d", mem_id);
	
	//attach
	map = (t_map*)shmat(mem_id, NULL, SHM_W  | SHM_R) ;
	printf(" - %p\n", map);
	// creation semaphore d abord en read write et sinon en creee un 
	if ((sem_id = semget(key, 1, 0)) < 0)
	{
		printf("creation d un semaphore\n");
		sem_id = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);
		printf("sem id = %d\n", sem_id);
		if ((semctl (sem_id, 0, SETVAL, 1)) < 0)
			printf("sem init fail\n");
	}
	
	//test remplissage /lect/ecriture
	if (atoi(argv[1]) == 1)
	{
		sb[0].sem_num = 0;
		sb[0].sem_op = -1;
		sb[0].sem_flg = 0;
		if (semop(sem_id, sb, 1) != 0)
			printf("sema fail\n");
		printf("wait\n");
		sleep(10);
		printf("remplissage  de l'equipe%d\n", player.team_nb);
		map->nb = 9;
		printf("OK 'equipe1\n");
		sb[0].sem_num = 0;
		sb[0].sem_op = 1;
		sb[0].sem_flg = 0;
		if (semop(sem_id, sb, 1) != 0)
			printf("sem fail encore\n");
	}
	else  if (atoi(argv[1]) == 2)
	{
		printf("acces 1\n");
		sb[0].sem_num = 0;
		sb[0].sem_op = -1;
		sb[0].sem_flg = 0;
		if (semop(sem_id, sb, 1) != 0)
			printf("sema fail\n");
		printf("nb de l'equipe %d %d",player.team_nb,  map->nb);
		printf("OK 'equipe2\n");
		sb[0].sem_num = 0;
		sb[0].sem_op = 1;
		sb[0].sem_flg = 0;
		if (semop(sem_id, sb, 1) != 0)
			printf("sem fail encore\n");
	}
	else if (atoi(argv[1]) == 3)
	{
		printf("nb de l'equipe %d %d",player.team_nb,  map->nb);
		printf("ecrit de l'equipe 3 ");
		map->nb = 525;
	}
	// free semaphore
	if (semctl(sem_id, 0, IPC_RMID) != 0) 
	{
		//perror("detruire_sem");exit(EXIT_FAILURE);
	}
	// detach
	if (shmctl(mem_id, IPC_RMID, NULL) < 0)
		printf("detach fai\n");

	//while (1)
	//;
	return (0);
}
