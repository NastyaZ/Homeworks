//return 1, if number can fit into n bit and 0 otherwise
//Zotova A.
#include <stdio.h>

 int main (void)
{
   int x, n, a, b;
   printf("Input x, n:\n");
   scanf("%i %i", &x, &n);
   a=(1<<(n-1))-1;
   b=((!(~a&x)) | (!((x&~a)^~a)));
   printf("%i", b);
   return (0);
}
