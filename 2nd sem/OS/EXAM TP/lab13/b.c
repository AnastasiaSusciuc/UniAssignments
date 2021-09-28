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
	int handler = semget(our_key, 0, 0);
	if (handler < 0){
		exit(1);
	} 
	int f;
	f = open("abc.txt",0);
	
	int i, r, r2;
	for (i = 0; i < 100; i++){
		sem_wait((sem_t *)&handler);
		read(f,&r, sizeof(int));
		read(f,&r2,sizeof(int));	
		sem_post((sem_t *)&handler);
		printf("%d\n",r+r2);
	}
	sem_destroy((sem_t *)&handler);
	close(f);
	return 0;
}
