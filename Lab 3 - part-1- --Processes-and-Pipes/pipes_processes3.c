#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
  int pipefd[2], pipe2[2];
  int pid, pid_2;

  char *cat_args[] = {"cat", "scores", NULL};
  char *grep_args[] = {"grep", argv[1], NULL};
  char *sort_args[] = {"sort", NULL};
  
  pipe(pipefd);
  pipe(pipe2);

  pid = fork();
  // Child
  if (pid == 0) 
    {
      pid_2 = fork();
      if (pid_2 == 0) {
        // reads from pipe 2
        dup2(pipe2[0], 0); 
        close(pipe2[1]);
        close(pipefd[1]);
        close(pipefd[0]);
        
        execvp("sort", sort_args);
      }
      else {
      // writes to pipe 2
      dup2(pipe2[1], 1); 
      dup2(pipefd[0], 0); // read
      close(pipefd[1]);
      close(pipe2[0]);
      
      execvp("grep", grep_args);
      }
    }
  else {
      dup2(pipefd[1], 1); // write 
      close(pipefd[0]);
      
      execvp("cat", cat_args);
    }
}