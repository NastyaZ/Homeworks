//raises a number to power
//Zotova A.
#include <stdio.h>

float func (float a, int n)
{
   float k;
   int m=n;
   if (!((n>>31)+1))
      n=~n+1;
   if (!(n))
      return 1; 
   k=func(a, n>>1);
   k=k*k;
   if (n&1)
      k=k*a;
   if ((m>>31)+1)
       return k; 
   else
       return 1/k;
}

int main (void)
{
   float a;
   int n;
   printf("Input a, n:\n");
   scanf ("%f %i", &a, &n);
   printf("%f", func(a,n));
   return (0);
    scanf ("%f %i", &a, &n);
}
