//print the sign of a number
//Zotova A.
#include <stdio.h>

int main (void)
{
  int n;
  int m;
  printf("Input n:");
  scanf("%i", &n);
  printf("%i", (n>>31)+!(n>>31)-!n );
  return (0);
}
