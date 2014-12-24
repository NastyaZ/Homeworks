//expansion of the number, third method
//Zotova A.
#include <stdio.h>
int main (void)
{
   union
  {
    float fval;
    struct
    {
       unsigned int m1:23;
       unsigned int e1:8;
       unsigned int s1:1;
    }fvalue;
  }one;
   int e,m,s;
   printf("Input value:");
   scanf("%f", &one.fval);
   s=one.fvalue.s1;
   e=one.fvalue.e1;
   m=one.fvalue.m1;
   if (s)
      s=-1;
   else
      s=1;
   if ((e==0) && (m==0))
   {
      printf("0");
   }
   else if ((e==255) && (m==0) && (s==1))
   {
      printf("+Infinity");
   }
   else if ((e==255) && (m==0) && (s==-1))
   {
      printf("-Infinity");
   }
   else if ((e==255) && (m==0))
   {
      printf("NaN");
   }
   else
      printf("%d * 2 ^ %d * %f\n", s, e-127, 1+((float)m/(1<<23)));
   return 0;
}

