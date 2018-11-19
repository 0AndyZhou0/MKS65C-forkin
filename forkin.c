#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int file = open("/dev/random", O_RDONLY);
  int *number = (int *)malloc(sizeof(int));
  printf("Hello There\n");
  pid_t child1, child2, pid;
  int status;
  child1 = fork();
  if(child1){
    child2 = fork();
    if(child2){

      //parent code
      
      printf("Waiting for children\n");
      //pid = waitpid(child1,&status,WUNTRACED);
      //printf("%i has completed\n",pid);

      
      pid = wait(&status);
      //printf("time : %d\n",status / 255);
      printf("%i was sleeping for %d seconds\n",pid, status/255);
      
      //printf("I'm the parent\n");
      //printf("parent pid : %i\n",getpid());
      //printf("child1 pid : %i\n",child1);
      //printf("child2 pid : %i\n",child2);
      printf("Parent is done\n");
    }else{
      
      //child2 code
      
      //printf("I'm child2\n");
      //printf("parent pid : %i\n",getppid());
      printf("child2 pid : %i\n",getpid());
      read(file,number,sizeof(int));
      if(*number < 0){
	*number *= -1;
      }
      int randnum = (*number % 15) + 5;
      printf("sleeping for %d seconds\n",randnum);
      sleep(randnum);
      printf("child2 is done\n");
      //return randnum;
      exit(randnum);
    }
  }else{
    
    //child1 code
    
    //printf("I'm child1\n");
    //printf("parent pid : %i\n",getppid());
    printf("child1 pid : %i\n",getpid());
    read(file,number,sizeof(int));
    if(*number < 0){
      *number *= -1;
    }
    int randnum = (*number % 15) + 5;
    printf("sleeping for %d seconds\n",randnum);
    sleep(randnum);
    printf("child1 is done\n");
    //return randnum;
    exit(randnum);
  }
  free(number);
  close(file);
  return 0;
}
