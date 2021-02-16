#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int echo(char *path)
{
  int r;
  int fd = open(path, O_WRONLY);
  char buf[10];
  while ((r = read(0, buf, 10)) != 0)
    {
      if (r == -1)
	err(3, "ca lit pas bien bro\n");
      r = write(fd, buf, r);
      if (r == -1)
	err(3, "ca arrive pas a ecrire c'est la demer\n");
    }
  return 0;
}

int main(int argc, char *argv[])
{
  return echo(argv[1]);
}


