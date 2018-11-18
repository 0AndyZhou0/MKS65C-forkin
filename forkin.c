#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int file = open("/dev/random", O_RDONLY);
  int *number = (int *)malloc(sizeof(int));
  printf("Hello There\n");
  pid_t child1, child2;
  child1 = fork();
  if(child1){
    child2 = fork();
    if(child2){

      //parent code
      
      printf("Waiting for child1\n\n");
      sleep(15);
      printf("I'm the parent\n");
      printf("parent pid : %i\n",getpid());
      printf("child1 pid : %i\n",child1);
      printf("child2 pid : %i\n",child2);
      printf("Parent is done\n");
    }else{
      
      //child2 code
      
      //printf("I'm child2\n");
      //printf("parent pid : %i\n",getppid());
      read(file,number,sizeof(int));
      printf("child2 pid : %i\n",getpid());
      sleep(*number % 15 + 5);
      printf("child2 is done\n\n");
    }
  }else{
    
    //child1 code
    
    //printf("I'm child1\n");
    //printf("parent pid : %i\n",getppid());
    printf("child1 pid : %i\n",getpid());
    sleep(*number % 16 + 5);
    printf("child1 is done\n\n");
  }
  return 0;
}
