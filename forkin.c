#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	printf("Hello There\n");
	pid_t child1, child2;
	child1 = fork();
	int status;
	child1 = wait(&status);
	if(child1 != getpid()){
		child2 = fork();
	}else{
		printf("parent pid : %i\n",getppid());
		printf("pid : %i\n",getpid());
	}
	//printf("%d\n",status);
	printf("done\n");
	return 0;
}
