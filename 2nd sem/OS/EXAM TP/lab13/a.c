#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char** argv){
	key_t our_key = 3029;
	int handler = semget(our_key, 1, IPC_CREAT | 0666); 
	if (handler < 0){
		exit(1);
	} 
	int f;
	f = open("abc.txt",1);
	
	int i, r, r2;
	for (i = 0; i < 100; i++){
		r = rand() % 100;
		r2 = rand() % 100;
		sem_wait((sem_t *)&handler); 
		write(f,&r, sizeof(int));
		write(f,&r2,sizeof(int));	
		sem_post((sem_t *)&handler);
	}
	
	sem_destroy((sem_t *)&handler);
	close(f);
	return 0;
}
