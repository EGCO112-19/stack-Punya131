#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv)
{
  printf("Checking the parentheses in argv arguments\n");
  int i,N,j/*,check=0*/;
  
  Stack s;
  s.size = 0;
  s.top = NULL;
  int x1 = 0;
  int x2 = 0;
  int x3 = 0;


 
  for(i=1;i<argc;i++){
   
     for(j=0;j<strlen(argv[i]);j++){
       /* Use stack to help with the parentheses*/
     switch(argv[i][j])
     {
      case '[' : push(&s,argv[i][j]);x1++;break; 
      case '{' : push(&s,argv[i][j]);x2++;break;
      case '(' : push(&s,argv[i][j]);x3++;break;
      case '}' : pop(&s);x2--;break;
      case ']' : pop(&s);x1--;break;
      case ')' : pop(&s);x3--;break;
      }   
    // if(check)break;
   //printf("%d\n",s.size);
     }
if(s.size>0 || x1 !=0 || x2 !=0 || x3 !=0)
     {
       printf("The parentheses do not match for %s \n",argv[i]);
      // printf("%d\n",s.size);
     }
     else
     {
       printf("The parentheses match successfully for %s \n",argv[i]);
       // printf("%d\n",s.size);
     } 
    // check = 0;
    x1 = 0;
     x2 = 0;
     x3 = 0;
     pop_all(&s);
  
  }
   return 0;
}
