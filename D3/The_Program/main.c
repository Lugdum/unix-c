#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *worker_arg[] = {argv[1], NULL};

  //creation des pipes
  int fd1[2];
  int fd2[2];
  pipe(fd1);
  pipe(fd2);
  if (pipe(fd1))
    err(1, "could not create a pipe1");
  if (pipe(fd2))
    err(1, "could not create a pipe2");

  //creation fork
  int child_pid = fork();
 
  if (child_pid == -1)
        err(2, "could not fork");
  else if (child_pid) //enfant
    {
      //redirection
      dup2(fd1[0] , STDIN_FILENO);
      dup2(fd2[1] , STDOUT_FILENO);

      //execution
      execvp(argv[1], worker_arg);
    }
  else //parent
    {
      FILE fd = fopen(argv[2], "r");
      int *line[];
      int len = 0;

      while(int r = getLine(&line, &len, fd) != -1)
{
 write(fd1[1],strcat(line, "\0\0"), len);
}
      close(fd);
    }
}
