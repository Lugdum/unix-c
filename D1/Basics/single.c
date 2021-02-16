//single comme moi mdr

#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int single(char *path, int super)
{
  int fd = open(path, O_RDONLY);
  lseek(fd, super, SEEK_SET);
  char buf;
  int r = read(fd, &buf, 1);
  if (r == -1)
    err(3, "ca lit pas bien bro\n");
  printf("%c\n", buf);
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
    err(3, "les arguments bro les arguments\n");
  return single(argv[1], atoi(argv[2]));
}
