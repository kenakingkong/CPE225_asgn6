/*
 * makena kong 
 * mkong02 
 * assignment 6 
 * subroutines
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

/*declare stack*/
int stack[10]; 
int top = -1;


/*push objects onto stack*/
int push(int value)
{
   if (top == 9) 
   {
      return 1;  
   }
   else
   {
      top++;
      stack[top] = value;
      return 0;
   } 
}


/*pop object off top of stack*/
int pop(int *value)
{
   if (top == -1)
   {
      return 1;  
   }
   else
   {
      *value = stack[top];
      top--;
      return 0;
   }    
}


void printStack(int type)
{
   int i,next, remainder;
   int x,y;
   char hex_num[100];

   printf("Stack: ");

   switch(type)
   {
      /*decimal*/
      case 0:
         for (i=0; i <= top; i++)
         {
            next = stack[i];
            if (next == 0)
               break;
            printf("%d ", next);
         }
         break;

      /*hex*/
      case 1: 
         for (i=0; i <= top; i++)
         {
            next = stack[i];
            x = 0;
            y = 0;

               while(next!=0)
               {
                  remainder = next % 16;
                  if (remainder < 10)
                  {
                     remainder = remainder + 48;
                     y++;
                  }
                  else
                  {
                     remainder = remainder + 87;
                     y++;
                  }
                  hex_num[x++] = remainder;
                  next = next / 16;
               }

               for (y = x-1; y>=0; y--)
                  printf("%c", hex_num[y]);
               printf(" ");
         }
         break;

      /*char*/
      case 2:
         for (i=0; i <= top; i++)
         {
            next = stack[i];
            if (next == 0)
               break;
            printf("%c ", next);
         }
         break;
   }     
   printf("\n");
}

