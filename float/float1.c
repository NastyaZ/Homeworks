//expansion of the number, first method
//Zotova A.
#include <stdio.h>
int main (void)
{
   float val; 
   int eval,e,m,s;
   printf("Input value:");
   scanf("%f", &val);
   eval=*((int*)((void*)&val));
   s=(eval>>31)&1;
   e=(eval>>23)&((1<<8)-1);
   m=eval&((1<<23)-1);
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

