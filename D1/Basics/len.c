#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int len(char *path)
{
  struct stat st;
  stat(path, &st);
  size_t size = st.st_size;
  printf("%zu\n", size);
  
  return 0;
}

int main(int argc, char *argv[])
{
  return len(argv[1]);
}


