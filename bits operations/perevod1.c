//return binary representation of the number
//Zotova A.
#include <stdio.h>

int main (void)
{
   int a, n=sizeof(int)*8-1;
   printf("Input a:\n");
   scanf ("%i", &a);
   while(!(a&(1<<n)) && (n))
      n--;
   while (n+1)
   { 
      printf("%i", !!(a&(1<<n)));
      n--;
   }

    return (0);
}
