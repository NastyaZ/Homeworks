#include<stdio.h>
#include<stdlib.h> 
typedef struct LIST
{
   int DATA;
   struct LIST *next;
}LIST;
 LIST *L=NULL;

void DisplayList()
{
   LIST *Copy=L;
   if (Copy==NULL)
      printf("List is empty\n");
   while(Copy!=NULL)
   {
     printf("%i", Copy->DATA);
     Copy=Copy->next;
     printf(Copy==NULL ? "\n" : ",");
   }
}
void AddToBegin(int value)
{
   LIST *New;
   New=malloc(sizeof (LIST *));
   New->DATA = value;
   New->next = L;
   L=New;
}
void Delete(int k)
{
  struct LIST *Old=L->next, *New=L;
  if (L==NULL)
  {
    printf("List is empty");
    return;
  }
  if ((L->DATA == k) && (L->next==NULL))
  {
    free(L);
    L=NULL;
    return;
  }
  while(Old!=NULL)
  {
      if (L->DATA==k)
      {
         L=L->next;
         free (New);
      }
      while(Old->DATA != k)
     {
       New=New->next;
       if(Old->next !=NULL)
         Old=Old->next;
       else
         return;
     }
     New->next=Old->next;
     free(Old);
     Old=L->next;
     New=L;
  }
}


int main (void)
{
  int val,k;
  char m;
  printf("a-add to begin\n"
         "r-delete\n"
         "p-print \n"
         "q-exit\n");
  while (m!= 'q')
  { 
    scanf("%c", &m);

   switch(m)
  {
    case 'a':
      printf("Input new data\n");
      scanf("%i", &val);
      AddToBegin(val);
    break;
    case 'p':
      printf("\n");
      DisplayList();
    break;
    case 'r':
      printf("Input value to delete\n");
      scanf("%i", &k);
      Delete(k);
    break;
    case 'q':
    break;
}
}
}
