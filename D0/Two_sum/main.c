#include <stdio.h>
#include <stdlib.h>


void Twosum(int nums[], int target) {
  for (int i = 0; i < (sizeof(nums)/sizeof(int)); i++)
    {
      for (int j = i + 1; j < (sizeof(nums)/sizeof(int)); j++)
        {
          if (nums[j] == target - nums[i])
	    {
	      printf("%d, %d\n", i, j);
	      return;
	    }
	}
    }
  printf("Y'a pas\n");
}

int main()
{
  int tab[4];
  tab[0] = 2;
  tab[1] = 7;
  tab[2] = 11;
  tab[3] = 15;
  Twosum(tab, 10);
}

