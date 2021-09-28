#include <stdio.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
pthread_rwlock_t rw;


void* f(){
	printf("2 in thread before read lock\n");
	pthread_rwlock_rdlock(&rw);
	printf("2 in thread after read lock\n");

	
	printf("Hello\n");

	pthread_rwlock_unlock(&rw);
	
	printf("4 before wr lock\n");
	pthread_rwlock_wrlock(&rw);
	printf("4 after wr lock\n");
	
	sleep(2);
	printf("5 before wr unlock\n");
	pthread_rwlock_unlock(&rw);
	printf("5 after wr unlock\n");
	return NULL;
}



int main(int argc, char** argv){
	pthread_rwlock_init(&rw,NULL);
	printf("1 before read lock\n");
	pthread_rwlock_rdlock(&rw);	
	printf("1 after rd lock\n");

	pthread_t tr;
	pthread_create(&tr,NULL,f, NULL);	

	sleep(1);	
	printf("3 before rd unlock\n");
	pthread_rwlock_unlock(&rw);
	printf("3 after rd unlock\n");

	
	printf("6 before rd lock\n");
	pthread_rwlock_rdlock(&rw);
	printf("6 affter rd lock\n");

	printf("7 before rd unlock\n");
	pthread_rwlock_unlock(&rw);
	printf("7 after rd unlock\n");
	
	pthread_join(tr,NULL);	
	return 0;
}
