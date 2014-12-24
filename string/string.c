#include <stdio.h>
#include <string.h>
int main (void)
{
   char s1[100];
   char s2[100];
   int i,j, k=0;
   printf ("Input first string:\n");
   gets(s1);
   printf ("Input second string:\n");
   gets(s2);
   for (i=0; i<strlen(s1); i++)
   { 
      j=0;
      while ((j<strlen(s2)) && (s1[i+j]==s2[j]))
         j++;
      if (j==strlen(s2))
         k++;

   }
   printf("%i\n", k);
return 0;
}
