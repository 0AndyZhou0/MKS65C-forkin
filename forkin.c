#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  printf("Hello There\n");
  pid_t child1, child2;
  child1 = fork();
  if(child1){
    child2 = fork();
    if(child2){
      printf("I'm the parent\n");
      printf("parent pid : %i\n",getppid());
      printf("pid : %i\n",getpid());
    }else{
      printf("I'm child2\n");
      printf("parent pid : %i\n",getppid());
      printf("pid : %i\n",getpid());
    }
  }else{
    printf("I'm child1\n");
    printf("parent pid : %i\n",getppid());
    printf("pid : %i\n",getpid());
  }
  printf("done\n");
  return 0;
}
