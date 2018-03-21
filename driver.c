/*
 * makena kong 
 * mkong02 
 * assignment 6 
 * driver
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

int main(int argc, char *argv[])
{
 
   char input;
   int push_input;
   int pop_output;
   int result;
   int mode = 0;

   printf("Welcome to the stack program.\n");

   for (;;)
   {
      printf("\nEnter option: ");
      scanf(" %c", &input); 
 
      switch(input) 
      {
         case 'u':
         printf("What number? ");
         scanf("%d", &push_input);
         result = push(push_input);
         if (result == 1)
            printf("Overflow!!!\n");
         printStack(mode);
         break;

         case 'o':
         result = pop(&pop_output);
         if (result == 1)
            printf("Underflow!!!\n");
         else
            printf("Popped %d\n", pop_output);
         printStack(mode);
         break;

         case 'x':
         printf("Goodbye!\n");
         return(0);

         case 'd':
         printStack(0);
         mode = 0;
         break;

         case 'h':
         printStack(1);
         mode = 1;
         break;

         case 'c':
         printStack(2);
         mode = 2;
         break;

         default:
         printf("\n");
        
      }

   }
   return(0);
}
