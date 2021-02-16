#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int areDistinct(char str[], int i, int j)
{
  int visited[26] = {0};
  for(int k = i; k <= j; k++)
  {
      if (visited[str[k] - 'a'])
          return 0;
      visited[str[k] - 'a'] = 1;
  }
  return 1;
}

int lUS(char str[])
{
  int n = strlen(str);
  int res = 0;
  for(int i = 0; i < n; i++)
    for(int j = i; j < n; j++)
	if (areDistinct(str, i, j))
	  if (res < j - i + 1)
	    res = j - i + 1;
  return res;
}

int main()
{
  printf("%d\n", lUS("pwwkew"));
}
